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
ll A[100010];
ll sum[100010];
bool ok[100010];

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A+N);
  fill(sum, sum+100010, 0);
  sum[0] = A[0];
  for (auto i = 1; i < N; ++i) {
    sum[i] = A[i] + sum[i-1];
  }
  ok[N-1] = true;
  for (auto i = 1; i < N; ++i) {
    ok[i-1] = (sum[i-1] * 2 >= A[i]);
  }
  for (auto i = N-1; i >= 1; --i) {
    if (!ok[i]) {
      ok[i-1] = false;
    }
  }
  int cnt = 0;
  for (auto i = 0; i < N; ++i) {
    if (ok[i]) ++cnt;
  }
  cout << cnt << endl;
}
