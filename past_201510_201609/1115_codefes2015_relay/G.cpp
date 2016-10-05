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

int A[10010];
int B[10010];
int C[10010];
int D[10010];
int sat[10010];

int main() {
  int N, M, L;
  cin >> N >> M >> L;
  for (auto i=0; i<N; i++) {
    cin >> A[i] >> B[i];
  }
  for (auto i=0; i<M; i++) {
    cin >> C[i] >> D[i];
  }
  fill(sat, sat+10010, -1);
  sat[0] = 0;
  for (auto i=0; i<M; i++) {
    for (auto j=L; j>=0; j--) {
      if (sat[j] >= 0 && j+C[i] <= L) {
        sat[j+C[i]] = max(sat[j+C[i]], sat[j]+D[i]);
      }
    }
  }
  for (auto i=0; i<L; i++) {
    sat[i+1] = max(sat[i+1], sat[i]);
  }
  int ans = 0;
  for (auto i=0; i<N; i++) {
    if (L-A[i] >= 0) {
      ans = max(ans, B[i] + sat[L-A[i]]);
    }
  }
  cout << ans << endl;
}
