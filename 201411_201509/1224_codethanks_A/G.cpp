#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
double P[210][210][110];

int main() {
  int N, K;
  cin >> N >> K;
  double X[110];
  for (auto i=1; i<=N; i++) {
    cin >> X[i];
    X[i] /= 100;
    cerr << X[i] << endl;
  }
  reverse(X+1, X+N+1);
  fill(&P[0][0][0], &P[0][0][0]+210*210*110, 0);
  P[0][K][N] = 1;
  for (auto k=N; k>0; k--) {
    for (auto i=K; i>=0; i--) {
      for (auto j=K; j>=0; j--) {
        if (P[i][j][k] == 0) continue;
        if (i >= 2) {
          P[i-1][j][k-1] += X[k] * P[i][j][k];
        } else if (i == 1 && j >= 1) {
          P[i][j-1][k-1] += X[k] * P[i][j][k];
        } else if (i == 1 && j == 0) {
          P[i-1][j][k-1] += X[k] * P[i][j][k];
        } else if (i == 0 && j >= 2){
          P[i+1][j-2][k-1] += X[k] * P[i][j][k];
        } else if (i == 0 && j == 1) {
          P[i][j-1][k-1] += X[k] * P[i][j][k];
        } else {
          P[i][j][k-1] += X[k] * P[i][j][k];
        }
        if (j >= 2) {
          P[i+1][j-2][k-1] += (1 - X[k]) * P[i][j][k];
        } else if (j == 1) {
          P[i][j-1][k-1] += (1 - X[k]) * P[i][j][k];          
        } else {
          P[i][j][k-1] += (1 - X[k]) * P[i][j][k];
        }
      }
    }
  }
  /* ここが一番遅かった。
  for (auto k=N; k>=0; k--) {
    cerr << "k=" << k << endl;
    for (auto i=K; i>=0; i--) {
      for (auto j=K; j>=0; j--) {
        cerr << "i=" << i << ", j=" << j << " ";
        cerr << P[i][j][k] << endl;
      }
    }
  }
  */
  double ans = 0;
  for (auto i=K; i>=0; i--) {
    for (auto j=K; j>=0; j--) {
      ans += P[i][j][0] * (i+j);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}
