// 誤答
#include <iostream>
using namespace std;

int N;
int c[30010];

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> c[i];
  }
  int now = 0;
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    if (now < c[i]) {
      ans += c[i] - now - 1;
      now = c[i];
    }
  }
  cout << ans << endl;
}
