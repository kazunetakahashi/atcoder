#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

struct man {
  int A;
  int B;
  bool operator<( const man& right ) const {
    return A < right.A;
  }
};

struct erigonomi {
  bool operator()( const man& left, const man& right ) {
    return left.B > right.B;
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
  int indx=0;
  int ans = 0;
  priority_queue<man, vector<man>, erigonomi> Q;
  for (auto i = 0; i < M; i++) {
    while (indx < N && X[indx].A >= Y[i].D) {
      Q.push(X[indx]);
      indx++;
    }
    while (!Q.empty()) {
      if (Q.top().B <= Y[i].C) {
        ans++;
        Q.pop();
        break;
      } else {
        Q.pop();
      }
    }
  }
  cout << ans << endl;
}
