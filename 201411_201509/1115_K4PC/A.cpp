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
  int N;
  cin >> N;
  int A[1000];
  for (auto i=0; i<N; i++) {
    cin >> A[i];
  }
  int ans = 0;
  for (auto i=0; i<N; i++) {
    if (i+1 - A[i] > 0) {
      ans += i+1 - A[i];
    }
  }
  cout << ans << endl;
}
