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

int N;
int A[100010];

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
  }
  bool force_inc = false;
  bool force_dec = false;
  int cnt = 1;
  for (auto i = 0; i < N-1; ++i) {
    int now = A[i];
    int next = A[i+1];
    if ((force_inc && now > next) || (force_dec && now < next)) {
      cnt++;
      force_inc = false;
      force_dec = false;
    } else if (now < next) {
      force_inc = true;
    } else if (now > next) {
      force_dec = true;
    }
  }
  cout << cnt << endl;
}
