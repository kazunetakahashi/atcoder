#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int> sn;

int main() {
  int N, P;
  cin >> N >> P;
  sn S[5100];
  int a, b;
  for (auto i=0; i<N; i++) {
    cin >> a >> b;
    S[i] = make_tuple(a, b);
  }
  sort(S, S+N);
  reverse(S, S+N);
  int manzoku[5010];
  fill(manzoku, manzoku+5010, -1);
  manzoku[0] = 0;
  int ans = 0;
  for (auto i=0; i<N; i++) {
    a = get<0>(S[i]);
    b = get<1>(S[i]);
    for (auto j=P; j>=0; j--) {
      if (manzoku[j] == -1) continue;
      if (j + a > P) {
        ans = max(ans, manzoku[j]+b);
        // cerr << "manzoku[" << i << "][" << j << "] + " << b << " over " << manzoku[j]+b << endl;
      } else {
        manzoku[j+a] = max(manzoku[j+a], manzoku[j]+b);
        // cerr << "manzoku[" << i+1 << "][" << j+a << "] = " << manzoku[j+a] << endl;
        ans = max(ans, manzoku[j+a]);
      }
    }
  }
  cout << ans << endl;
}
