#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int ans = 0;
  while (true) {
    if (B <= A * ans) break;
    ans++;
  }
  cout << ans << endl;
}
