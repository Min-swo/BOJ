#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 10

pair<int, int>prior[26];
int val[26];

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 26; i++)
        prior[i] = make_pair(i, 0);

    int n;
    cin >> n;
    
    string word[n];
    for(int i = 0; i < n; i++)
        cin >> word[i];
    
    int tmp;
    for(int i = 0; i < n; i++)
    {
        tmp = word[i].length();
        for(int j = 0; j < tmp; j++)
        {
            // cout << "WORD: " << word[i][j] << " NUM: " << (word[i][j]-65) << "\n";
            prior[word[i][j] - 65].second = 
                prior[word[i][j] - 65].second + pow(10, (tmp-j-1));
        }
    }

    sort(prior, prior+26, compare);

    int k = 9;
    for(int i = 0; i < 10; i++)
        val[prior[i].first] = k--;
    
    // for(int i = 0; i < 10; i++)
    //     cout << val[i] << " ";
    // cout << "\n";

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        tmp = word[i].length();
        for(int j = 0; j < tmp; j++)
        {
            sum = sum + val[word[i][j] - 65] * pow(10, tmp-j-1);
        }
    }

    cout << sum << "\n";
    return 0;
}