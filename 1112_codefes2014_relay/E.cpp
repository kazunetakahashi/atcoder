#include <iostream>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  string b[110];
  for (auto i=0; i<h; i++) {
    cin >> b[i];
  }
  int ans = 0;
  for (auto i=0; i<h; i++) {
    for (auto j=0; j<w; j++) {
      if (b[i][j] != '.') {
        ans += b[i][j] - '0';
      }
    }
  }
  cout << ans << endl;
}
