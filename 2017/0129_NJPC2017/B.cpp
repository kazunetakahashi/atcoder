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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const ll M = 1000000007;

ll H, W, N;
int x[1010];
int y[1010];

bool is_tonari(int X1, int Y1, int X2, int Y2) {
  if (X1 == X2) {
    return (abs(Y1 - Y2) == 1);
  } else if (Y1 == Y2) {
    return (abs(X1 - X2) == 1);    
  } else {
    return false;
  }
}

ll number(int a, int b) {
  ll ans = 4;
  if (a == 1) {
    ans--;
  }
  if (a == H) {
    ans--;
  }
  if (b == 1) {
    ans--;
  }
  if (b == W) {
    ans--;
  }
  return ans;
}

int main () {
  cin >> H >> W >> N;
  for (auto i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }
  ll ans = (W-1) * H + (H-1) * W;
  for (auto i = 0; i < N; i++) {
    ans -= number(x[i], y[i]);
  }
  for (auto i = 0; i < N; i++) {
    for (auto j = i+1; j < N; j++) {
      if (is_tonari(x[i], y[i], x[j], y[j])) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
