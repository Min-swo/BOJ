#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int tmp;
	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	
	vector<int> sorted_v = v;
	sort(sorted_v.begin(), sorted_v.end());
	sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());
	
	// for(int i = 0; i < n; i++)
	// 	cout << sorted_v[i] << " ";
	// cout << "\n";
	
	// for(int i = 0; i < n; i++)
	// 	cout << v[i] << " ";
	// cout << "\n";
	
	map<int, int> index_map;
	for(int i = 0; i < n; i++)
		index_map.insert(make_pair(sorted_v[i], i));
	
	for(int i = 0; i < n; i++)
		cout << index_map[v[i]] << " "; 
	cout << "\n";
}