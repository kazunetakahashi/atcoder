#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

typedef pair<int, int> shorui;

int DP[510][510];

int main() {
  int N, M;
  cin >> N >> M;
  int V[500];
  int T[500];
  for (auto i = 0; i < N; i++) {
    cin >> V[i] >> T[i];
  }
  for (auto j = 0; j <= M; j++) {
    DP[0][j] = 0; 
  }
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j <= M; j++) {
      if (j-T[i] >= 0) {
        DP[i+1][j] = max(DP[i][j-T[i]] + V[i], DP[i][j]);
      } else {
        DP[i+1][j] = DP[i][j];
      }
    }
  }
  cout << DP[N][M] << endl;
}
