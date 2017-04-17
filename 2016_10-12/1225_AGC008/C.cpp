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
  ll a[10];
  for (auto i = 0; i < 7; i++) {
    cin >> a[i];
  }
  ll ans_a = 0;
  ans_a += 4 * (a[0]/2 + a[3]/2 + a[4]/2);
  ans_a += 2 * a[1];
  if (a[0]%2 == 1 && a[3]%2 == 1 && a[4]%2 == 1) {
    ans_a += 6;
  }
  ll ans_b = 0;
  if (a[0] > 0 && a[3] > 0 && a[4] > 0) {
    ans_b += 6;
    a[0]--;
    a[3]--;
    a[4]--;
  }
  ans_b += 4 * (a[0]/2 + a[3]/2 + a[4]/2);
  ans_b += 2 * a[1];  
  cout << max(ans_a, ans_b)/2 << endl;
}
