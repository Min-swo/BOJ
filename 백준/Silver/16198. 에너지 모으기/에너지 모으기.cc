#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> weights;
vector<int> totals;


void init() {
  int weigths;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> weigths;
    weights.push_back(weigths);
  }
}

int gatherWeights(int idx) {
  int ret = weights[idx-1] * weights[idx+1];
  weights.erase(weights.begin()+idx);
  return ret;
}

void recursive(int idx, int sum) {
  int tmp = weights[idx];
  int ret = gatherWeights(idx);

  if(weights.size() <= 2) {
    totals.push_back(sum+ret);
    weights.insert(weights.begin() + idx, tmp);
    return;
  }

  for(int i = 1; i < weights.size() - 1; i++) {
    recursive(i, sum + ret);
  }
  weights.insert(weights.begin() + idx, tmp);
}

void solution() {
  for(int i = 1; i < weights.size() - 1; i++) {
    recursive(i, 0);
  }
}

int main(void) {
  init();
  
  // for(int i = 0; i < weights.size(); i++) {
  //   cout << weights[i] << "\n";
  // }

  solution();

  sort(totals.begin(), totals.begin() + totals.size());
  cout << totals[totals.size()-1];
  return 0;
}