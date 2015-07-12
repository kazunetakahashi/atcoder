#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> buka[30];
ll X[30];

ll cal(int x) {
  if (X[x] != 0) {
    return X[x];
  }
  if (buka[x].empty()) {
    X[x] = 1;
    return X[x];
  } else {
    ll tmax = cal(buka[x][0]);
    ll tmin = cal(buka[x][0]);
    for (unsigned i=0; i<buka[x].size(); i++) {
      tmax = max(tmax, cal(buka[x][i]));
      tmin = min(tmin, cal(buka[x][i]));
    }
    X[x] = tmax + tmin + 1;
    return X[x];
  }
}

int main() {
  fill(X, X+30, 0);
  int N;
  cin >> N;
  for (auto i=1; i<N; i++) {
    int b;
    cin >> b;
    b--;
    buka[b].push_back(i);
  }
  cout << cal(0) << endl;
}
