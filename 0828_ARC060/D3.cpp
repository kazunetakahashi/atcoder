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

ll f(ll b, ll n) {
  if (n < b) return n;
  return f(b, n/b) + n%b;
}

vector<int> V[100010];

int main() {
  ll n, s;
  cin >> n >> s;
  if (s == n) {
    cout << n+1 << endl;
    return 0;
  }
  ll sq = sqrt(n);
  // cerr << sq << endl;
  for (auto i = 2; i < sq+10; i++) {
    if (f(i, n) == s) {
      cout << i << endl;
      return 0;
    }
  }
  ll ans = 1000000000000;    
  for (ll p = 1; p < sq+10; p++) {
    ll q = s - p;
    ll b = (n - q)/p;
    if (0 <= q && q < b && p < b && f(b, n) == s) {
      ans = min(b, ans);
    }
  }
  if (ans == 1000000000000) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

// V[138] : 100 118 133 144 154 157 188 199 205 287 664 749 859 885 1123 1288 1327 1684 1717 1990 2245 2432 2575 2653 3367 3979 4863 5149 6733 7294 7957 9725 14587 21880 29173 43759 87517 
