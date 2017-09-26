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
const int infty = 1000000007;

string A;
int N;

void clear(bool* ary) {
  fill(ary, ary+26, false);
}

int first(bool* ary) {
  for (auto i = 0; i < 26; ++i) {
    if (!ary[i]) return i;
  }
  assert(false);
  return infty;
}

int main () {
  cin >> A;
  N = A.size();
  vector<int> V;
  V.push_back(N);
  int size = 0;
  bool used[26];
  clear(used);
  for (auto i = N-1; i >= 0; --i) {
    if (!used[A[i] - 'a']) {
      ++size;
      used[A[i] - 'a'] = true;
    }
    if (size == 26) {
      size = 0;
      clear(used);
      V.push_back(i);
    }
  }
  V.push_back(0);
  reverse(V.begin(), V.end());
  vector<string> W;
  for (auto i = 0; i < (int)V.size()-1; ++i) {
    W.push_back(A.substr(V[i], V[i+1] - V[i]));
  }
  vector<int> ans;
  clear(used);
  for (auto x : W[0]) {
    used[x - 'a'] = true;
  }
  ans.push_back(first(used));
  for (auto i = 1; i < (int)W.size(); ++i) {
    string str = W[i];
    char c = 'a' + ans[i-1];    
    int found = infty;
    for (auto j = 0; j < (int)str.size(); ++j) {
      if (str[j] == c) {
        found = j;
        break;
      }
    }
    assert(found < infty);
    clear(used);
    for (auto j = found+1; j < (int)str.size(); ++j) {
      used[str[j] - 'a'] = true;
    }
    ans.push_back(first(used));
  }
  string ret = "";
  for (auto x : ans) {
    ret = ret + to_string('a' + x);
  }
  cout << ret << endl;
}
