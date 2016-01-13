#include <iostream>
#include <algorithm>
using namespace std;

int used[100010];

int main() {
  int N;
  cin >> N;
  int A[100010];
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = 0;
  fill(used, used+100010, -1);
  int l=0, r=0;
  while (r < N) {
    if (used[A[r]] == -1) {
    } else {
      l = max(l, used[A[r]]+1);
    }
    used[A[r]] = r;
    //cerr << "r = " << r << ", l = " << l << endl;
    ans = max(ans, r-l+1);
    r++;
  }
  cout << ans << endl;
}
