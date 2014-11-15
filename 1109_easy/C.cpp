#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // if (S.find(key) != S.end()) { }
// for (auto i=S.begin(); i != S.end(); i++) { }
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--; t--;
  int x[10010];
  int y[10010];  
  int d[10010];
  const int C = 10010;
  for (auto i=0; i<m; i++) {
    cin >> x[i] >> y[i] >> d[i];
    x[i]--;
    y[i]--;
  }
  vector< tuple<int, int> > V[C]; // node, cost
  for (auto i=0; i<m; i++) {
    V[x[i]].push_back(make_tuple(y[i], d[i]));
    V[y[i]].push_back(make_tuple(x[i], d[i]));
  }
  int cost[2][C];
  const int infty = 100000000;
  fill(&cost[0][0], &cost[0][0]+2*C, infty);
  for (auto time=0; time<2; time++) {
    priority_queue< tuple<int, int, int> > Q;
    bool visited[C];
    fill(visited, visited+C, false);
    int from[C];
    Q.push(make_tuple(0, ((time==0) ? s : t), -1)); // cost, machi, from
    while (!Q.empty()) {
      int ncost = -1 * get<0>(Q.top());
      int nnode = get<1>(Q.top());
      int nfrom = get<2>(Q.top());
      // cerr << "visiting " << nnode << endl;
      Q.pop();
      if (!visited[nnode]) {
	visited[nnode] = true;
	cost[time][nnode] = ncost;
	from[nnode] = nfrom;
	for (auto i=0; i<V[nnode].size(); i++) {
	  int dnode = get<0>(V[nnode][i]);
	  int dcost = get<1>(V[nnode][i]);
	  if (!visited[dnode]) {
	    Q.push(make_tuple(-1 * (dcost + ncost), dnode, nnode));
	  }
	}
      }
    }
  }
  for (auto i=0; i<n; i++) {
    if (cost[0][i] == cost[1][i] && cost[0][i] < infty) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
  /*
  while (true) {
    cerr << "now" << now << " " << cost[now] << endl;
    if (cost[now] == total/2) {
      cout << now+1 << endl;
      return 0;
    } else if (cost[now] < total/2) {
      cout << -1 << endl;
      return 0;
    } else {
      now = from[now];
      if (now < 0) {
	cout << -1 << endl;
	return 0;
      }
    }
  }
  */
}
