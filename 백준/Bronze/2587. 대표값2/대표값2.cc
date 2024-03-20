#include <iostream>
#include <algorithm>
using namespace std;
#define N 5

int main(void)
{
	int* arr = new int[N];
	
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	
	int sum = 0;
	for(int i = 0; i < N; i++)
		sum += arr[i];
	
	int avg = sum / N;
	
	sort(arr, arr + N);
	
	cout << avg << "\n" << arr[N / 2] << "\n"; 
}