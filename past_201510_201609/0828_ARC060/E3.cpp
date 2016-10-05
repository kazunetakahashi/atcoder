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

void init() {
  int l = 0;
  int r = 1;
  while (r < N) {
    if (x[r] - x[l] > L) {
      r--;
      memo[l][0] = r;
      //cerr << "memo[" << l << "][0] = " << memo[l][0] << endl;
      l++;
    } else {
      r++;
    }
  }
  while (l < N) {
    memo[l][0] = N-1;
    //cerr << "memo[" << l << "][0] = " << memo[l][0] << endl;
    l++;
  }
}

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

int minimum(int a, int b) {
  if (b <= a) return 0;
  int x = 1;
  while (g(a, x) < b) {
    x++;
  }
  x -= 1;
  return (1 << x) + minimum(g(a, x), b);
}

int main() {
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
  init();
  for (auto i = 0; i < Q; i++) {
    cout << minimum(a[i], b[i]) << endl;
  }
}
