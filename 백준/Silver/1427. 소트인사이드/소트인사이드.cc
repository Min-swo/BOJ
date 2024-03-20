#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
using namespace std;

int main(void)
{
	string str;
	getline(cin, str);
	int size = str.size();
	
	int* arr = new int[size];
	for(int i = 0; i < size; i++)
		arr[i] = str[i] - '0';
	
	sort(arr, arr+size, greater<>());
	
	for(int i = 0; i < size; i++)
		cout << arr[i];
	cout << "\n";
	
}