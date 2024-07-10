#include <iostream>
#include <cmath>  
#include <fstream>
#include <string>

void circlefile(std::string pathC, std::string pathD)
{

    double xc{}, yc{}, r{}, xd, yd;

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


int main(int argc, char *arcv[])
{
    setlocale(LC_ALL, "Ru");
    std::string pathc = arcv[1];
    std::string pathd = arcv[2];


    circlefile(pathc, pathd);
     return 0;
}


