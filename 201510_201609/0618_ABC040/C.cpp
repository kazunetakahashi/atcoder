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

long long a[100010];
long long ans[100010];

int main() {
  int N;
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  ans[0] = 0;
  ans[1] = abs(a[0] - a[1]);
  for (auto i = 2; i < N; i++) {
    ans[i] = min(ans[i-1] + abs(a[i]-a[i-1]),
                 ans[i-2] + abs(a[i]-a[i-2]));
  }
  cout << ans[N-1] << endl;
}
