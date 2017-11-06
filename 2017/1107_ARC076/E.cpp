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

typedef tuple<int, int> point; // score, num

int R, C, N;

bool onedge(int x, int y) {
  return (x == 0 || x == R-1 || y == 0 || y == C-1);
}

int score(int x, int y) {
  assert(onedge(x, y));
  if (y == 0) {
    return x;
  }
  if (x == R-1) {
    return R-1 + y;
  }
  if (y == C-1) {
    return R-1 + C-1 + (R-1 - x);
  }
  // x == 0
  return R-1 + C-1 + R-1 + (C-1 - y);
}

int main () {
  cin >> R >> C >> N;
  vector<point> V;
  for (auto i = 0; i < N; ++i) {
    int X0, Y0, X1, Y1;
    cin >> X0 >> Y0 >> X1 >> Y1;
    if (onedge(X0, Y0) && onedge(X1, Y1)) {
      V.push_back(point(score(X0, Y0), i));
      V.push_back(point(score(X1, Y1), i));      
    }
  }
  int visited[100010];
  fill(visited, visited+100010, 0);
  sort(V.begin(), V.end());
  stack<int> S;
  for (auto it = V.begin(); it != V.end(); ++it) {
    int num = get<1>(*it);
    if (visited[num] == 0) {
      visited[num]++;
      S.push(num);
    } else {
      assert(visited[num] == 1);
      int t = S.top();
      S.pop();
      if (num != t) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}

