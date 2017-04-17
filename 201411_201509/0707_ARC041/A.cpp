#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int k;
  cin >> k;
  if (y > k) {
    cout << x + k << endl;
  } else {
    cout << x - (k - y) + y << endl;
  }
}
