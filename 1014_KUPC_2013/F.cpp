#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;

typedef tuple<int, int> lr;
typedef long long ll;

int n, s;
lr T[510];
int memo[510];
int W[510][510];
const int infty = (1 << 30);

int calc(int i) {
  if (memo[i] >= 0) return memo[i];
  int ans = 0;
  for (auto j=0; j<=n; j++) {
    if (i == j) continue;
    int temp = get<1>(T[j]) - max(get<1>(T[i])+W[i][j], get<0>(T[j]));
    if (temp > 0) {
      ans = max(ans, temp + calc(j));
    }
  }
  return memo[i] = ans;
}

int main() {
  cin >> n >> s;
  s--;
  int l, r;
  for (auto i=0; i<n; i++) {
    cin >> l >> r;
    T[i] = make_tuple(l, r);
  }
  for (auto i=0; i<n; i++) {
    for (auto j=0; j<n; j++) {
      cin >> W[i][j];
    }
  }
  for (auto i=0; i<=n; i++) {
    W[i][n] = infty;
  }
  for (auto i=0; i<=n; i++) {
    W[n][i] = W[s][i];
  }
  for (auto k=0; k<=n; k++) {
    for (auto i=0; i<=n; i++) {
      for (auto j=0; j<=n; j++) {
        W[i][j] = min(W[i][j], W[i][k]+W[k][j]);
      }
    }
  }
  fill(memo, memo+n+1, -1);
  cout << calc(n) << endl;
}

