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

int N;
int x[100010];
int L, Q;
int a[100010];
int b[100010];

int memo[100010][18];

int g(int a, int r) {
  // cerr << "g(" << a << ", " << r << ") is called." << endl;
  if (memo[a][r] != -1) return memo[a][r];
  int ans = 0;
  if (a == N-1) {
    ans = N-1;
  } else if (r == 0) {
    int now = a;
    // cerr << "now = " << a << endl;
    // cerr << "x[" << a << "] = " << x[a] << endl;
    // cerr << "x[" << now+1 << "] = " << x[now+1] << endl;
    // cerr << "N = " << N << endl;
    // cerr << "L = " << L << endl;
    while (now+1 < N && x[now+1] - x[a] <= L) {
      // // cerr << "hello" << endl;
      now++;
    }
    ans = now;
  } else {
    ans = g(g(a, r-1), r-1);
  }
  // cerr << "memo[" << a << "][" << r << "] = " << ans << endl;
  return memo[a][r] = ans;
}

int h(int n) {
  int ans = 0;
  int m = n;
  while (m > 0) {
    m = (m >> 1);
    if (m == 0) break;
    ans++;
  }
  // assert(n - (1 << ans) >= 0);
  return ans;
}

int f(int a, int day) {
  // cerr << "f(" << a << ", " << day << ") is called." << endl;
  if (day == 0) return a;
  int s = h(day);
  /*
  if (day - (1 << s) < 0) {
    cerr << day << " " << s << endl;
  }
  */
  return f(g(a, s), day - (1 << s));
}

int mini(int a, int b) {
  int lb = 0;
  int ub = 100010;
  while (ub - lb > 1) {
    int t = (lb + ub)/2;
    int s = f(a, t);
    if (b <= s) {
      ub = t;
    } else {
      lb = t;
    }
  }
  return ub;
}

int main() {
  // init();
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
  }
  cin >> L >> Q;
  for (auto i = 0; i < Q; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    if (a[i] > b[i]) swap(a[i], b[i]);
  }
  // assert(N <= 1000 && Q <= 1000);
  fill(&memo[0][0], &memo[0][0]+100010*18, -1);
  for (auto i = 0; i < Q; i++) {
    cout << mini(a[i], b[i]) << endl;
  }
}
