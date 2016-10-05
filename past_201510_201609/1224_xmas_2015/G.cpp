#include <iostream>
using namespace std;
typedef long long ll;

int A[100010];

int main() {
  int N;
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  for (auto i = 0; i < N-1; i++) {
    ans += abs(A[i] - A[i+1]);
  }
  cout << ans << endl;
}
