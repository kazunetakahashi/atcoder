#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int x, y, X, Y;
  cin >> x >> y >> X >> Y;
  cout << abs(x - X) + abs(y - Y) + 1 << endl;
}
