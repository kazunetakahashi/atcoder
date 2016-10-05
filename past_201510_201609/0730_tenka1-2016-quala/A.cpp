#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <complex>

using namespace std;

int main() {
  int ans = 0;
  for (auto i = 1; i <= 100; i++) {
    if (!(i % 3 == 0 || i % 5 == 0)) {
      ans += i;
    }
  }
  cout << ans << endl;
}
