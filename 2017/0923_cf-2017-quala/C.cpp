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

int H, W;
string a[110];
int cnt[26];
int amari = 0;
int yoyu = 0;

int main () {
  cin >> H >> W;
  for (auto i = 0; i < H; ++i) {
    cin >> a[i];
  }
  fill(cnt, cnt+26, 0);
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      cnt[a[i][j] - 'a']++;
    }
  }
  for (auto i = 0; i < 26; ++i) {
    amari += cnt[i]%4;
  }
  if (H%2 != 0 && W%2 != 0) {
    yoyu = H + W - 1;
  } else if (H%2 == 0 && W%2 != 0) {
    yoyu = H;
  } else if (H%2 != 0 && W%2 == 0) {
    yoyu = W;
  } else {
    yoyu = 0;
  }
  if (amari <= yoyu) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
