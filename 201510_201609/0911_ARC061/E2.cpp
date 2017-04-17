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

typedef tuple<int, int, int> state; // cost, src, now

int N;
int M;
map<int, vector<int> > V[100010];
vector<int> W[100010];

priority_queue<state, vector<state>, greater<state> > Q;
int visited[100010];
set<int> used[100010];
bool

int main () {
  cin >> N >> M;
  int p, q, c;
  for (auto i = 0; i < M; i++) {
    cin >> p >> q >> c;
    p--; q--; c--;
    V[p][c].push_back(q);
    V[q][c].push_back(p);
  }
  
  fill(visited, visited+100010, -1);
  Q.push(make_tuple(0, -1, 0));
  while(!Q.empty()) {
    int cost = get<0>(Q.top());
    int src = get<1>(Q.top());
    int now = get<2>(Q.top());
    Q.pop();
    if (visited[now] == -1 ||
        (visited[now] == cost && used[now].find(src) == used[now].end())) {
      visited[now] = cost;
      used[now].insert(src);
      // cerr << "visited[" << now << "] = " << cost << ", src = " << src << endl;
      if (now == N-1) {
        cout << cost << endl;
        return 0;
      }
      stack<int> S;
      S.insert(now);
      bool alph[100010];
      fill(alph, alph)
        
        int dst = get<0>(x);
        int rosen = get<1>(x);
        int newcost = ((src != rosen) ? cost+1 : cost);
        if (visited[dst] == -1 ||
            (visited[dst] == newcost
             && used[dst].find(rosen) == used[now].end())) {
          
          Q.push(make_tuple(newcost, rosen, dst));
        }
      }
    }
  }
  cout << -1 << endl;
}
