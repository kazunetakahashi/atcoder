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

set<int> S;
int N;
int T[200010];

int main () {
  cin >> N;
  int tmp;
  for (auto i = 1; i <= N; i++) {
    cin >> tmp;
    T[tmp] = i;
  }
  S.insert(0);
  S.insert(N+1);
  ll cnt = 0;
  for (auto i = 1; i <= N; i++) {
    ll x = T[i];
    auto it = S.lower_bound(x);
    ll ub = *it;
    ll lb = *(--it);
    /*
    cerr << "i = " << i
         << ", x = " << x << ", lb = " << lb << ", ub = " << ub << endl;
    cerr << "point : " << x * (x - lb) * (ub - x) << endl;
    */
    cnt += i * (x - lb) * (ub - x);
    S.insert(x);
  }
  cout << cnt << endl;
}
