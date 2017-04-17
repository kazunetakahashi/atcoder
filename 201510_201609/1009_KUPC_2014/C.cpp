#include <iostream>
#include <algorithm>
using namespace std;

const int C = 500;

int P[C];

int N, M, Q;

void init() {
  for (auto i=0; i<C; i++) {
    P[i] = i;
  }
}

int root(int x) {
  if (P[x] == x) return x;
  return P[x] = root(P[x]);
}

bool is_same_root(int x, int y) {
  return root(x) == root(y);
}

void unite(int x, int y) {
  P[root(x)] = root(y);
}

int gcd(int x, int y) {
  if (x < y) return gcd(y, x);
  if (y == 0) return x;
  return gcd(y, x%y);
}

int main() {
  init();
  cin >> N >> M >> Q;
  int c, d;
  for (auto i=0; i<Q; i++) {
    cin >> c >> d;
    c--; d--;
    unite(c, d+C/2);
  }
  int g = gcd(N, M);
  int n = N/g;
  int m = M/g;
  int max_ans = (n+m-1)*g;
  int ans = 0;
  while (true) {
    int t = ans;
    while (t < max_ans && is_same_root(t%N, t%M+C/2)) t++;
    if (t == max_ans) {
      break;
    } else {
      unite(ans%N, ans%M+C/2);
      ans++;
    }
  }
  cout << ans << endl;
}
