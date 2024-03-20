#include <iostream>
#include <algorithm>
using namespace std;

class user_info{
	public:
		int age;
		string name;
		int order;
};

bool compare(user_info a, user_info b)
{
	if(a.age == b.age)
		return a.order < b.order;
	return a.age < b.age;
}

int main(void)
{
	int n;
	cin >> n;
	
	user_info* user_info_arr = new user_info[n];
	
	for(int i = 0; i < n; i++)
	{
		cin >> user_info_arr[i].age >> user_info_arr[i].name;
		user_info_arr[i].order = i;
	}
	
	sort(user_info_arr, user_info_arr + n, compare);
	
	for(int i = 0; i < n; i++)
		cout << user_info_arr[i].age << " " << user_info_arr[i].name << "\n";
}