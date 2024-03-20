#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(void)
{
	int n;
	cin >> n;
	
	pair<int, int>* xy_pair_array = new pair<int, int>[n];
	for(int i = 0; i < n; i++)
		cin >> xy_pair_array[i].first >> xy_pair_array[i].second;
	
	sort(xy_pair_array, xy_pair_array + n, compare);
	
	for(int i = 0; i < n; i++)
		cout << xy_pair_array[i].first << " " << xy_pair_array[i].second << "\n";
}