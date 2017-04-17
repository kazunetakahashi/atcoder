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

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

ll A, B, C;
string T;
int cntl[200010];
int cntr[200010];
ll cnt[200010];
ll cost[200010];

void count() {
  fill(cntr, cntr+200010, 0);
  fill(cntl, cntl+200010, 0);
  char now = T[0];
  int ans = 0;
  for (auto i = 0; i < (int)T.size(); i++) {
    // // cerr << T[i] << endl;
    if (now != T[i]) {
      ans++;
      now = T[i];
    }
  }
  cntr[0] = ans;
  // // cerr << ans << endl;
  ans = 0;
  now = T[0];
  for (auto i = 0; i < (int)T.size(); i++) {
    if (now != T[i]) {
      ans++;
      now = T[i];
      cntl[i]--;
    }
    cntr[i] = cntr[0] - ans;
    cntl[i] = cntl[i] + ans;
  }
  cntr[(int)T.size()] = 0;
  cntl[(int)T.size()] = cntr[0];
  if (T[(int)T.size()-1] == '0') {
    for (auto i = 0; i < (int)(T.size()); i++) {
      cntr[i]++;
    }
  }
  if (T[0] == '1') {
    for (auto i = 1; i <= (int)(T.size()); i++) {
      cntl[i]++;
    }
  }
  for (ll i = 0; i <= (ll)(T.size()); i++) {
    cnt[i] = max(cntl[i], cntr[i]);
    cost[i] = i * A  + (T.size() - i) * B + cnt[i] * C;
  }
}

int main () {
  cin >> A >> B >> C;
  cin >> T;
  count();
  for (auto i = 0; i < (int)(T.size()); i++) {
    // cerr << i << " " << cntl[i] << " " << cntr[i] << endl;
  }
  ll ans = 10010000010010010;
  for (auto i = 0; i <= (int)(T.size()); i++) {
    ans = min(ans, cost[i]);
  }
  cout << ans << endl;
}
