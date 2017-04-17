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

int N;
int x[100010];
int L, Q;
int a[100010];
int b[100010];

int mini(int a, int b) {
  int ans = 0;
  int now = a;
  int t = x[a];
  while (true) {
    if (now == b) {
      ans++;
      break;
    } else if (x[now+1] - t > L) {
      t = x[now];
      ans++;
    } else {
    }
    now++;
  }
  return ans;
}

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
  }
  cin >> L >> Q;
  for (auto i = 0; i < Q; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    if (a[i] > b[i]) swap(a[i], b[i]);
  }
  assert(N <= 1000 && Q <= 1000);
  for (auto i = 0; i < Q; i++) {
    cout << mini(a[i], b[i]) << endl;
  }

}
