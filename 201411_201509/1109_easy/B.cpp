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
  int a = n%20;
  int b = (n-1)/20;
  if (a == 0) a = 20;
  if (b % 2 != 0) {
    cout << 21 - a << endl;
  } else {
    cout << a << endl;
  }
}
