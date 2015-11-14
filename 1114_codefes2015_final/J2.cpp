#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>
#include <cassert>

using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  if (N%2 == 1) return 0;
  int S[100010];
  for (auto i=0; i<N; i++) {
    cin >> S[i];
    S[i] *= 2;
  }
  int Q;
  cin >> Q;
  int P[100010];
  int X[100010];
  for (auto i=0; i<Q; i++) {
    cin >> P[i] >> X[i];
  }
  ll ans = 0;
  ll W[100010];
  for (auto i=0; i<N; i++) {
    if (i%2 == 0) {
      W[i] = min(S[i], S[i+1]);
    }
  }
  for (auto i=0; i<N; i++) {
    if (i%2 == 1) {
      W[i] = min(S[i]-W[i-1], S[(i+1)%N]-W[(i+1)%N]);
    }
  }
  for (auto i=0; i<N; i++) {
    ans += W[i];
  }
  for (auto i=0; i<Q; i++) {
    int k = P[i]-1;
    S[k] = X[i]*2;
    for (auto i=-10; i<10; i++) {
      int l = (k+i+100*N)%N;
      //cerr << l << endl;
      if (l%2 == 0) {
        ans -= W[l];
        W[l] = min(S[l], S[l+1]);
        ans += W[l];
      }
    }
    for (auto i=-10; i<10; i++) {
      int l = (k+i+100*N)%N;
      if (l%2 == 1) {
        ans -= W[l];
        W[l] = min(S[l]-W[l-1], S[(l+1)%N]-W[(l+1)%N]);
        ans += W[l];
      }
    }
    cout << ans << endl;
  }
}
