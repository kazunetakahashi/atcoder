#include <iostream>
using namespace std;
typedef long long ll;

const int C = 1010;
const int C2 = C*2;
const int M = 1000000007;

int p[C];
int l[C2];
ll DP[C][C2]; // poyo_number, relative_position
ll DPsum[C][C2]; // DPsum[i][j] = \sum_{k=0}^{j} DP[i][k]

int main() {
  int n;
  cin >> n;
  for (auto i=0; i<n; i++) {
    cin >> p[i] >> l[i];
    p[i] += C;
  }
  fill(&DP[0][0], &DP[0][0]+C*C2, 0);
  for (auto i=-1*l[0]; i<=l[0]; i++) {
    DP[0][i+C] = 1;
  }
  DPsum[0][0] = DP[0][0];
  for (auto i=1; i<C2; i++) {
    DPsum[0][i] = DPsum[0][i-1] + DP[0][i];
  }
  for (auto i=1; i<n; i++) {
    for (auto j = -1 * l[i]; j <= l[i]; j++) {
      DP[i][j+C] = DPsum[i-1][min(l[i-1],p[i]+j-p[i-1]-1)+C];
    }
    DPsum[i][0] = DP[i][0];
    for (auto j=1; j<C2; j++) {
      DPsum[i][j] = DPsum[i][j-1] + DP[i][j];
      DPsum[i][j] %= M;
    }
  }
  cout << DPsum[n-1][C2-1] << endl;
}
