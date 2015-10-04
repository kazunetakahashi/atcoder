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
typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  int a[100010];
  for (auto i=0; i<m; i++) {
    cin >> a[i];
  }
  queue<int> Q;
  int ans = 0;
  for (auto i=0; i<m; i++) {
    Q.push(a[i]);
    while (a[i] - Q.front() > n) {
      // cerr << "de " << Q.front() << endl;
      Q.pop();
    }
    ans = max(ans, (int)Q.size());
  }
  cout << ans << endl;
}
