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
            re += " " + std::to_string(k) ; /// Пробел в выводе поставлен для разделения двузначных чисел 
        }
        
    } while (k != 1);

    return re;
}

 
int main()
{
   setlocale(LC_ALL, "ru");
   int n, m;
   std::cin >> n >> m;
    
   std::cout << solve(m,n);

    return 0;
}


