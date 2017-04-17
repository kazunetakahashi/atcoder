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

int A[100010];
int cnt[100010];

int main() {
  int N, M;
  cin >> N >> M;
  fill(cnt, cnt+100010, 0);
  for (auto i=0; i<N; i++) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  int max_c = 0;
  int ans = 0;
  for (auto i=0; i<=M; i++) {
    if (max_c < cnt[i]) {
      ans = i;
      max_c = cnt[i];
    }
  }
  if (max_c > N/2) {
    cout << ans << endl;
  } else {
    cout << "?" << endl;
  }
}
