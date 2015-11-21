#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int K, N;
string v[60];
string w[60];
int moji[9];

bool cleared = false;

bool solve() {
  map<int, string> M;
  for (auto i=0; i<N; i++) {
    int ind = 0;
    for (auto x : v[i]) {
      int m = moji[x-'1'];
      if (ind+m <= (int)w[i].size()) {
        string sub = w[i].substr(ind, m);
        if (M.find((int)(x-'1')) == M.end()) {
          M[(int)(x-'1')] = sub;
        } else {
          if (M[(int)(x-'1')] != sub) {
            return false;
          }
        }
        ind += m;
      } else {
        return false;
      }
    }
    if (ind < (int)(w[i].size())) {
      return false;
    }
  }
  if (!cleared) {
    for (auto i=0; i<K; i++) {
      cout << M[i] << endl;
    }
    cleared = true;
  }
  return true;
}

void dfs(int x) {
  if (x == K) {
    solve();
  } else {
    for (auto i=1; i<=3; i++) {
      moji[x] = i;
      dfs(x+1);
    }
  }
}

int main() {
  cin >> K >> N;
  for (auto i=0; i<N; i++) {
    cin >> v[i] >> w[i];
  }
  dfs(0);
}
