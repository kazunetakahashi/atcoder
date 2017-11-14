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
const ll infty = 10000000000000007;

int N;
ll a[300010];
ll plusscore[300010];
ll minusscore[300010];

int main () {
  cin >> N;
  for (auto i = 0; i < 3*N; ++i) {
    cin >> a[i];
  }
  fill(plusscore, plusscore+300010, -infty);
  fill(minusscore, minusscore+300010, infty);
  priority_queue<ll, vector<ll>, greater<ll> > Q;
  ll sum = 0;
  for (auto i = 0; i < 2*N; ++i) {
    Q.push(a[i]);
    sum += a[i];
    while ((int)Q.size() > N) {
      sum -= Q.top();
      Q.pop();      
    }
    plusscore[i] = sum;
  }
  priority_queue<ll> QQ;
  sum = 0;
  for (auto i = 3*N-1; i >= N; --i) {
    QQ.push(a[i]);
    sum += a[i];
    // cerr << "a[" << i << "] = " << a[i] << endl;
    while ((int)QQ.size() > N) {
      sum -= QQ.top();
      QQ.pop();
    }
    minusscore[i] = sum;
  }
  ll ans = -infty * 3;
  for (auto i = 0; i < 3*N; ++i) {
    cerr << "plusscore[" << i << "] = " << plusscore[i] << endl;
  }
  for (auto i = 0; i < 3*N; ++i) {
    cerr << "minusscore[" << i << "] = " << minusscore[i] << endl;
  }
  for (auto i = N; i < 2*N; ++i) {
    ans = max(ans, plusscore[i] - minusscore[i+1]);
  }
  // cout << ans << endl;
}
