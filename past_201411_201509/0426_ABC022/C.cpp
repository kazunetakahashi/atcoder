#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector< tuple<int, int> > V[310];
  for (auto i=0; i<M; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    u--; v--;
    V[u].push_back(make_tuple(v, l));
    V[v].push_back(make_tuple(u, l));
  }
  const int infty = 100100100;
  int WF[310][310];
  fill(&WF[0][0], &WF[0][0]+310*310, infty);
  for (auto i=0; i<N; i++) {
    WF[i][i] = 0;
  }
  for (auto i=1; i<N; i++) {
    // cerr << "i = " << i << endl;
    for (unsigned int j=0; j<V[i].size(); j++) {
      int v = get<0>(V[i][j]);
      int cost = get<1>(V[i][j]);
      // cerr << "v = " << v << ", cost = " << cost << endl;
      WF[i][v] = min(WF[i][v], cost);
    }
  }
  /*
  for (auto i=0; i<N; i++) {
    for (auto j=0; j<N; j++) {
      cerr << WF[i][j] << ", ";
    }
    cerr << endl;
  }
  */
  for (auto k=0; k<N; k++) {
    for (auto i=0; i<N; i++) {
      for (auto j=0; j<N; j++) {
        WF[i][j] = min(WF[i][j], WF[i][k] + WF[k][j]);
      }
    }
  }
  for (unsigned int j=0; j<V[0].size(); j++) {
    int v = get<0>(V[0][j]);
    int cost = get<1>(V[0][j]);
    // cerr << "v = " << v << ", cost = " << cost << endl;
    WF[0][v] = min(WF[0][v], cost);
  }
  /*
  for (auto i=0; i<N; i++) {
    for (auto j=0; j<N; j++) {
      cerr << WF[i][j] << ", ";
    }
    cerr << endl;
  }
  */
  int ans = infty;
  for (unsigned int i=0; i<V[0].size(); i++) {
    for (unsigned int j=i+1; j<V[0].size(); j++) {
      ans = min(ans,
                get<1>(V[0][i])
                + WF[get<0>(V[0][i])][get<0>(V[0][j])]
                + get<1>(V[0][j]));
    }
  }
  cout << ((ans < infty) ? ans : -1) << endl;
}
