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
  string S[110];
  for (auto i=0; i<n; i++) {
    cin >> S[i];
  }
  int x = 0; 
  int y = 0;
  for (auto i=0; i<n; i++) {
    for (auto j=0; j<n; j++) {
      if (S[j][i] == '.') x++;
      if (S[j][i] == 'X') break;
    }
  }
  for (auto i=0; i<n; i++) {
    for (auto j=0; j<n; j++) {
      if (S[n-1-j][i] == '.') y++;
      if (S[n-1-j][i] == 'Y') break;
    }
  }
  if (x == y) {
    cout << "Impossible" << endl;
  } else if (x > y) {
    cout << "X" << endl;
  } else {
    cout << "Y" << endl;
  }
}
