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

int N;
ll E;
ll T;
ll x[100010];
ll memo[100010];
int ret[100010];

int main () {
  cin >> N >> E >> T;
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
  }
  memo[0] = x[0] + T;
  ret[0] = -1;
  for (auto i = 1; i < N; i++) {
    ll wait = memo[i-1] + (x[i] - x[i-1]) + T;
    ll back;
    if (ret[i-1] == -1) {
      back = x[i];
    } else {
      back = memo[ret[i-1]] + (x[i] - x[ret[i-1]]);
    }
    ll time = x[i] - x[ret[i-1]+1];
    if (2 * time < T) back += (T - 2 * time);
    back += 2 * time;
    if (wait < back) {
      memo[i] = back;
      ret[i] = ret[i-1];
    } else {
      memo[i] = wait;
      ret[i] = i;
    }
  }
  cout << memo[N-1] + (E - x[N-1]) << endl;
}
