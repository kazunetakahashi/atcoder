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
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

typedef tuple<int, int, int> rail; // now, src, cost
typedef tuple<int, int> station; // now, src
typedef tuple<int, int, int> state; // cost, src, now

int N;
int M;
priority_queue<state, vector<state>, greater<state> > Q;
set<station> visited;
map<station, vector<rail> > W;

int main () {
  cin >> N >> M;
  int p, q, c;
  for (auto i = 0; i < M; i++) {
    cin >> p >> q >> c;
    p--; q--; c--;
    W[make_tuple(p, -1)].push_back(make_tuple(q, c, 1));
    W[make_tuple(q, -1)].push_back(make_tuple(p, c, 1));
    W[make_tuple(p, c)].push_back(make_tuple(q, c, 0));
    W[make_tuple(q, c)].push_back(make_tuple(p, c, 0));
  }
  for (auto x : W) {
    if (get<1>(x.first) != -1) {
      W[x.first].push_back(make_tuple(get<0>(x.first), -1, 0));
    }
  }
  Q.push(make_tuple(0, -1, 0));
  while(!Q.empty()) {
    int cost = get<0>(Q.top());
    int src = get<1>(Q.top());
    int now = get<2>(Q.top());
    station s = make_tuple(now, src);
    Q.pop();
    if (visited.find(s) == visited.end()) {
      //cerr << "now = " << now << ", src = "
      //     << src << ", cost = " << cost << endl;
      visited.insert(s);
      if (now == N-1) {
        cout << cost << endl;
        return 0;
      }
      for (auto x : W[s]) {
        int dst = get<0>(x);
        int rosen = get<1>(x);
        int newcost = cost + get<2>(x);
        //cerr << "dst = " << dst << ", rosen = "
        //     << rosen << ", newcost = " << newcost << endl;
        station t = make_tuple(dst, rosen);
        if (visited.find(t) == visited.end()) {
          Q.push(make_tuple(newcost, rosen, dst));
        }
      }
    }
  }
  cout << -1 << endl;
}
