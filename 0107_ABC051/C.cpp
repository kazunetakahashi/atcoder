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

string S = "";

void add(string c, int t) {
  for (auto i = 0; i < t; i++) {
    S += c;
  }
}

int main () {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  int x = tx - sx;
  int y = ty - sy;
  add("U", y);
  add("R", x);
  add("R", 1);
  add("D", y+1);
  add("L", x+1);
  add("U", 1);
  add("L", 1);
  add("U", y+1);
  add("R", x+1);
  add("D", 1);
  add("D", y);
  add("L", x);
  cout << S << endl;
}
