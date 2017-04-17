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

int N;
string T;
vector<bool> X;

bool ok(bool left, bool center, bool right, bool t) {
  if (center) {
    return ((left == right) == t);
  } else {
    return ((left != right) == t);
  }
}

bool add(bool left, bool center, bool t) {
  if (center) {
    if (t) return left;
    return !left;
  } else {
    if (t) return !left;
    return left;    
  }
}

bool check(vector<bool> S) {
  assert(N == (int)S.size());
  for (auto i = 0; i < N; ++i) {
    int left, right;
    int center = i;
    if (i == 0) {
      left = N-1;
      right = 1;
    } else if (i == N-1) {
      left = N-2;
      right = 0;
    } else {
      left = i-1;
      right = i+1;
    }
    if (!ok(S[left], S[center], S[right], X[center])) {
      return false;
    }
  }
  return true;
}

void flush(vector<bool> S) {
  assert(N == (int)S.size());
  for (auto x : S) {
    if (x) {
      cout << "S";
    } else {
      cout << "W";
    }
  }
  cout << endl;
}

int main () {
  cin >> N >> T;
  for (auto x : T) {
    X.push_back(x == 'o');
  }
  vector<bool> Y[4] = { {true, true}, {true, false},
                        {false, true}, {false, false}, };
  for (auto i = 0; i < 4; ++i) {
    for (auto j = 1; j < N-1; ++j) {
      Y[i].push_back(add(Y[i][j-1], Y[i][j], X[j]));
    }
    if (check(Y[i])) {
      flush(Y[i]);
      return 0;
    }
  }
  cout << "-1" << endl;
}
