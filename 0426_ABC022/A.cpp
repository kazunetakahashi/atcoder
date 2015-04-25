#include <iostream>
using namespace std;

int main() {
  int N, S, T;
  cin >> N >> S >> T;
  int W = 0;
  int ans = 0;
  for (auto i=0; i<N; i++) {
    int A;
    cin >> A;
    W += A;
    if (S <= W && W <= T) ans++;
  }
  cout << ans << endl;
}
