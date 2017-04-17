#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

typedef pair<int, int> shorui;

int main() {
  int N, K;
  cin >> N >> K;
  int H[100010];
  for (auto i = 0; i < N; i++) {
    cin >> H[i];
    if (H[i] == 0) H[i] = 1;
    else H[i] = 0;
  }
  int l = 0;
  int r = 0;
  int ans = 0;
  int cnt = 0;
  while (r < N) {
    while (cnt <= K && r < N) {
      //cerr << "r = " << r << ", l = " << l << endl;
      ans = max(ans, r-l);
      cnt += H[r];
      r++;
    }
    while (cnt > K && l <= r) {
      cnt -= H[l];
      l++;
    }
  }
  ans = max(ans, r-l);
  cout << ans << endl;
}
