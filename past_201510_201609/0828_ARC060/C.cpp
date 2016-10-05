#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <tuple>
#include <cmath>
#include <cassert>
#include <string>

using namespace std;

typedef long long ll;

int N, A;
int x[100010];

ll memo[60][60][2510];

ll f(int n, int m, int a) {
  if (memo[n][m][a] != -1) return memo[n][m][a];
  ll ans = -1;
  if (m == 0 && a == 0) {
    ans = 1;
  } else if (m == 0) {
    ans = 0;
  } else if (n < m) {
    ans = 0;
  } else if (a-x[n-1] < 0) {
    ans = f(n-1, m, a);
  } else {
    ans = f(n-1, m-1, a-x[n-1]) + f(n-1, m, a);
  }
  // cerr << "memo[" << n << "][" << m << "][" << a << "] = " << ans << endl;
  return memo[n][m][a] = ans;
}

int main() {
  cin >> N >> A;
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
  }
  fill(&memo[0][0][0], &memo[0][0][0]+60*60*2510, -1);
  ll ans = 0;
  for (auto i = 1; i <= N; i++) {
    ans += f(N, i, A*i);
  }
  cout << ans << endl;
}
