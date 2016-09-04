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

int main () {
  ll A[3];
  cin >> A[0] >> A[1] >> A[2];
  for (auto i = 0; i < 3; i++) {
    if (A[i]%2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = A[0] * A[1];
  for (auto i = 0; i < 3; i++) {
    ans = min(A[i] * A[(i+1)%3], ans);
  }
  cout << ans << endl;
}
