#include <iostream>
#include <algorithm>
using namespace std;

void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void quick_sort(int* arr, int left, int right)
{
	int pivot = left;
	int i = left + 1;
	int j = right;
	if(left >= right)
		return;
	
	while(i <= j)
	{
		while(i <= right && arr[i] >= arr[pivot])
			i++;
		while(j > left && arr[j] <= arr[pivot])
			j--;
				
		if(i > j)
			swap(arr, pivot, j);
		
		else
			swap(arr, i, j);	
	}
	
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	
	int* arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	quick_sort(arr, 0, n-1);
	
	cout << arr[k-1] << "\n";
}