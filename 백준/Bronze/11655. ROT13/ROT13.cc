#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string raw;
    getline(cin, raw);
    for(int i = 0; i < raw.length(); i++)
    {
        if(64 < raw[i] && raw[i] < 91)
        {
            if(raw[i] + 13 > 90)
                raw[i] = 64 + (raw[i] + 13) % 90;
            else
                raw[i] = raw[i] + 13;
        }
        else if(96 < raw[i] && raw[i] < 123)
        {
             if(raw[i] + 13 > 122)
                raw[i] = 96 + (raw[i] + 13) % 122;
            else
                raw[i] = raw[i] + 13;
        }
    }

    cout << raw << "\n";
}