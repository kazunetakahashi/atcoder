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

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef tuple<int, bool> state;

int N;
int M;
vector<int> V[100010];
int visited[100010];

vector<ll> W[3];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  fill(visited, visited+100010, 0);
  for (auto i = 0; i < N; ++i) {  
    if (visited[i] != 0) continue;
    bool is_there_odd = false;
    ll cnt = 0;
    stack<state> S;
    S.push(state(i, false));
    while (!S.empty()) {
      int now = get<0>(S.top());
      bool cl = get<1>(S.top());
      int col = (cl ? 1 : 2);
      S.pop();
      if (visited[now] == 0) {
        visited[now] = col;
        // cerr << "visited[" << now << "] = " << col << endl;
        ++cnt;
        for (auto x : V[now]) {
          if (visited[x] == 0) {
            // cerr << x << endl;
            S.push(state(x, !cl));
          } else {
            if (col == visited[x]) {
              is_there_odd = true;
            }
          }
        }
      }
    }
    /*
    cerr << "i = " << i << ", cnt = "
         << cnt << ", is_there_odd = " << is_there_odd << endl;
    */
    if (cnt == 1) {
      W[2].push_back(cnt);
    } else if (is_there_odd) {
      W[1].push_back(cnt);
    } else {
      W[0].push_back(cnt);
    }
  }
  ll i = (ll)W[2].size();
  ll q = (ll)W[0].size();
  ll p = (ll)W[1].size();
  //cerr << p << " " << q << " " << i << endl;
  ll ans = i * i + 2 * i * (N - i) + p * p + 2 * p * q + 2 * q * q;
  cout << ans << endl;
}
