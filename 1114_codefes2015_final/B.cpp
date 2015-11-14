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
  int N;
  cin >> N;
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  cout << floor(N * 3.5) << endl;
}
