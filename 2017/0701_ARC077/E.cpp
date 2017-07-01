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

ll n, m;
ll a[100010];

ll imos[3][100010];

int main () {
  cin >> n >> m;
  for (auto i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll sum = 0;
  for (auto i = 0; i < n-1; ++i) {
    sum += abs(a[i+1] - a[i]);
  }
  fill(&imos[0][0], &imos[0][0]+3*100010, 0);
  for (auto i = 0; i < n-1; ++i) {
    if (a[i] < a[i+1]) {
      imos[0][a[i]+2] += 1;
      imos[0][a[i+1]+1] -= 1;
      imos[2][a[i+1]+1] -= a[i+1] - (a[i] + 1);
    } else {
      imos[0][1] += 1;
      imos[0][a[i+1]+1] -= 1;
      imos[0][a[i]+2] += 1;
      imos[0][m+1] -= 1;
      imos[2][1] += m - (a[i] + 1);
      imos[2][a[i+1] + 1] -= m - (a[i] + 1) + (a[i+1] + 1);
    }
  }
  for (auto k = 0; k < 3; ++k) {
    for (auto i = 0; i < m+2; ++i) {
      imos[k][i+1] += imos[k][i];
    }
    if (k < 2) {
      for (auto i = 0; i <= m+2; ++i) {
        imos[k+1][i] += imos[k][i];
      }      
    }
  }
  ll ans = 0;
  for (auto i = 1; i <= m; ++i) {
    ans = max(ans, imos[2][i]);
  }
  cout << sum - ans << endl;
}

