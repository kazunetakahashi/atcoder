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
  int x[110];
  fill(x, x+110, 0);
  int m = 200;
  for (auto i = 0; i < N; i++) {
    int a;
    cin >> a;
    x[a]++;
    m = min(m, a);
  }
  if (x[m] >= 3) {
    cout << "Impossible" << endl;
    return 0;
  } else if (x[m] == 2) {
    for (auto i = m+1; i <= 2*m-1; i++) {
      if (i >= 110 || x[i] < 2) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
    for (auto i = 2*m; i < 110; i++) {
      if (x[i] != 0) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  } else {
    for (auto i = m+1; i <= 2*m; i++) {
      if (i >= 110 || x[i] < 2) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
    for (auto i = 2*m+1; i < 110; i++) {
      if (x[i] != 0) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
}
