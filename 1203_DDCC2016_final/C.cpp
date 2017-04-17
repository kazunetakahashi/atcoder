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

const ll infty = 1010101010101010;

ll A, B, C;
ll dp[100010];

int one(int x) {
  int cnt = 0;
  int t = x;
  while (t != 0) {
    t = (t >> 1);
    cnt++;
  }
  return x + (1 << (cnt-1));
}

int two(int x) {
  return (x << 1) + 1;
}

int three(int x) {
  int cnt = 0;
  int t = x;
  while (t != 0) {
    t = (t >> 1);
    cnt++;
  }
  return (((1 << (cnt-1)) - 1) ^ x) & ((1 << cnt) - 1);
}

int main () {
  for (auto i = 2; i < 10; i++) {
    cerr << i
         << " " << one(i)
         << " " << two(i)
         << " " << three(i) << endl;
  }
  cin >> A >> B >> C;
  string T;
  cin >> T;
  for (auto i = 0; i < 100010; i++) {
    dp[i] = infty;
  }
  dp[2] = min(A, B+C);
  dp[3] = min(B, A+C);
  for (int i = 2; i < 10000; i++) {
    int x = one(i);
    int y = two(i);
    int z = three(i);
    dp[x] = min(dp[i]+A, dp[x]);
    dp[y] = min(dp[i]+B, dp[y]);
    dp[z] = min(dp[i]+C, dp[z]);    
  }
  T = '1' + T;
  int t = 0;
  reverse(T.begin(), T.end());
  for (auto i = 0; i < (int)T.size(); i++) {
    t += ((T[i] - '0') << i);
  }
  cerr << t << endl;
  cout << dp[t] << endl;
}
