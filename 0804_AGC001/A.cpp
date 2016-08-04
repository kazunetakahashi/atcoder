#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  int L[220];
  for (auto i = 0; i < 2*N; i++) {
    cin >> L[i];
  }
  sort(L, L+2*N);
  int ans = 0;
  for (auto i = 0; i < 2*N; i++) {
    if (i%2 == 0) ans += L[i];
  }
  cout << ans << endl;
}
