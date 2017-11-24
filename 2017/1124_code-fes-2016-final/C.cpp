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

const int C = 1e5+5;
// const ll M = 1000000007;

int N, M;
int K[100010];
vector<int> L[100010];

vector<int> V[200010];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; ++i) {
    cin >> K[i];
    for (auto j = 0; j < K[i]; ++j) {
      int l;
      cin >> l;
      L[i].push_back(l);
      V[i].push_back(l+C);
      V[l+C].push_back(i);
    }
  }
  bool visited[200010];
  fill(visited, visited+200010, false);
  stack<int> S;
  S.push(0);
  while (!S.empty()) {
    int src = S.top();
    S.pop();
    if (!visited[src]) {
      visited[src] = true;
      for (auto x : V[src]) {
        if (!visited[x]) {
          S.push(x);
        }
      }
    }
  }
  for (auto i = 0; i < N; ++i) {
    if (!visited[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
