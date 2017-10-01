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
#include <random> // random_device rd; mt19937 mt(rd());
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
const ll infty = 10000000000007;

typedef tuple<int, int> pass; // to, num

int n, m;
ll v[100010];
int x[200010];
int y[200010];
vector<pass> V[100010];
bool visited[100010];

int main () {
  cin >> n >> m;
  for (auto i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (auto i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    V[x[i]].push_back(pass(y[i], i));
    V[y[i]].push_back(pass(x[i], i));    
  }
  fill(visited, visited+100010, false);
  ll ans = 0;
  for (auto i = 0; i < n; ++i) {
    if (!visited[i]) {
      queue<int> Q;
      set<int> S;
      int sited = 0;
      ll sum = 0;
      ll mini = infty;
      Q.push(i);
      while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        if (!visited[now]) {
          visited[now] = true;
          sited++;
          sum += v[now];
          mini = min(mini, v[now]);
          for (auto x : V[now]) {
            int dst = get<0>(x);
            int num = get<1>(x);
            S.insert(num);
            if (!visited[dst]) {
              Q.push(dst);
            }
          }
        }
      }
      if ((int)S.size() < sited) {
        ans += sum - mini;
      } else {
        ans += sum;
      }
    }
  }
  cout << ans << endl;
}
