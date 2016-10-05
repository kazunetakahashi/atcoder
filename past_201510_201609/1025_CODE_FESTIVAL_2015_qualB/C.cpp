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
int B[100010];
int cnt[100010];

int main() {
  int N, M;
  cin >> N >> M;
  for (auto i=0; i<N; i++) {
    cin >> A[i];
  }
  for (auto i=0; i<M; i++) {
    cin >> B[i];
  }
  sort(A, A+N);
  sort(B, B+M);
  int inda = 0;
  int indb = 0;
  while (inda < N && indb < M) {
    if (B[indb] <= A[inda]) {
      inda++;
      indb++;
    } else {
      inda++;
    }
  }
  cout << ((indb == M) ? "YES" : "NO") << endl;
}
