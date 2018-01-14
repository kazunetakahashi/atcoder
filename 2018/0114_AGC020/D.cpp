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

string rep(string c, int n) {
  string ans = "";
  for (auto i = 0; i < n; ++i) {
    ans += c;
  }
  return ans;
}

string repa(int n) {
  return rep("A", n);
}

string repb(int n) {
  return rep("B", n);
}

string hanten(string S) {
  string ans = "";
  for (auto x : S) {
    if (x == 'A') {
      ans += "B";
    } else {
      ans += "A";
    }
  }
  return ans;
}

string f(int A, int B) {
  if (A == 1) {
    return repb(B/2) + "A" + repb(B - B/2);
  }
  if (A > B) {
    string x = f(B, A);
    reverse(x.begin(), x.end());
    return hanten(x);
  }
  if (B < A * (A+1)) {
    int k = B/A;
    int l = B%A;
    if (l <= k) {
      string ans = repb(l);
      string bu = "A" + repb(k);
      ans += rep(bu, A);
      return ans;
    } else {
      string bu1 = "A" + repb(k);
      string bu2 = "A" + repb(k+1);
      return rep(bu1, A-l) + rep(bu2, l);
    }
  } else {
    int k = B/(A+1);
    int l = B%(A+1);
    string bu1 = "A" + repb(k);
    string bu2 = "A" + repb(k+1);
    return repb(k) + rep(bu1, A-l) + rep(bu2, l);    
  }
  assert(false);
}

int main () {
  int Q;
  cin >> Q;
  int A[1010], B[1010], C[1010], D[1010];
  for (auto i = 0; i < Q; ++i) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  for (auto i = 0; i < Q; ++i) {
    string X = f(A[i], B[i]);
    cout << X.substr(C[i]-1, D[i]-C[i]+1) << endl;
  }
}
