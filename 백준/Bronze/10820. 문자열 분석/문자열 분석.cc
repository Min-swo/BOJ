#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    //공백: 32, 숫자: 48 ~ 57, 대문자: 65 ~ 90, 소문자: 97 ~ 122
   string line;
   int space, upper, lower, num;
   while(getline(cin, line))
   {
        space = 0; upper = 0; lower = 0; num = 0;
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == 32)
                space++;
            else if(47 < line[i] && line[i] < 58)
                num++;
            else if(64 < line[i] && line[i] < 91)
                upper++;
            else if(96 < line[i] && line[i] < 123)
                lower++;
        }
        cout << lower << " " << upper << " " 
        << num << " " << space << "\n";
   }

}