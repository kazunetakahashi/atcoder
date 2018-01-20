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

string henkan(string str) {
  char op = str[0];
  if (op != '+' && op != '-' && op != '*' && op != '/') {
    return str;
  }
  string opp = string{op};
  string naka = str.substr(2, str.size() - 3);
  // cerr << naka << endl;
  int cnt = 0;
  vector<string> V;
  int start = 0;
  for (auto i = 0; i < (int)naka.size(); ++i) {
    if (naka[i] == '(') {
      cnt++;
    } else if (naka[i] == ')') {
      cnt--;
    } else if (naka[i] == ',' && cnt == 0) {
      V.push_back(str.substr(start, i-start));
      start = i+1;
    }
  }
  V.push_back(str.substr(start, (int)naka.size()-start));
  for (auto it = V.begin(); it != V.end(); ++it) {
    *it = henkan(*it);
  }
  string ans = "";
  for (auto i = 0; i < (int)V.size(); ++i) {
    ans += V[i];
    if (i < (int)V.size()-1) {
      ans += opp;
    }
  }
  return "(" + ans + ")";
}

int main () {
  string S;
  cin >> S;
  cout << henkan(S) << endl;
}
