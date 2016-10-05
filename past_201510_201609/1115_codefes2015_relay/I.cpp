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
typedef tuple<int, int, int> pass; // cost, x, y;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


int main() {
  int N;
  cin >> N;
  int k[210];
  int d[210];
  for (auto i=0; i<N; i++) {
    cin >> k[i] >> d[i];
  }
  int sumk=0, sumd=0;
  for (auto i=0; i<N; i++) {
    sumk += k[i];
    sumd += d[i];
  }
  if (sumk != sumd) {
    cout << "invalid" << endl;
    return 0;
  }
  int s[210];
  for (auto i=0; i<N; i++) {
    s[i] = k[i] + d[i];
  }
  bool dp[100010];
  fill(dp, dp+100010, false);
  dp[0] = true;
  for (auto i=0; i<N; i++) {
    for (auto j=sumk; j>=0; j--) {
      if (dp[j] && (j+s[i] <= sumk)) {
        dp[j+s[i]] = true;
        if (j+s[i] == sumk) {
          cout << "valid" << endl;
          return 0;
        }
      }
    }
  }
  cout << "invalid" << endl;
  return 0;
}
