#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;

int N;
const int C = (1 << 21);
double x[21], y[21];
double dist[21][21];
double memo[21][C];

const double infty = 1000000;

double sell(int now, int s) {
  if (memo[now][s] >= 0) return memo[now][s];
  if (s == (1 << (N+3))-1) {
    return memo[now][s] = ((now >= N) ? 0 : infty);
  }
  memo[now][s] = infty;
  for (auto i = 0; i < N+3; i++) {
    if (i == now) continue;
    memo[now][s] = min(memo[now][s],
                       dist[i][now] + sell(i, s|(1 << i)));
  }
  //cerr << "memo[" << now << "][" << s << "] = " << memo[now][s] << endl; 
  return memo[now][s];
}

int main() {
  cin >> N;
  for (auto i = 0; i < N+3; i++) {
    cin >> x[i] >> y[i];
  }
  for (auto i = 0; i < N+3; i++) {
    for (auto j = i+1; j < N+3; j++) {
      dist[i][j] = dist[j][i]
        = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
    }
  }
  for (auto i = 0; i < N+3; i++) {
    for (auto j = N; j < N+3; j++) {
      dist[i][j] = 0;
    }
  }
  fill(&memo[0][0], &memo[0][0]+21*C, -1);
  double ans = infty;
  for (auto i = 0; i < N+2; i++) {
    ans = min(sell(i, 0), ans);
  }
  cout << fixed << setprecision(10) << ans << endl;
}
