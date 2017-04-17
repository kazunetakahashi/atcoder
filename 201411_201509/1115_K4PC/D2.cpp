#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> kukan; // B, A, F

const int C = 1e5+10;
vector<kukan> V;
int dp[C];

int main() {
  int N, K;
  cin >> N >> K;
  for (auto i=0; i<N; i++) {
    int b, a, f;
    cin >> a >> b >> f;
    V.push_back(make_tuple(b, a, f));
  }
  sort(V.begin(), V.end());
  int j = 0;
  int M = 0;
  for (auto i=1; i<C; i++) {
    dp[i] = max(0, dp[i-1]-K);
    while (get<0>(V[j]) == i) {
      dp[i] = max(dp[i], 
		  dp[get<1>(V[j])] + get<2>(V[j]) -K*(i-get<1>(V[j])));
      j++;
    }
    if (M < dp[i]) M = dp[i];
  }
  cout << M << endl;
}
