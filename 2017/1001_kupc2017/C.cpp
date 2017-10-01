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
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int A;
string S;
vector<int> V;

int calc(string str) {
  assert(str.size() <= 7);
  int tmp = 1;
  int ans = 0;
  for (auto i = 0; i < (int)str.size(); ++i) {
    ans += tmp * (str[i] - 'a' + 1);
    tmp *= A;
  }
  //cerr << ans << endl;
  return ans;
}

string maximal(int h) {
  string ans = "";
  while (h > 0) {
    for (auto i = 26; i >= 1; --i) {
      if (h - i < 0) continue;
      if ((h - i) % A == 0) {
        string t{(char)('a' + i - 1)};
        ans = ans + t;
        h = (h - i)/A;
        break;
      }
    }
    //cerr << ans << " " << h << endl;
  }
  return ans;
}

int main () {
  cin >> A >> S;
  if (S.size() <= 7) {
    cout << maximal(calc(S)) << endl;
    return 0;
  }
  string T = S.substr(0, S.size()-7);
  string U = S.substr(S.size()-7, 7);
  assert(S == T + U);
  string ans = 0;
  int kari = 0;
  cerr << "xxx" << endl;
  for (auto j = 0; j < (int)T.size(); ++j) {
    char x = T[j];
    int now = x - 'a' + 1;
    now -= kari;
    for (auto i = 26; i >= 1; --i) {
      if ((i - now) % A == 0) {
        string t{(char)('a' + i - 1)};
        ans = ans + t;
        kari = (i - now)/A;
        break;
      }
    }
    cerr << ans << endl;
  }
  ans += maximal(calc(U) + kari);
  cout << ans << endl;
}
