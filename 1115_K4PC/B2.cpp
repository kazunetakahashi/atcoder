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
// for (auto i=S.begin(); i != S.end(); i++) { }
// auto i = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

set<ll> S;

const ll infty = 1e14+10;

int main() {
  cerr << infty << endl;
  int N;
  long long M;
  cin >> N >> M;
  S.insert(M);
  S.insert(infty);
  S.insert(-1*infty);
  cerr << "insert: " << M << endl;
  ll ans = 0;
  for (auto i=0; i<N; i++) {
    ll t;
    cin >> t;
    ll cost = 10 * infty;  
    auto it = S.lower_bound(t);
    cerr << "ub = " << *it << endl;
    cost = min(abs(*it-t), cost);
    it--;
    cost = min(abs(*it-t), cost);
    cerr << "lb = " << *it << endl;
    ans += cost;
    S.insert(t);
    cerr << "insert: " << t << endl;
  }
  cout << ans << endl;
}
