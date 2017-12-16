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

int main () {
  string S;
  cin >> S;
  int x[2];
  cin >> x[0] >> x[1];
  vector<int> V[2];
  bool isx = 0;
  int cnt = 0;
  bool isfirst = true;
  for (auto e : S) {
    if (e == 'F') cnt++;
    else {
      if (isfirst) {
        x[0] -= cnt;
        isfirst = false;
      } else if (cnt > 0) {
        V[isx].push_back(cnt);          
      }
      cnt = 0;
      isx = !isx;
    }
  }
  if (cnt > 0) {
    V[isx].push_back(cnt);
  }
  for (auto k = 0; k < 2; ++k) {
    int sum = 0;
    for (auto e : V[k]) {
      sum += e;
    }
    if ((x[k] + sum) %2 != 0) {
      cout << "No" << endl;
      return 0;
    }
    int mokuhyo = (x[k] + sum)/2;
    if (mokuhyo < 0 || mokuhyo > sum) {
      cout << "No" << endl;
      return 0;
    }
    bool dp[10000];
    fill(dp, dp+10000, false);
    dp[0] = true;
    for (auto e : V[k]) {
      for (auto i = 9999; i >= 0; --i) {
        if (dp[i] && i + e < 10000) {
          dp[i+e] = true;
        }
      }
    }
    if (!dp[mokuhyo]) {
      cout << "No" << endl;
      return 0;      
    }
  }
  cout << "Yes" << endl;
}
