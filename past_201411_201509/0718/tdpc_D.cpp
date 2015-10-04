#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int N;
long long D;
const int C = 65;
const double P = 1.0/6;
double dp[110][C][C][C];

int main() {
  cin >> N >> D;
  long long DD = D;
  int two=0, three=0, five=0;
  while (DD%2 == 0) {
    two++;
    DD /= 2;
  }
  while (DD%3 == 0) {
    three++;
    DD /= 3;
  }
  while (DD%5 == 0) {
    five++;
    DD /= 5;
  }
  if (DD != 1) {
    cout << 0 << endl;
    return 0;
  }
  fill(&dp[0][0][0][0], &dp[0][0][0][0]+110*C*C*C, 0);
  dp[0][0][0][0] = 1;
  for (auto n=0; n<N; n++) {
    for (auto i=0; i<C; i++) {
      for (auto j=0; j<C; j++) {
        for (auto k=0; k<C; k++) {
          dp[n+1][i][j][k] += P * dp[n][i][j][k];
          dp[n+1][min(i+1, C-1)][j][k] += P * dp[n][i][j][k];
          dp[n+1][i][min(j+1, C-1)][k] += P * dp[n][i][j][k];
          dp[n+1][min(i+2, C-1)][j][k] += P * dp[n][i][j][k];
          dp[n+1][i][j][min(k+1, C-1)] += P * dp[n][i][j][k];
          dp[n+1][min(i+1, C-1)][min(j+1, C-1)][k] += P * dp[n][i][j][k];
        }
      }
    }
  }
  double ans = 0;
  for (auto i=two; i<C; i++) {
    double anst = 0;
    for (auto j=three; j<C; j++) {
      double ansh = 0;
      for (auto k=five; k<C; k++) {
        ansh += dp[N][i][j][k];
      }
      anst += ansh;
    }
    ans += anst;
  }
  cout << fixed << setprecision(20) << ans << endl;
}
