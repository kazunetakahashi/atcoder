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
  int N;
  cin >> N;
  int p[20010];
  for (auto i = 0; i < N; i++) {
    cin >> p[i];
    p[i]--;
  }
  int a[20010];
  int b[20010];
  int C = 20001;
  for (auto i = 0; i < N; i++) {
    a[p[i]] = C * p[i] + i + 1;
    b[p[i]] = C * C - C * p[i] + 1;
  }
  for (auto i = 0; i < N; i++) {
    cout << a[i];
    if (i < N-1) cout << " ";
  }
  cout << endl;
  for (auto i = 0; i < N; i++) {
    cout << b[i];
    if (i < N-1) cout << " ";
  }
  cout << endl;
}
