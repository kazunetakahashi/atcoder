#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, B, C;
  cin >> N >> B >> C;
  int A[110];
  for (auto i=0; i<N; i++) {
    cin >> A[i];
  }
  reverse(A, A+N);
  int x[110];
  for (auto i=0; i<N; i++) {
    x[i] = max(0, min(B, C));
    C -= x[i];
  }
  int ans = 0;
  for (auto i=0; i<N; i++) {
    ans += A[i] * x[i];
  }
  cout << ans << endl;
}
