#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <tuple>
#include <cmath>
#include <cassert>
#include <string>

using namespace std;

typedef long long ll;

int f(int b, int n) {
  if (n < b) return n;
  return f(b, n/b) + n%b;
}

vector<int> V[100010];

int main() {
  int n;
  cin >> n;
  for (auto i = 2; i < n; i++) {
    cout << "f(" << i << ", " << n << ") = " << f(i, n) << endl;
    V[f(i, n)].push_back(i);
  }
  for (auto i = 1; i < n/2+10; i++) {
    cout << "V[" << i << "] : ";
    for (auto x : V[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
}
