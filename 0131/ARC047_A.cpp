#include <iostream>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  string S;
  cin >> S;
  int tab = 1;
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    if (S[i] == '+') {
      tab++;
      if (tab > L) {
        ans++;
        tab = 1;
      }
    } else {
      tab--;
    }
  }
  cout << ans << endl;
}
