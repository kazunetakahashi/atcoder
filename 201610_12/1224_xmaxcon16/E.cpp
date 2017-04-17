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

int A[30][50];
int ans[50];

void solve() {
  for (auto i = 0; i < 30; i++) {
    for (auto j = 0; j < 50; j++) {
      cin >> A[i][j];
    }
  }
  for (auto j = 0; j < 50; j++) {
    int cnt[4];
    fill(cnt, cnt+4, 0);
    for (auto i = 0; i < 30; i++) {
      cnt[A[i][j]]++;
    }
    int maxi = 0;
    int ind = 0;
    for (auto i = 0; i < 4; i++) {
      if (maxi < cnt[i]) {
        maxi = cnt[i];
        ind = i;
      }
    }
    ans[j] = ind;
  }
  for (auto i = 0; i < 50; i++) {
    cout << ans[i];
    if (i < 49) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}

int main () {
  for (auto i = 0; i < 200; i++) {
    solve();
  }
}
