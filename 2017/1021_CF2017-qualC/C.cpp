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

vector<char> C;
vector<int> V;

int main () {
  cin >> S;
  int cnt = 0;
  C.push_back('X');
  for (auto i = 0; i < (int)S.size(); ++i) {
    if (S[i] == 'x') {
      cnt++;
    } else {
      V.push_back(cnt);
      cnt = 0;
      C.push_back(S[i]);
    }
  }
  C.push_back('X');
  if ((int)C.size() - 1 > (int) V.size()) {
    V.push_back(cnt);
  }
  for (auto x : V) {
    cerr << x << " ";
  }
  cerr << endl;
  for (auto x : C) {
    cerr << x << " ";
  }
  cerr << endl;
  int left = 0;
  int right = C.size() - 1;
  int ans = 0;
  while (left < right) {
    if (C[left] == C[right]) {
      ans += abs(V[left] - V[right-1]);
      left++;
      right--;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
