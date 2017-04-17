#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>

using namespace std;
typedef long long ll;

int main() {
  int X, Y;
  cin >> X >> Y;
  if (X > Y) swap(X, Y);
  if (((X == 1) && (Y%2 == 1))
      || ((X == 2) && (Y%4 == 2))
      || ((X == 3) && (Y%4 == 0) && (Y >= 8))
      || ((X == 4) && (Y == 4))) {
    cout << "rng" << endl;
  } else {
    cout << "snuke" << endl;
  }
}
