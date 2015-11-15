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

ll sq(ll n) {
  return n * (n+1) / 2;
}

int main() {
  int N;
  cin >> N;
  ll A[100010];
  for (auto i=0; i<N; i++) {
    cin >> A[i];
  }
  ll sum[100010];
  sum[0] = 0;
  for (auto i=0; i<N; i++) {
    sum[i+1] = sum[i] + A[i];
  }
  ll ans = 0;
  for (auto i=0; i<N; i++) {
    ans += i * A[i];
  }
  ll M = ans + sq(N-2);
  cerr << ans << endl;
  for (auto i=1; i<N; i++) {
    ans += sum[i];
    ans -= sum[N] - sum[i];
    if (i%2 == 0) {
      cerr << ans << endl;
      M = min(M, ans + sq(i-1) + sq(N-i-2));
    }
  }
  cout << M << endl;
}
