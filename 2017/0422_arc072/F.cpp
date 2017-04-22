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
ll L;
ll t[500010];
ll v[500010];
ll C;
ll V;

typedef tuple<ll, ll> info;
priority_queue<info, vector<info>, greater<info> > Q;

int main () {
  cin >> N >> L;
  for (auto i = 0; i < N; ++i) {
    cin >> t[i] >> v[i];
  }
  Q.push(info(t[0], v[0]));
  C = t[0] * v[0];
  V = v[0];
  cout << t[0] << endl;
  for (auto i = 1; i < N; ++i) {
    Q.push(info(t[i], v[i]));
    C += t[i] * v[i];
    V += v[i];
    while (V > L) {
      ll temp = get<0>(Q.top());
      ll vol = get<1>(Q.top());
      Q.pop();
      if (V - L >= vol) {
        V -= vol;
        C -= temp * vol;
      } else {
        ll nvol = vol - (V - L);
        V = L;
        C -= temp * (V - L);
        Q.push(info(temp, nvol));
      }
    }
    cout << fixed << setprecision(10) << C / (double)V << endl;
  }
}
