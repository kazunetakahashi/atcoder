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

ll X, Y, Z;
ll A[100010];
ll B[100010];
ll C[100010];
typedef tuple<ll, ll, ll> unit;

ll silver[100010];
ll gold[100010];

int main () {
  cin >> X >> Y >> Z;
  ll N = X+Y+Z;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i] >> B[i] >> C[i];
  }
  ll ans = 0;
  for (auto i = 0; i < N; ++i) {
    A[i] -= C[i];
    B[i] -= C[i];
    ans += C[i];
  }
  unit T[100010];
  for (auto i = 0; i < N; ++i) {
    T[i] = unit(A[i]-B[i], A[i], B[i]);
  }
  sort(T, T+N);
  for (auto i = 0; i < N; ++i) {
    A[i] = get<1>(T[i]);
    B[i] = get<2>(T[i]);
    // cerr << "i = " << i << ", (" << A[i] << ", " << B[i] << ")" << endl;
  }
  ll sum = 0;
  priority_queue<ll, vector<ll>, greater<ll> > Q;
  for (auto i = 0; i < N; ++i) {
    sum += B[i];
    Q.push(B[i]);
    while ((ll)Q.size() > Y) {
      sum -= Q.top();
      Q.pop();
    }
    silver[i] = sum;
    // cerr << "silver[" << i << "] = " << silver[i] << endl;
  }
  sum = 0;
  priority_queue<ll, vector<ll>, greater<ll> > QQ;
  for (auto i = N-1; i >= 0; --i) {
    sum += A[i];
    QQ.push(A[i]);
    while ((ll)QQ.size() > X) {
      sum -= QQ.top();
      QQ.pop();
    }
    gold[i] = sum;
    // cerr << "gold[" << i << "] = " << gold[i] << endl;
  }
  ll maxi = -1000000000000000000;
  for (auto i = Y-1; i <= Y+Z-1; ++i) {
    // cerr << "sliver[" << i << "] = " << silver[i]
    //      << ", gold[" << i+1 << "] = " << gold[i+1] << endl;
    maxi = max(maxi, gold[i+1]+silver[i]);
  }
  cout << ans + maxi << endl;
}
