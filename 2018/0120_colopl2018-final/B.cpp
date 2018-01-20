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

string S;
int depth[100010];
set<int> dset[100010];

string henkan(int l, int r, int d) {
  char op = S[l];
  if (op != '+' && op != '-' && op != '*' && op != '/') {
    cerr << S.substr(l, r-l) << endl;
    return S.substr(l, r-l);
  }
  string opp = string{op};
  vector< tuple<int, int> > V;
  auto it = dset[d].lower_bound(l+2);
  int start = l+2;
  while (it != dset[d].end() && *it < r-1) {
    V.push_back(make_tuple(start, *it));
    start = (*it) + 1;
    it++;
  }
  V.push_back(make_tuple(start, r-1));
  cerr << start << " " << r-1 << endl;
  vector<string> W;
  for (auto it = V.begin(); it != V.end(); ++it) {
    int s = get<0>(*it);
    int g = get<1>(*it);    
    W.push_back(henkan(s, g, d+1));
  }
  string ans = "";
  for (auto i = 0; i < (int)W.size(); ++i) {
    ans += W[i];
    if (i < (int)W.size()-1) {
      ans += opp;
    }
  }
  return "(" + ans + ")";
}

int main () {
  string S;
  cin >> S;
  fill(depth, depth+100010, 0);
  int cnt = 0;
  for (auto i = 0; i < (int)S.size(); ++i) {
    if (S[i] == '(') {
      cnt++;
    } else if (S[i] == ')') {
      cnt--;
    } else if (S[i] == ',') {
      depth[i] = cnt;
      dset[cnt].insert(i);
    }
  }
  cout << henkan(0, (int)S.size(), 0) << endl;
}
