#include <iostream>
#include <queue>
using namespace std;

int a[100010];

int main() {
  int n, m;
  cin >> n >> m;
  for (auto i=0; i<m; i++) {
    cin >> a[i];
  }
  queue<int> Q;
  int ans = 0;
  for (auto i=0; i<m; i++) {
    while (!Q.empty() && Q.front() < a[i]-n) {
      Q.pop();
    }
    Q.push(a[i]);
    ans = max(ans, (int)Q.size());
  }
  cout << ans << endl;
}
