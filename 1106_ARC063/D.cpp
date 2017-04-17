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

vector< vector<int> > V;

int main () {
  int N, T;
  cin >> N >> T;
  int A[100010];
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  multiset<int> S;
  for (auto i = 0; i < N; i++) {
    S.insert(A[i]);
  }
  int income = 0;
  for (auto i = 0; i < N; i++) {
    auto x = S.end();
    x--;
    int y = *x;
    income = max(income, y - A[i]);
    S.erase(S.find(A[i]));
  }
  reverse(A, A+N);
  set<int> SS;
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    if (SS.find(A[i]+income) == SS.end()) {
      //
    } else {
      ans++;
    }
    SS.insert(A[i]);
  }
  cout << ans << endl;
}
