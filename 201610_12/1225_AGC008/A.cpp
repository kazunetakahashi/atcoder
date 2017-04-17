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
  ll x, y;
  cin >> x >> y;
  vector<int> V;
  if (y+x >= 0) {
    V.push_back(y+x+1);
  }
  if (y-x > 0) {
    V.push_back(y-x);
  }
  if (-y+x >= 0) {
    V.push_back(-y+x+2);
  }
  if (-y-x > 0) {
    V.push_back(-y-x+1);
  }
  cout << *min_element(V.begin(), V.end()) << endl;
}
