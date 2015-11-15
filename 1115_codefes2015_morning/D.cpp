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

using namespace std;
typedef long long ll;

int main() {
  int N;
  ll K;
  cin >> N >> K;
  ll A[100010];
  for (auto i=0; i<N; i++) {
    cin >> A[i];
  }
  ll ub=1000000000000010;
  ll lb=0;
  while (ub-lb > 1) {
    ll t = (ub+lb)/2;
    ll sakujo =0;
    for (auto i=0; i<N; i++) {
      if (A[i] > t) {
        sakujo += A[i] - t;
      }
    }
    if (sakujo <= K) {
      ub = t;
    } else {
      lb = t;
    }
  }
  cerr << "ub = " << ub << endl;
  ll amari = K;
  for (auto i=0; i<N; i++) {
    if (A[i]-ub >= 1) {
      amari -= A[i] - ub;
      A[i] = ub;
    } else {
      //
    }
  }
  for (auto i=0; i<N; i++) {
    cerr << A[i] << " ";
  }
  cerr << endl;
  ll M = 1000000000000010;
  ll ind = 0;
  for (auto i=0; i<N; i++) {
    if (M > A[i]) {
      M = A[i];
      ind = i;
    }
  }
  cerr << "M = " << M << endl;
  ll x = 0;
  cerr << "amari = " << amari << endl;
  while (amari > 0 && ind+x < N) {
    ll y = min(amari, A[ind+x] - M);
    amari -= y;
    A[ind+x] -= y;
    x++;
  }
  x = 0;
  while (amari > 0 && ind+x >= 0) {
    ll y = min(amari, A[ind+x] - M);
    amari -= y;
    A[ind+x] -= y;
    x--;
  }
  ll ans = A[0] + A[N-1];
  for (auto i=0; i<N-1; i++) {
    ans += abs(A[i] - A[i+1]);
  }
  for (auto i=0; i<N; i++) {
    cerr << A[i] << " ";
    ans += 2 * A[i];
  }
  cerr << endl;
  ans += N;
  cout << ans << endl;
}
