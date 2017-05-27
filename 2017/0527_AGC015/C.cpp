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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, M, Q;
string S[2010];
int x[200010][2];
int y[200010][2];
int grid[2010][2010];
int imos[4][2010][2010];

typedef tuple<int, int> point;

int main () {
  cin >> N >> M >> Q;
  for (auto i = 0; i < N; ++i) {
    cin >> S[i];
  }
  for (auto i = 0; i < Q; ++i) {
    cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
    x[i][0]--; y[i][0]--; x[i][1]--; y[i][1]--;
  }
  fill(&grid[0][0], &grid[0][0]+2010*2010, 0);
  fill(&imos[0][0][0], &imos[0][0][0]+4*2010*2010, 0);
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < M; ++j) {
      if (S[i][j] == 1 && grid[i][j] == 0) {
        queue<point> Q;
        Q.push(point(i, j));
        grid[i][j] = -1;
        while (!Q.empty()) {
          point now = Q.front();
          Q.pop();
          for (auto k = 0; k < 4; ++k) {
            int newx = get<0>(now) + dx[k];
            int newy = get<1>(now) + dy[k];
            if (grid[newx][newy] == 0 && S[newx][newy] == 1) {
              grid[newx][newy] = k+1;
              imos[k][newx][newy] = 1;
              Q.push(point(newx, newy));
            }
          }
        }
      }
    }
  }
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < M-1; ++j) {
      imos[0][i][j+1] += imos[0][i][j];
      imos[2][i][j+1] += imos[2][i][j];
    }
  }
  for (auto j = 0; j < M; ++j) {
    for (auto i = 0; i < N-1; ++i) {
      imos[1][i+1][j] += imos[1][i][j];
      imos[3][i+1][j] += imos[3][i][j];
    }
  }
  for (auto i = 0; i < Q; ++i) {
    int ans = 0;
    // 0
    int t = y[i][0]-1;
    if (t < 0) {
      ans += imos[0][x[i][0]][y[i][1]];
    } else {
      ans += imos[0][x[i][0]][y[i][1]] - imos[0][x[i][0]][t];
    }
    // 2
    t = y[i][0]-1;
    if (t < 0) {
      ans += imos[2][x[i][1]][y[i][1]];
    } else {
      ans += imos[2][x[i][1]][y[i][1]] - imos[0][x[i][1]][t];
    }
    // 1
    t = x[i][0]-1;
    if (t < 0) {
      ans += imos[1][x[i][1]][y[i][0]];
    } else {
      ans += imos[1][x[i][1]][y[i][0]] - imos[1][t][y[i][0]];
    }
    // 1
    t = x[i][0]-1;
    if (t < 0) {
      ans += imos[3][x[i][1]][y[i][1]];
    } else {
      ans += imos[3][x[i][1]][y[i][1]] - imos[3][t][y[i][1]];
    }
    cout << ans << endl;
  }
}
