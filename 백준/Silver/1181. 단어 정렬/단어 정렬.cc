#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool compare(string a, string b)
{
	if(a.length() == b.length())
	{
		return a < b;
	}
	
	return a.length() < b.length();
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	
	string* str_word_arr = new string[n];
	for(int i = 0; i < n; i++)
		getline(cin, str_word_arr[i]);
	
	sort(str_word_arr, str_word_arr + n, compare);
	
	for(int i = 0; i < n - 1; i++)
	{
		if(str_word_arr[i] == str_word_arr[i + 1])
			str_word_arr[i] = "";
	}
	
	for(int i = 0; i < n; i++)
	{
		if(str_word_arr[i] != "")
			cout << str_word_arr[i] << "\n";
	}
}