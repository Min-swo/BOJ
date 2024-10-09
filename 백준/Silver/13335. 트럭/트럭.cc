#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> waitingQueue;
vector<pair<int, int>> bridgeVector;

int N, W, L;

int main(void) {
  cin >> N >> W >> L;
  for(int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    waitingQueue.push(tmp);
  }

  int time = 0;
  int weigth = 0;
  while(!waitingQueue.empty()) {
    time += 1;
    
    if(!bridgeVector.empty()) {
      for(int i = 0; i < int(bridgeVector.size()); i++) {
        bridgeVector[i].second += 1;
      }
      if(bridgeVector.front().second > W) {
        weigth -= bridgeVector.front().first;
        bridgeVector.erase(bridgeVector.begin());
      }
    }
    
    int truck = waitingQueue.front();
    if(int(bridgeVector.size()) + 1 <= W && weigth + truck <= L) {
      waitingQueue.pop();
      weigth += truck;
      bridgeVector.push_back({truck, 1});
    }

    // cout << "================================\n";
    // cout << "Time: " << time << "\ntotal count: " << int(bridgeVector.size()) << "\n";
    // for(int i = 0; i < int(bridgeVector.size()); i++) {
    //   cout << "Number: " << i << ", Weight: " << bridgeVector[i].first << ", Pos: " << bridgeVector[i].second << "\n";
    // }
    // cout << "================================\n";
  }

  if(!bridgeVector.empty()) {
    time += W - bridgeVector.back().second + 1;
  }

  cout << time << "\n";
}