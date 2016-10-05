#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
  int N;
  cin >> N;
  int a[100010];
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll ans[100010];
  fill(ans, ans+100010, 1);
  for (auto i = 1; i < N; i++) {
    if (a[i] > a[i-1]) {
      ans[i] = ans[i-1] + 1;
    }
    cerr << "ans[" << i << "] = " << ans[i] << endl;
  }
  ll ret = 0;
  for (auto i = 0; i < N; i++) {
    ret += ans[i];
  }
  cout << ret << endl;
}
