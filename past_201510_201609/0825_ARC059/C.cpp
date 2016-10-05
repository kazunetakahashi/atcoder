#include <iostream>
#include <cassert>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[110];
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  int ans = 1000000007;
  for (auto i = -100; i <= 100; i++) {
    int temp = 0;
    for (auto j = 0; j < N; j++) {
      int x = (a[j] - i);
      temp += x * x;
    }
    ans = min(ans, temp);
  }
  assert(ans < 1000000000);
  cout << ans << endl;
}
