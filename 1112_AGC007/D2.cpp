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

int main () {
  cin >> N >> E >> T;
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
  }
  fill(memo, memo+100010, -1);
  memo[0] = x[0] + T;
  int now = 1;
  int ret = -1;
  while (now < N) {
    //cerr << "ret = " << ret << ", now = " << now << endl;
    ll back;
    if (ret == -1) {
      back = x[now];
    } else {
      back = memo[ret] + (x[now] - x[ret]);
    }
    ll time = x[now] - x[ret+1];
    if (2 * time < T) back += (T - 2 * time);
    back += 2 * time;
    if (memo[now] == -1) {
      memo[now] = back;
      ret++;
    } else {
      if (memo[now] > back) {
        memo[now] = back;
        ret++;
        if (ret > now) now++;
      } else {
        now++;
      }
    }
  }
  cout << memo[N-1] + (E - x[N-1]) << endl;
}
