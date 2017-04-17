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

set<point> S;
ll H, W;
int N;
ll ans[10];
int a[100010], b[100010];

void calc(int x, int y) {
  if (!(0 <= x && x+2 < H && 0 <= y && y+2 < W)) {
    return;
  }
  int cnt = 0;
  for (auto i = x; i < x+3; i++) {
    for (auto j = y; j < y+3; j++) {
      if (S.find(make_pair(i, j)) == S.end()) {
        
      } else {
        cnt++;
      }
    }
  }
  if (cnt != 0) {
    // cerr << "x = " << x << ", y = " << y << ", cnt = " << cnt << endl;
    ans[cnt]++;
  }
}

int main () {
  cin >> H >> W >> N;
  for (auto i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    S.insert(make_pair(a[i], b[i]));
  }
  fill(ans, ans+10, 0);
  for (auto i = 0; i < N; i++) {
    for (auto j = a[i]-2; j <= a[i]; j++) {
      for (auto k = b[i]-2; k <= b[i]; k++) {
        calc(j, k);
      }
    }
  }
  ll sum = (H-2) * (W-2);
  for (auto i = 1; i < 10; i++) {
    sum -= ans[i]/i;
  }
  cout << sum << endl;
  for (auto i = 1; i < 10; i++) {
    cout << ans[i]/i << endl;
  }
  
}
