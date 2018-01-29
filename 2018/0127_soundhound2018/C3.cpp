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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;

//--------------二部マッチング--------------------

int MAX_V;
vector<int> G[100010];
int match[100010];
bool used[100010];

void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int v) {
  used[v] = true;
  for (auto u : G[v]) {
    int w = match[u];
    if (w < 0 || (!used[w] && dfs(w))) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int bipartite_matching() {
  int res = 0;
  fill(match, match+100010, -1);
  for (auto v = 0; v < MAX_V; ++v) {
    if (match[v] < 0) {
      fill(used, used+100010, false);
      if (dfs(v)) {
        res++;
      }
    }
  }
  return res++;
}


//---------------------------------------------------

int R, C;
string S[100];
int vertex = 0;

bool valid(int i, int j) {
  return (0 <= i && i < R && 0 <= j && j < C && S[i][j] == '.');
}

int num(int i, int j) {
  return i * C + j;
}

void add_edge_grid(int i, int j) {
  if (!valid(i, j)) return;
  int now = num(i, j);
  vertex++;
  if ((i+j) % 2 == 0) {
    for (auto k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (valid(x, y)) {
        add_edge(now, num(x, y));
#if DEBUG == 1
        // cerr << "add_edge(" << now << ", " << num(x, y) << ", 1)" << endl;
#endif
      }
    }
  } else {
    //
  }
}

int main () {
  cin >> R >> C;
  for (auto i = 0; i < R; ++i) {
    cin >> S[i];
  }
  MAX_V = R * C - 1;
  for (auto i = 0; i < R; ++i) {
    for (auto j = 0; j < C; ++j) {
      add_edge_grid(i, j);
    }
  }
  ll maxi = bipartite_matching();
#if DEBUG == 1
  cerr << "vertex = " << vertex << endl;
  cerr << "maxi = " << maxi << endl;
#endif
  cout << vertex - maxi << endl;
}
