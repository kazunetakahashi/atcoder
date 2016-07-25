#include <iostream>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
using namespace std;

set<char> D;

int main() {
  int N, K;
  cin >> N >> K;
  int d;
  for (auto i = 0; i < K; i++) {
    cin >> d;
    D.insert(d + '0');
  }
  int ans = N;
  while (true) {
    string S = to_string(ans);
    for (auto x : S) {
      //cerr << x << endl;
      if (D.find(x) != D.end()) {
        goto EXIT;
      }
    }
    cout << ans << endl;
    return 0;
  EXIT:
    ans++;
  }
}
