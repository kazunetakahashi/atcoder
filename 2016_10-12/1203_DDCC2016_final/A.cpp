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

int R, C;

bool ok(int x, int y) {
  for (auto i = 0; i < 2; i++) {
    for (auto j = 0; j < 2; j++) {
      if (((x + i) * (x + i) + (y + j) * (y + j)) * C * C > R * R) {
        return false;
      }
    }
  }
  return true;
}

int main () {
  cin >> R >> C;
  int ans = 0;
  for (auto i = 0; i < 200; i++) {
    for (auto j = 0; j < 200; j++) {
      if (ok(i, j)) ans++;
    }
  }
  cout << ans * 4 << endl;
}
