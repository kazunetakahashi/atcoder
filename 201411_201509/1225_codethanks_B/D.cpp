#include <iostream>
#include <algorithm>
using namespace std;

int S[1010];

int main() {
  int N, T;
  cin >> N >> T;
  int A[1010];
  fill(S, S+T+1, 0);
  for (auto i=0; i<N; i++) {
    cin >> A[i];
    for (auto j=1; A[i]*j <= T; j++) {
      S[A[i]*j]++;
    }
  }
  int ans = 0;
  for (auto i=0; i<=T; i++) {
    if (S[i] > ans) ans = S[i];
  }
  cout << ans << endl;
}
