#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long ll;

ll A[100010];

int main() {
  int N;
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++) {
    ll pair = A[i]/2;
    ans += pair;
    A[i] -= pair * 2;
    if (i < N-1) {
      ll cnt = min(A[i], A[i+1]);
      ans += cnt;
      A[i] -= cnt;
      A[i+1] -= cnt;
    }
  }
  cout << ans << endl;
}
