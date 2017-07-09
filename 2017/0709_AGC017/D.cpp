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
// const ll M = 1000000007;

int N;
int x[100010];
int y[100010];
vector<int> V[100010];
int parent[100010];

void make_parent(int v, int p) {
  parent[v] = p;
  for (auto x : V[v]) {
    if (x != p) {
      make_parent(x, v);
    }
  }
}

int grundy(int v) {
  int s = V[v].size();
  if (v == 0) ++s;
  int ans;
  if (s == 1) {
    ans = 0;
  } else if (s == 2) {
    for (auto x : V[v]) {
      if (x != parent[v]) {
        ans = grundy(x) + 1;
      }
    }
  } else {
    ans = 0;
    for (auto x : V[v]) {
      if (x != parent[v]) {
        ans ^= grundy(x);
      }
    }
  }
  cerr << "grundy(" << v << ") = " << ans << endl;
  return ans;
}

int main () {
  cin >> N;
  for (auto i = 0; i < N-1; ++i) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    V[x[i]].push_back(y[i]);
    V[y[i]].push_back(x[i]);
  }
  make_parent(0, -1);
  if (grundy(0) == 0) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;    
  }
}
