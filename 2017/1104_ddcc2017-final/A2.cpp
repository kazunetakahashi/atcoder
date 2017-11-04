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

bool inter(int x, int y, int center, int hankei) {
  int a = x - center;
  int b = y - center;
  return (a * a + b * b <= hankei * hankei);
}

bool ok(int x, int y, int center, int hankei) {
  return inter(x, y, center, hankei)
    && inter(x + K, y, center, hankei)
    && inter(x, y + K, center, hankei)
    && inter(x + K, y + K, center, hankei);
}

int solve(int A) {
  int center = A/2;
  int grid = A/K;
  int ans = 0;
  for (auto i = 0; i < grid; ++i) {
    for (auto j = 0; j < grid; ++j) {
      if (ok(i * K, j * K, center, center)) {
        ans++;
      }
    }
  }
  return ans;
}

int main () {
  cin >> K;
  cout << solve(200) << " " << solve(300) << endl;
}
