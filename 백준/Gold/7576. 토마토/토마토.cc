#include <iostream>
#include <vector>
using namespace std;

int m, n;
int** box;
vector<vector<int>> tomato;
vector<vector<int>> fresh;

int IsOk(int x, int y)
{
	if((0 <= x && x < n) && (0 <= y && y < m))
	{
		if(box[x][y] == 0)
		{
			return 1;
		}
	}
	return 0;
}

void InsertFresh(int x, int y)
{
	vector<int> loc;
	loc.push_back(x);
	loc.push_back(y);
	fresh.push_back(loc);
}

void Side(int x, int y)
{
	if(IsOk(x, y))
	{
		box[x][y] = 1;
		InsertFresh(x, y);
	}
}

void Spread(vector<int> loc)
{
	int k = 0;
	Side(loc[0]+1, loc[1]);
	Side(loc[0], loc[1]+1);
	Side(loc[0]-1, loc[1]);
	Side(loc[0], loc[1]-1);
}

int Check()
{
	if(fresh.size())
		return 0;
	return 1;
}

void Update()
{
	int size;
	size = tomato.size();
	for(int i = size-1; i >= 0; i--)
	{
		tomato[i].clear();
		tomato.pop_back();
	}

	for(int i = 0; i < fresh.size(); i++)
			tomato.push_back(fresh[i]);
	
	size = fresh.size();
	for(int i = size-1; i >= 0; i--)
	{
		fresh[i].clear();
		fresh.pop_back();
	}

}

int main(void)
{
	cin >> m >> n;
	
	box = new int*[n];
	for(int i = 0; i < n; i++)
		box[i] = new int[m];
	
	vector<int> loc;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			loc.clear();
			cin >> box[i][j];
			if(box[i][j] == 1)
			{
				loc.push_back(i);
				loc.push_back(j);
				tomato.push_back(loc);
			}
		}
	}
	
	int day = 0;
	while(1)
	{
		for(int i = 0; i < tomato.size(); i++)
		{
			Spread(tomato[i]);
		}
		if(Check())
			break;
		day++;
		
		// cout << "Day " << day << "\n";
		// for(int i = 0; i < n; i++)
		// {
		// 	for(int j = 0; j < m; j++)
		// 		cout << box[i][j] << " ";
		// 	cout << "\n";
		// }
		// cout << "\n";
		
		// cout << "tomato: \n";
		// for(int i = 0; i < tomato.size(); i++)
		// 	cout << "( " << tomato[i][0] << ", " << tomato[i][1] << " )\n";
		// cout << "\n";
		
		// cout << "fresh: \n";
		// for(int i = 0; i < fresh.size(); i++)
		// 	cout << "( " << fresh[i][0] << ", " << fresh[i][1] << " )\n";
		// cout << "\n";
		
		Update();
	}
	
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(box[i][j] == 0)
				ans = 0;
		}
	}
	
	if(ans)
		cout << day;
	else
		cout << -1;
	cout << "\n";
	
	// for(int i = 0; i < cnt; i++)
	// {
	// 	cout << "(" << tomato[i].at(0) << ", " << tomato[i].at(1) << ")\n";
	// }
	
	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < m; j++)
	// 		cout << box[i][j] << " ";
	// 	cout << "\n";
	// }
	
	return 0;
}