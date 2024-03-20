#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
    int a, b, m;
    cin >> a >> b >> m;

    int* digits = new int[m];
    for(int i = m-1; i >= 0; i--)
        cin >> digits[i];

    int k = 0;
    for(int i = 0; i < m; i++)
        k = k + digits[i] * pow(a, i);

    int tmp;
    vector<int> v;
    while(k != 0)
    {
        tmp = k % b;
        v.push_back(tmp);
        k = k / b;
    }
    
    for(int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
    cout << "\n";
}