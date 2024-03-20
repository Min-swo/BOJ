#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    
    int* price = new int[n];
    for(int i = 0; i < n; i++)
        cin >> price[i];

    int* maxPrice = new int[n];
    for(int i = 0; i < n; i++)
        maxPrice[i] = 0;
    maxPrice[0] = price[0];

    int max = -1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(max < maxPrice[j] + price[i-j-1])
                max = maxPrice[j] + price[i-j-1];
        }
        if(max < price[i])
            max = price[i];
        maxPrice[i] = max;
    }

    cout << maxPrice[n-1] << "\n";
    
}