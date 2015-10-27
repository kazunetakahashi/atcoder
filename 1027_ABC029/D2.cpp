#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N > 10000) return 0;
  int ans = 0;
  for (auto i=0; i<=N; i++) {
    string S = to_string(i);
    for (auto x : S) {
      if (x == '1') ans++;
    }
  }
  cout << ans << endl;
}
