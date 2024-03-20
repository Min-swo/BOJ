#include <iostream>
using namespace std;

#define MAX 10001
int main(void)
{
    int n;
    cin >> n;

    int* price = new int[n];
    for(int i = 0; i < n; i++)
        cin >> price[i];

    int* minPrice = new int[n];
    minPrice[0] = price[0];
    int min;
    for(int i = 1; i < n; i++)
    {
        min = MAX;
        for(int j = 0; j < i; j++)
        {
            if(min > minPrice[j] + price[i-j-1])
                min = minPrice[j] + price[i-j-1];
        }
        if(min > price[i])
            min = price[i];
        minPrice[i] = min;
    }
    cout << minPrice[n-1] << "\n";
}