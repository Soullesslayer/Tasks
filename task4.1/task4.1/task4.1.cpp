#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int countpath = 0;


std::vector<int> arrfromfile(std::string pathF) 
{

    std::ifstream fin(pathF);
    int g;
    std::vector<int> arr;
    if (!fin.is_open()) {
        std::cout << "File input.txt not found!"<< std::endl;
        exit(0);
    }
    else {
        while (fin >> g) {
            arr.push_back(g);
        }
    } 

    fin.close();

    return arr;
}

double findMedian(std::vector<int> a,int n)
{
    if (n % 2 == 0) {

        std::nth_element(a.begin(),
            a.begin() + n / 2,
            a.end());

        std::nth_element(a.begin(),
            a.begin() + (n - 1) / 2,
            a.end());

        return round((double)(a[(n - 1) / 2]
            + a[n / 2])
            / 2.0);
    }

    
    else {

        nth_element(a.begin(),
            a.begin() + n / 2,
            a.end());

        return round((double)a[n / 2]);
    }
}

int minpath(double median, std::vector<int> arr)
{

    for (int i = 0; i < arr.size(); i++) 
    {
        if (arr[i] == median) { continue; }
        else if (arr[i] < median) { countpath += median - arr[i]; }
        else if (arr[i] > median){ countpath += arr[i] - median; }
    
    }

    return countpath;
} 



int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    if (argc != 2) {
        std::cout << "Expected 2 args" << std::endl;
        exit(1);
    }

    std::string pathF = argv[1];

    std::vector<int> array = arrfromfile(pathF);

    int median = findMedian(array, array.size());

    std::cout << minpath(median, array) << std::endl;

    
    return 0;
}


