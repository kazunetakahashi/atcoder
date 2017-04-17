#include <iostream>
#include <vector>
using namespace std;

long long X(long long a) {
  return a * (a - 1) / 2;
}

int main () {
  vector<int> V[100010];
  int N, C;
  cin >> N >> C;
  for (auto i=0; i<C; i++) {
    V[i].push_back(-1);
  }
  for (auto i=0; i<N; i++) {
    int a;
    cin >> a;
    a--;
    V[a].push_back(i);
  }
  for (auto i=0; i<C; i++) {
    V[i].push_back(N);
  }
  long long all = X(N+1);
  // cerr << "all = " << all << endl;
  for (auto i=0; i<C; i++) {
    long long notvalid = 0;
    for (auto j=1; j<V[i].size(); j++) {
      // cerr << V[i][j-1] << endl;
      notvalid += X(V[i][j] - V[i][j-1]);
    }
    cout << all - notvalid << endl;
  }
}
