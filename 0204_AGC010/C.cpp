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

int N;
vector<int> V[100010];
vector<int> children[100010];
int parent[100010];
int root;
ll A[100010];
bool ok = true;

ll deru(int now) {
  if (!ok) return 0;
  if ((int)children[now].size() == 0) return A[now];
  ll sum = 0;
  ll maxi = 0;
  for (auto x : children[now]) {
    ll temp = deru(x);
    sum += temp;
    maxi = max(maxi, temp);
  }
  if ((int)children[now].size() == 1) {
    if (A[now] == sum) return A[now];
    ok = false;
    return 0;
  }
  ll y = sum - A[now];
  ll x = 2 * A[now] - sum;
#if DEBUG == 1
    cerr << "now = " << now << ", x = " << x << ", y = " << y << endl; 
#endif
  if (y >= 0 && x >= 0 && y <= sum - maxi && y <= sum/2) {
    return x;
  } else {
    ok = false;
    return 0;
  }
}

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (auto i = 0; i < N-1; ++i) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  if (N == 2) {
    cout << ((A[0] == A[1]) ? "YES" : "NO") << endl;
    return 0;
  }
  for (auto i = 0; i < N; ++i) {
    if ((int)V[i].size() > 1) {
      root = i;
      break;
    }
  }
  stack<int> S;
  parent[root] = -1;
  S.push(root);
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    for (auto x : V[now]) {
      if (x != parent[now]) {
#if DEBUG == 1
        cerr << "parent[" << x << "] = " << now << endl;
#endif
        parent[x] = now;
        children[now].push_back(x);
        S.push(x);
      }
    }
  }
  if (deru(root) == 0 && ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
