#include <iostream>
#include <cmath>  
#include <fstream>
#include <string>

void circlefile()
{
    std::string pathC, pathD;

    double xc{}, yc{}, r{}, xd, yd;

    std::cout << "Введите путь до файла с окружностью" << std::endl;
    std::cin >> pathC; 
    std::ifstream file(pathC);

      if (file.is_open())
      {
        file >> xc >> yc >> r;
        file.close();
      } 
      else 
      { 
          std::cout << "Файл не найден"; return; 
      }
    std::cout << "Введите путь до файла с точками" << std::endl;

    std::cin >> pathD; 
    std::ifstream dots(pathD);

    if (dots.is_open())
    {
        while (dots >> xd >> yd)
        {
            double d = pow(pow((xc - xd), 2) + pow((yc - yd), 2), 0.5);
            if (d > r) 
            {
                std::cout << "2" << std::endl;
            }
            else if (d == r) 
            {
                std::cout << "0" << std::endl;
            }
            else 
            {
                std::cout << "1" << std::endl;
            }
        }
    }
    else { std::cout << "Файл не найден"; return;}
    

}




int main()
{
    setlocale(LC_ALL, "Ru");

    circlefile();
     return 0;
}


