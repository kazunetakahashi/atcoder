#include <iostream>
using namespace std;

int n, m;
int a[1010];
int b[1010];
int v[1010][1010];
int dp[1010][1010];

int calc(int x, int y, bool turn) {
  if (v[x][y]) {
    return dp[x][y];
  }
  int ans = (turn ? -10000000 : 10000000);
  if (x < n && turn) {
    ans = max(calc(x+1, y, !turn)+a[x], ans);
  }
  if (x < n && !turn) {
    ans = min(calc(x+1, y, !turn)-a[x], ans);
  }
  if (y < m && turn) {
    ans = max(calc(x, y+1, !turn)+b[y], ans);
  }
  if (y < m && !turn) {
    ans = min(calc(x, y+1, !turn)-b[y], ans);
  }
  v[x][y] = true;
  // cerr << "dp[" << x << "][" << y << "] = " << ans << endl;
  return dp[x][y] = ans;
}

int main() {
  cin >> n >> m;
  int wa = 0;
  for (auto i=0; i<n; i++) {
    cin >> a[i];
    wa += a[i];
  }
  for (auto i=0; i<m; i++) {
    cin >> b[i];
    wa += b[i];
  }
  fill(&v[0][0], &v[0][0]+1010*1010, false);
  dp[n][m] = 0;
  v[n][m] = true;
  int sa = calc(0, 0, true);
  cout << (sa+wa)/2 << endl;
}
