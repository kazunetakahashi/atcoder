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

int ans(int n, int d) {
  if (n%2 == 0) {
    return (127-d) + (n-1) * 127;
  } else {
    return d + (n-1) * 127;    
  }
}

int T;
int N[1010];
int D[1010];

int main () {
  cin >> T;
  for (auto i = 0; i < T; i++) {
    cin >> N[i] >> D[i];
  }
  for (auto i = 0; i < T; i++) {
    cout << ans(N[i], D[i]) << endl;
  }
}
