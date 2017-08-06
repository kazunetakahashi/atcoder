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

int H, W;
int N;
int a[100010];
int c[110][110];

bool valid(int x, int y) {
  return (0 <= x && x < H && 0 <= y && y < W && c[x][y] == -1);
}

int main () {
  cin >> H >> W;
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }
  int d = 0;
  int color = 0;
  int x = 0, y = 0;
  fill(&c[0][0], &c[0][0]+110*110, -1);
  while (color < N) {
    // cerr << x << " " << y << " " << d << endl;
    /*
    for (auto i = 0; i < H; ++i) {
      for (auto j = 0; j < W; ++j) {
        cerr << c[i][j];
        if (j < W-1) {
          cerr << " ";
        } else {
          cerr << endl;
        }
      }
    }
    */
    if (valid(x, y)) {
      c[x][y] = color + 1;
      a[color]--;
      if (a[color] == 0) color++;
    } else if (valid(x + dx[d], y + dy[d])) {
      x += dx[d];
      y += dy[d];
    } else {
      d++;
      d %= 4;
    }
  }
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      cout << c[i][j];
      if (j < W-1) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  }
}
