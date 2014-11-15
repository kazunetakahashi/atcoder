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
#include <set> // if (S.find(key) != S.end()) { }
// for (auto i=S.begin(); i != S.end(); i++) { }
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  double X[1000];
  for (auto i=0; i<n; i++) {
    cin >> X[i];
  }
  // cout << X[0] << X[n-1] << n-1 << endl;
  cout << fixed << setprecision(9) << (X[n-1]-X[0])/(n-1) << endl;
}
