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

typedef tuple<int, int> point;
typedef tuple<point, int> circle;
typedef tuple<double, int> pass;
typedef tuple<double, int> state;

int N;
circle C[1010];
vector<pass> V[1010];

double distance(point x, point y) {
  double a = get<0>(x);
  double b = get<1>(x);
  double c = get<0>(y);
  double d = get<1>(y);
  // cerr << a << " " << b << " " << c << " " << d << " " << endl;
  return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main () {
  int x, y;
  cin >> x >> y;
  C[0] = make_tuple(make_tuple(x, y), 0);
  cin >> x >> y;
  cin >> N;
  C[N+1] = make_tuple(make_tuple(x, y), 0);
  int r;
  for (auto i = 1; i <= N; i++) {
    cin >> x >> y >> r;
    C[i] = make_tuple(make_tuple(x, y), r);
  }
  for (auto i = 0; i <= N+1; i++) {
    point src = get<0>(C[i]);
    int src_r = get<1>(C[i]);
    for (auto j = 0; j <= N+1; j++) {
      if (i == j) continue;
      point dst = get<0>(C[j]);
      int dst_r = get<1>(C[j]);
      // cerr << distance(src, dst) << endl;
      double dist = max(0.0, distance(src, dst) - src_r - dst_r);
      // cerr << "i = " << i << ", j = " << j << ", dist = " << dist << endl;
      V[i].push_back(make_tuple(dist, j));
    }
  }
  bool visited[1010];
  fill(visited, visited+1010, false);
  priority_queue<state, vector<state>, greater<state> > Q;
  Q.push(make_tuple(0.0, 0));
  while (!Q.empty()) {
    double cost = get<0>(Q.top());
    int src = get<1>(Q.top());
    Q.pop();
    if (src == N+1){
      cout << fixed << setprecision(12) << cost << endl;
      return 0;
    } else if (!visited[src]) {
      visited[src] = true;
      for (auto p : V[src]) {
        double newcost = get<0>(p);
        int dst = get<1>(p);
        if (!visited[dst]) {
          Q.push(make_tuple(cost + newcost, dst));
        }
      }
    }
  }
}
