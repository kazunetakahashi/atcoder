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
  int ans = 0;
  int W[100010];
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
    if (k%2 == 0) {
      ans -= W[k];
      W[k] = min(S[k], S[(k+1)%N]);
      ans += W[k];
      ans -= W[(k+N-1)%N];
      W[(k+N-1)%N] = min(S[(k+N-1)%N]-W[(k+N-2)%N], S[k]-W[k]);
      ans += W[(k+N-1)%N];
      ans -= W[(k+N+1)%N];
      W[(k+N+1)%N] = min(S[(k+N+1)%N]-W[(k+N)%N], S[(k+N+2)%N]-W[(k+N+2)%N]);
      ans += W[(k+N+1)%N];
      cout << ans << endl;
    } else {
      ans -= W[k-1];
      W[k-1] = min(S[k], S[(k-1+N)%N]);
      ans += W[k-1];
      ans -= W[(k+N-2)%N];
      W[(k+N-2)%N] = min(S[(k+N-2)%N]-W[(k+N-3)%N], S[(k+N-1)%N]-W[(k+N-1)%N]);
      ans += W[(k+N-2)%N];
      ans -= W[(k+N)%N];
      W[(k+N)%N] = min(S[(k+N)%N]-W[(k+N-1)%N], S[(k+N+1)%N]-W[(k+N+1)%N]);
      ans += W[(k+N)%N];
      cout << ans << endl;
    }
    /*
    for (auto i=0; i<N; i++) {
      cerr << W[i] << " ";
    }
    cerr << endl;
    */
  }
}
