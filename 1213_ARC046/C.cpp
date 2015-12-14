#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
 
struct man {
  int A;
  int B;
  bool operator<( const man& right ) const {
    return A < right.A;
  }
};
 
struct woman {
  int C;
  int D;
  bool operator<( const woman& right ) const {
    return D < right.D;
  }
};
 
man X[150010];
woman Y[150010];
 
int main() { // 部分点
  int N, M;
  cin >> N >> M;
  for (auto i = 0; i < N; i++) {
    cin >> X[i].A >> X[i].B;
  }
  for (auto i = 0; i < M; i++) {
    cin >> Y[i].C >> Y[i].D;
  }
  sort(X, X+N);
  reverse(X, X+N);
  sort(Y, Y+M);
  reverse(Y, Y+M);
  int indx=0, indy=0;
  int ans = 0;
  while (indx < N && indy < M) {
    if (X[indx].A >= Y[indy].D) {
      ans++;
      indx++;
      indy++;
    } else {
      indy++;
    }
  }
  cout << ans << endl;
}
