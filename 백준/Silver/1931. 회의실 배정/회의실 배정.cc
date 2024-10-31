#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int s, e;
int cnt = 0;
int tmp = 0;
vector<pair<int, int>> cof;

bool compare(pair<int, int> a, pair<int, int> b) {
  if(a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int main(void) {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> s >> e;
    cof.push_back({s, e});
  }

  sort(cof.begin(), cof.end(), compare);

  for(int i = 0; i < N; i++) {
    if(tmp <= cof[i].first) {
      cnt++;
      tmp = cof[i].second;
    }
  }

  cout << cnt << "\n";
  return 0;
}