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

int main() {
  int N, M;
  cin >> N >> M;
  shorui X[1000];
  for (auto i = 0; i < N; i++) {
    int V, T;
    cin >> V >> T;
    X[i] = make_pair(V, T);
  }
  sort(X, X+N);
  reverse(X, X+N);
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    if (M >= X[i].second) {
      M -= X[i].second;
      ans += X[i].first;
    }
  }
  cout << ans << endl;
}
