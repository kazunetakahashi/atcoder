#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;

int D[100010];
int S[100010];
ll X[5][100010];
ll Y[4][100010];

const int M = 1000000007;

int main() {
  int N;
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> D[i];
  }
  sort(D, D+N);
  int indi=0, indj=0;
  while (indi < N && indj < N) {
    if (D[indi]*2 <= D[indj]) {
      S[indi] = indj;
      indi++;
    } else {
      indj++;
    }
  }
  assert(indj == N);
  while (indi < N) {
    S[indi] = N;
    indi++;
  }
  for (auto i=0; i<N; i++) {
    X[0][i] = 1;
  }
  for (auto t=0; t<=3; t++) {
    Y[t][N] = 0;
    for (auto i=N-1; i>=0; i--) {
      Y[t][i] = (Y[t][i+1] + X[t][i])%M;
    }
    for (auto i=N-1; i>=0; i--) {
      X[t+1][i] = Y[t][S[i]];
    }
  }
  cout << Y[3][0] << endl;
}
