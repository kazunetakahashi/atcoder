#include <iostream>
#include <string>
using namespace std;

int main() {
  string S[12];
  for (auto i=0; i<12; i++) {
    cin >> S[i];
  }
  int ans = 0;
  for (auto i=0; i<12; i++) {
    for (auto x : S[i]) {
      if (x == 'r') {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}
