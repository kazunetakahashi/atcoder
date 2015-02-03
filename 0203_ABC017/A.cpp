#include <iostream>
using namespace std;

int main() {
  int s[3];
  int e[3];
  int ans = 0; 
  for (int i=0; i<3; i++) {
    cin >> s[i] >> e[i];
    ans += s[i] * e[i] / 10;
  }
  cout << ans << endl;
}
