#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int> sn;

int main() {
  int N, P;
  cin >> N >> P;
  if (N > 100) return 0; // 部分点
  sn S[5100];
  int a, b;
  for (auto i=0; i<N; i++) {
    cin >> a >> b;
    S[i] = make_tuple(a, b);
  }
  sort(S, S+N);
  reverse(S, S+N);
  int manzoku[110][700];
  fill(&manzoku[0][0], &manzoku[0][0]+110*700, -1);
  for (auto i=0; i<N; i++) {
    manzoku[i][0] = 0;
  }
  int ans = 0;
  for (auto i=0; i<N; i++) {
    a = get<0>(S[i]);
    b = get<1>(S[i]);
    for (auto j=0; j<=P; j++) {
      manzoku[i+1][j] = manzoku[i][j];
    }
    for (auto j=0; j<=P; j++) {
      if (manzoku[i][j] == -1) continue;
      if (j + a > P) {
        ans = max(ans, manzoku[i][j]+b);
        // cerr << "manzoku[" << i << "][" << j << "] + " << b << " over " << manzoku[i][j]+b << endl;
      } else {
        manzoku[i+1][j+a] = max(manzoku[i+1][j+a], manzoku[i][j]+b);
        // cerr << "manzoku[" << i+1 << "][" << j+a << "] = " << manzoku[i+1][j+a] << endl;
        ans = max(ans, manzoku[i+1][j+a]);
      }
    }
  }
  cout << ans << endl;
}
