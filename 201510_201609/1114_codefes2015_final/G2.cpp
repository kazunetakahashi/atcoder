#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
int C[300];
ll DP_tree[300][300];
ll DP_forest[300][300];

const ll M = 1000000007;

ll forest(int i, int j);

ll tree(int i, int j) {
  if (DP_tree[i][j] != -1) {
    return DP_tree[i][j];
  }
  if (i > j) {
    return DP_tree[i][j] = 0;
  } else if (i == j) {
    return DP_tree[i][j] = 1;
  } else {
    DP_tree[i][j] = forest(i+1, j);
    // cerr << "tree(" << i << ", " << j << ") = " << DP_tree[i][j] << endl;
    return DP_tree[i][j];
  }
}

ll forest(int i, int j) {
  if (DP_forest[i][j] != -1) {
    return DP_forest[i][j];
  }
  if (i > j) {
    return DP_forest[i][j] = 0;
  } else {
    ll ans = tree(i, j);
    for (auto k=i; k+1<=j; k++) {
      if (C[i] < C[k+1]) {
        ans += (tree(i, k) * forest(k+1, j))%M;
        ans %= M;
      }
    }
    DP_forest[i][j] = ans;
    // cerr << "forest(" << i << ", " << j << ") = " << DP_forest[i][j] << endl;
    return DP_forest[i][j];
  }
}

int main() {
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> C[i];
  }
  if (C[0] != 1) {
    cout << 0 << endl;
    return 0;
  }
  fill(&DP_tree[0][0], &DP_tree[0][0]+300*300, -1);
  fill(&DP_forest[0][0], &DP_forest[0][0]+300*300, -1);
  cout << tree(0, N-1) << endl;
}
