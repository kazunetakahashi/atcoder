#include <iostream>
#include <string>
#include <set>
using namespace std;

int A[100010];
set<int> S[100010];

int main() {
  int N;
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  for (auto i = 0; i < N; i++) {
    S[A[i]].insert(i);
  }
  int now = 0;
  int ans = 0;
  for (auto i = 0; i < 100010; i++) {
    //cerr << "i = " << i << endl;
    if (S[i].empty()) {
      continue;
    } else if (S[i].lower_bound(now) == S[i].begin()) {
      auto x = S[i].end();
      x--;
      now = *x;
    } else {
      auto x = S[i].lower_bound(now);
      x--;
      now = *(x);
      ans++;
    }
    //cerr << "now = " << now << ", ans = " << ans << endl;
  }
  if (now == 0) {
    cout << ans << endl;
  } else {
    cout << ans+1 << endl;
  }
}
