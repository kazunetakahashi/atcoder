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
const ll M = 924844033;

ll ans[2010];

int main () {
  int N, K;
  cin >> N >> K;
  ans[0] = 1;
  for (auto n = 0; n <= N; n++) {
    ll R2 = max((n-K)-(1+K), 0);
    ll R1 = (n-K)-1 + (n-1) - (K+1) - 2 * R2;
    ll R0 = n - R2 - R1;
    if (1 <= n - K) {
      ans[n] = ((R1 * ans[n-1])%M + ((R0 + R2) * ans[n-2])%M)%M;
    } else {
      ans[n] = ((R0 * ans[n-1])%M + ((R1 + R2) * ans[n-2])%M)%M;
    }
  }
  cout << ans[N-1] << endl;
}
