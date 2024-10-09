#include <iostream>
#include <stack>
using namespace std;

string input;
stack<char> PPAP;
int state = 0;

void popPPAP() {
  for(int j = 0; j < 4; j++) {
    PPAP.pop();
  }
}

void setState(char input) {
  if(input == 'P') {
    if(PPAP.empty()) {
      state = 1;
    } 
    else if(PPAP.top() == 'P') {
      state = 2;
    } 
    else if(PPAP.top() == 'A') {
      if(state == 3) {
        state = 4;
      }
      else {
        state = 1;
      }
    }
  }
  else if(input == 'A') {
    if(PPAP.empty()) {
      state = 0;
    } 
    else if(PPAP.top() == 'P') {
      if(state == 2) {
        state = 3;
      }
      else {
        state = 0;
      }
    } 
    else if(PPAP.top() == 'A') {
      state = 0;
    }
  }
}

int main(void) {
  cin >> input;
  for(int i = 0; i < input.length(); i++) {
    setState(input[i]);
    PPAP.push(input[i]);

    if(state == 4) {
      popPPAP();
      setState('P');
      PPAP.push('P');
    }
  }

  // cout << PPAP.top() << " " << PPAP.size() << "\n";
  if(PPAP.top() == 'P' && PPAP.size() == 1) 
    cout << "PPAP" << "\n";
  else 
    cout << "NP" << "\n";
  
}