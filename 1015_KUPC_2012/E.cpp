#include <iostream>
#include <algorithm>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 mt(rd());

int main() {
  int N;
  cin >> N;
  bool hands[20][20];
  int win[20];
  for (auto i=0; i<N; i++) {
    string S;
    cin >> S;
    win[i] = 0;
    for (auto j=0; j<N; j++) {
      hands[i][j] = (S[j] == 'o');
      if (hands[i][j]) win[i]++;
    }
  }
  int master = -1;
  for (auto i=0; i<N; i++) {
    if (win[i] == N-1) master = i;
  }
  int X;
  if (master >= 0) {
    for (auto i=0; i<1000; i++) {
      cout << master+1 << endl;
      cin >> X;
    }
  } else {
    for (auto i=0; i<1000; i++) {
      cout << mt()%N+1 << endl;
      cin >> X;
    }
  }
}
