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

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int H, W;
string S[100];

int valid(int x, int y) {
  if (0 <= x && x < H && 0 <= y && y < W && S[x][y] == '#') {
    return 1;
  } else {
    return 0;
  }
}

int main () {
  cin >> H >> W;
  for (auto i = 0; i < H; ++i) {
    cin >> S[i];
  }
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      if (S[i][j] == '.') {
        int cnt = 0;
        for (auto k = 0; k < 8; ++k) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          cnt += valid(nx, ny);
        }
        S[i][j] = (char)('0' + cnt);
      }
    }
  }
  for (auto i = 0; i < H; ++i) {
    cout << S[i] << endl;
  }
}
