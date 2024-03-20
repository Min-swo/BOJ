#include <iostream>
#include <vector>
#include <string>
using namespace std;

double grade(string grd)
{
	vector<double> v = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0};
	vector<string> grade = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
	for(int i = 0; i < v.size(); i++)
	{
		if(grade[i].compare(grd) == 0)
			return v[i];
	}
	return -1;
}


int main(void)
{
	string str;
	double crd;
	string grd;
	double dgrd;
	double sCrd = 0;
	double sum = 0;
	for(int i = 0; i < 20; i++)
	{
		cin >> str >> crd >> grd;
		dgrd = grade(grd);
		if(dgrd == -1)
			continue;
		sCrd += crd;
		sum = sum + crd * dgrd;
		//cout << "\n" <<  sCrd << " " << sum << "\n";
	}
	
	cout << sum / sCrd << "\n";
}