#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N;
int c[30010];
int dp[30010];
int high[30010];

// 間違い
typedef pair<int, int> num;

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> c[i];
  }
  fill(dp, dp+30010, 1);
  // fill(high, high+30010, -1);
  stack<num> S;
  for (auto i = 0; i < N; i++) {
    while(!S.empty()) {
      int x = S.top().first;
      int ind = S.top().second;
      if (c[i] < x) {
        high[i] = ind;
        S.push(make_pair(c[i], i));
        break;
      } else {
        S.pop();
      }
    }
    if (S.empty()) {
      high[i] = -1;
    }
  }
  for (auto i = 1; i < N; i++) {
    int ind = i-1;
    while (ind >= 0) {
      if (c[ind] < c[i]) {
        dp[i] = max(dp[i], dp[ind]+1);
        ind = high[ind];
      } else {
        break;
      }
    }
  }
  int maxi = 0;
  for (auto i = 0; i < N; i++) {
    maxi = max(maxi, dp[i]);
  }
  cout << N - maxi << endl;
}
