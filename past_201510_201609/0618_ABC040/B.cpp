#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 1000000;
  for (auto i = 1; i <= n; i++) {
    int a = n/i;
    int b = n - a * i;
    ans = min(ans, abs(a-i) + b);
  }
  cout << ans << endl;
}
