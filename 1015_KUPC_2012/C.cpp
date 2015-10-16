#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> b[60];
  for (auto i=0; i<K; i++) {
    int m;
    cin >> m;
    for (auto j=0; j<m; j++) {
      int t;
      cin >> t;
      t--;
      b[i].push_back(t);
    }
  }
  bool unf[60][60];
  fill(&unf[0][0], &unf[0][0]+60*60, false);
  int R;
  cin >> R;
  for (auto i=0; i<R; i++) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    unf[p][q] = unf[q][p] = true;
  }
  bool good[60];
  fill(good, good+60, true);
  for (auto i=0; i<K; i++) {
    for (unsigned j=0; j<b[i].size(); j++) {
      for (unsigned k=j+1; k<b[i].size(); k++) {
        if (unf[b[i][j]][b[i][k]]) {
          good[b[i][j]] = good[b[i][k]] = false; 
        }
      }
    }
  }
  int ans = 0;
  // cerr << "kibunwarui usagi : " << endl;
  for (auto i=0; i<N; i++) {
    if (!good[i]) {
      // cerr << i << endl;
      ans++;
    }
  }
  cout << ans << endl;
}
