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

int dist(char x) {
  if (x == 'a') return 0;
  int d = (x - 'a');
  return 26 - d;
}

int main () {
  string S;
  int K;
  cin >> S >> K;
  string ans = "";
  for (auto x : S) {
    int d = dist(x);
    char c;
    if (K >= d) {
      c = 'a';
      K -= d;
    } else {
      c = x;
    }
    ans = ans + c;
  }
  ans[ans.size()-1] = ans[ans.size()-1] + K%26;
  cout << ans << endl;
}
