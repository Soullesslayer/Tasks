////////Для работы требуется библеотека nlohmann, которая находится в папке проекта "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <json.hpp>

using json = nlohmann::json;
using namespace std;

struct Test {
	int id;
	string title;
	string value;
	vector<Test> values;

	Test(const json& j) {
		id = j.at("id").get<int>();
		title = j.at("title").get<string>();
		if (j.contains("value")) {
			value = j.at("value").get<string>();
		}
		if (j.contains("values")) {
			for (const auto& sub_test : j.at("values")) {
				values.emplace_back(sub_test);
			}
		}
	}

	json to_json() const {
		json j;
		j["id"] = id;
		j["title"] = title;
		j["value"] = value;
		if (!values.empty()) {
			for (const auto& sub_test : values) {
				j["values"].push_back(sub_test.to_json());
			}
		}
		return j;
	}
};

void fill_values(Test& test, const unordered_map<int, string>& values_map) {
	if (values_map.find(test.id) != values_map.end()) {
		test.value = values_map.at(test.id);
	}
	for (auto& sub_test : test.values) {
		fill_values(sub_test, values_map);
	}
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		cerr <<"Usage: "<< argv[0]<< " <values.json> <tests.json> <report.json>"<< endl;
		return 1;
	}

	ifstream values_file(argv[1]);
	ifstream tests_file(argv[2]);
	ofstream report_file(argv[3]);

	if (!values_file.is_open() || !tests_file.is_open() || !report_file.is_open()) {
		std::cout << "Error opening files!" <<endl;
		return 1;
	}

	json values_json, tests_json;
	values_file>> values_json;
	tests_file>> tests_json;

	unordered_map<int, string> values_map;
	for (const auto& item : values_json["values"]) {
		int id = item.at("id").get<int>();
		string value = item.at("value").get<string>();
		values_map[id] = value;
	}

	vector<Test> tests;
	for (const auto& test_json : tests_json["tests"]) {
		tests.emplace_back(test_json);
	}

	for (auto& test : tests) {
		fill_values(test, values_map);
	}

	json report_json;
	for (const auto& test : tests) {
		report_json["tests"].push_back(test.to_json());
	}

	report_file<< report_json.dump(1);

	return 0;
}