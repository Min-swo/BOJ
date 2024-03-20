#include <iostream>
using namespace std;

int main(void)
{
    int pnt;
    cin >> pnt;
    
    if (pnt >= 90)
        cout << "A";
    else if (pnt >= 80)
        cout << "B";
    else if (pnt >= 70)
        cout << "C";
    else if (pnt >= 60)
        cout << "D";
    else
        cout << "F";
    
    
}