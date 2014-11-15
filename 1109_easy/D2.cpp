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
#include <set> // if (S.find(key) != S.end()) { }
// for (auto i=S.begin(); i != S.end(); i++) { }
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  const int C = 100010;
  int x[C];
  int y[C];
  pair<int, int> z[C];
  int a[C];
  for (auto i=0; i<n; i++) {
    cin >> x[i] >> y[i];
    z[i] = make_pair(x[i], y[i]);
  }
  for (auto i=0; i<m; i++) {
    cin >> a[i];
  }
  sort(z, z+n);
  sort(a, a+m);
  int ans = 0;
  int j = 0;
  priority_queue<int> Q;
  for (auto i=0; i<m; i++) {
    while (j < n && z[j].first <= a[i]) {
      // cerr << "pushed j = " << j << endl;
      Q.push(-1 * z[j++].second);
    }
    while (!Q.empty() && -1 * Q.top() < a[i]) {
      // cerr << "pop " << -1 * Q.top() << endl;
      Q.pop();
    }
    if (!Q.empty()) {
      // cerr << i << " is given to " << -1 * Q.top() << endl;
      ans++;
      Q.pop();
    }
  }
  cout << ans << endl;
}
