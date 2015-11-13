#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string B[110];
  for (auto i=0; i<n; i++) {
    cin >> B[i];
  }
  int x=0, y=0;
  for (auto i=0; i<n; i++) {
    for (auto j=0; j<n; j++) {
      if (B[j][i] == '.') x++;
      else break;
    }
  }
  for (auto i=0; i<n; i++) {
    for (auto j=n-1; j>=0; j--) {
      if (B[j][i] == '.') y++;
      else break;
    }
  }
  if (x > y) {
    cout << "X" << endl;
  } else if (x < y) {
    cout << "Y" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}
