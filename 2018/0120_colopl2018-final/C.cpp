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
const ll infty = 1000000000000000000;

typedef tuple<ll, ll, ll> state;

int main () {
  int N;
  cin >> N;
  ll a[200010];
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }
  priority_queue<state, vector<state>, greater<state> > Q;
  ll ans[200010];
  fill(ans, ans+200010, infty);
  for (auto i = 0; i < N; ++i) {
    Q.push(state(a[i], i, 0));
  }
  while(!Q.empty()) {
    ll num = get<0>(Q.top());
    ll place = get<1>(Q.top());
    ll dist = get<2>(Q.top());
    Q.pop();
    if (ans[place] == infty) {
      ans[place] = num;
      ll nplace[2] = {place + 1, place - 1};
      ll ndist = dist+1;
      ll nnum = num - dist * dist + ndist * ndist;
      for (auto j = 0; j < 2; ++j) {
        if (0 <= nplace[j] && nplace[j] < N) {
          Q.push(state(nnum, nplace[j], ndist));
        }
      }
    } 
  }
  for (auto i = 0; i < N; ++i) {
    cout << a[i] << endl;
  }
}
