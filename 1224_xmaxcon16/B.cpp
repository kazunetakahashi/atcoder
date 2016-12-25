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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

typedef pair<int, int> point;

map<point, vector<point> > M;

int main () {
  for (auto i = 0; i < 3; i++) {
    for (auto j = 0; j < (1 << i); j++) {
      point r = make_pair(i, j);
      point a = make_pair(i+1, 2*j);
      point b = make_pair(i+1, 2*j+1);
      M[r].push_back(a);
      M[r].push_back(b);
      M[a].push_back(r);
      M[b].push_back(r);
    }
  }
  map<point, int> visited;
  stack<point> S;
  S.push(make_pair(0, 0));
  while (!S.empty()) {
    point from = S.top();
    S.pop();
    if (visited.find(from) == visited.end()) {
      visited[from] = 1;
      for (auto to : M[from]) {
        if (visited.find(from) == visited.end() ||
            visited[from] == 1) {
          S.push(to);
        }
      }
    } else if (visited[from] == 1) {
      visited[from]++;
      cout << from.first << " " << from.second << endl;
    }
  }
}
