#include <iostream>
using namespace std;

int main(void)
{
    int hr, min, t;
    cin >> hr >> min >> t;
    
    int time;
    time = hr * 60 + min + t;
    int h, m;
    h = time / 60;
    m = time % 60;
    
    h = h % 24;
    
    cout << h << " " << m;
    
}