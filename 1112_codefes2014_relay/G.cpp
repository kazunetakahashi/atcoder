#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool sound[60][20010];

int main() {
  int n, m;
  cin >> n >> m;
  int a[60];
  for (auto i=0; i<n; i++) {
    cin >> a[i];
  }
  fill(&sound[0][0], &sound[0][0]+60*20010, false);
  sound[0][0] = true;
  for (auto i=1; i<=n; i++) {
    for (auto j=0; j<=20010; j++) {
      if (sound[i-1][j]) {
        sound[i][j] = true;
        if (j+a[i-1] < 20010) {
          sound[i][j+a[i-1]] = true;
        }
      }
    }
  }
  for (auto j=m; j<20010; j++) {
    if (sound[n][j]) {
      cout << j << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
