#include <iostream>
#include <algorithm>
using namespace std;

int M[60][60];
int num[5010];
int A[5010];
int B[5010];
int C[5010];
int D[5010];

const int infty = 1e9+10;

int main() {
  int N, Q;
  cin >> N >> Q;
  if (N > 50) return 0;
  fill(&M[0][0], &M[0][0]+60*60, 0);
  for (auto i = 0; i < Q; i++) {
    cin >> num[i];
    if (num[i] <= 2) {
      cin >> A[i] >> B[i] >> C[i];
    } else {
      cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
  }
  for (auto i = 0; i < Q; i++) {
    if (num[i] == 1) {
      for (auto j = 0; j < N; j++) {
        for (auto k = 0; k < N; k++) {
          if (A[i] <= j + k && j + k <= B[i]) {
            M[j][k] += C[i];
          }
        }
      }
    } else if (num[i] == 2) {
      for (auto j = 0; j < N; j++) {
        for (auto k = 0; k < N; k++) {
          if (A[i] <= j - k && j - k <= B[i]) {
            M[j][k] += C[i];
          }
        }
      }
    } else {
      int maxi = -1 * infty;
      for (auto j = A[i]; j <= B[i]; j++) {
        for (auto k = C[i]; k <= D[i]; k++) {
          maxi = max(maxi, M[j][k]);
        }
      }
      int cnt = 0;
      for (auto j = A[i]; j <= B[i]; j++) {
        for (auto k = C[i]; k <= D[i]; k++) {
          if (M[j][k] == maxi) {
            cnt++;
          }
        }
      }
      cout << maxi << " " << cnt << endl;
    }
  }
}
