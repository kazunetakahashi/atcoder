#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int K;

typedef tuple<int, int> state;

int main () {
  cin >> K;
  priority_queue<state, vector<state>, greater<state> > Q;
  Q.push(state(1, 1));
  int visited[100010];
  fill(visited, visited+100010, -1);
  while (!Q.empty()) {
    int cost = get<0>(Q.top());
    int now = get<1>(Q.top());
    Q.pop();
    if (visited[now] == -1) {
      visited[now] = cost;
      if (now == 0) {
        cout << cost << endl;
        return 0;
      }
      int plusone = (now + 1)%K;
      if (visited[plusone] == -1) {
        Q.push(state(cost+1, plusone));
      }
      int timesten = (now * 10)%K;
      if (visited[timesten] == -1) {
        Q.push(state(cost, timesten));
      }
    }
  }
}
