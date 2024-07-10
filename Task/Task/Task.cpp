#include <iostream>
#include <string>

std::string solve(int m, int n)
{
    std::string re;

    re = "1";

    if (m == n)
    {
        return re;
    }
    int k = 1;
    do 
    {
        k = k + m - 1;
        if (k > n)
        {
            if (k % n == 0) 
            {
                k = n;
            }
            else k = k % n;
            
        }
       
        if (k!= 1)
        {
            re  += std::to_string(k) ;
        }
        
    } while (k != 1);

    return re;
}

 
int main(int argc, char* argv[])
{
   setlocale(LC_ALL, "ru");
   
   if (argc != 3) {
       std::cerr << "Program is of the form: " << argv[0] << " <inp1> <inp2>\n";
       return 1;
   }
   std::string arg1 = argv[1];
   std::string arg2 = argv[2];
  
    
  std::cout << solve(std::stoi(arg2), std::stoi(arg1));

    return 0;
}


