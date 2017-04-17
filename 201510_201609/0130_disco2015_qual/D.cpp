#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  ll A[60];
  ll sumA = 0;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
    sumA += A[i];
  }
  ll B[60];
  ll sumB = 0;
  for (auto i = 0; i < M; i++) {
    cin >> B[i];
    sumB += B[i];
  }
  ll ans = 0;
  if (K != 1) return 0;
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < M; j++) {
      ll tempA = sumA;
      ll tempB = sumB;
      tempA -= A[i];
      tempA += B[j];
      tempB -= B[j];
      tempB += A[i];
      ans = max(ans, tempA * tempB);
    }
  }
  cout << ans << endl;
}
