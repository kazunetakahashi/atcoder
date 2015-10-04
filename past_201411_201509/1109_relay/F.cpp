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
  int n;
  cin >> n;
  vector<int> V[100010];
  for (auto i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    V[x].push_back(y);
    V[y].push_back(x);
  }
  int D[100010];
  bool visited[100010];
  fill(visited, visited+100010, false);
  stack< pair<int, int> > S; // node, cost;
  S.push(make_pair(0, -1));
  while (!S.empty()) {
    int now = S.top().first;
    int from = S.top().second;
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      D[now] = ( (from == -1) ? 0 : (D[from]+1) );
      for (auto i=0; i<V[now].size(); i++) {
	int dst = V[now][i];
	if (!visited[dst]) {
	  S.push(make_pair(dst, now));
	} else if (from != dst) {
	  cout << D[now] - D[dst] + 1 << endl;
	  return 0;
	}
      }
    }
  }
}
