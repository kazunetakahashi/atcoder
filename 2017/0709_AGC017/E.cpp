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

int N, H;
int A[100010];
int B[100010];
int C[100010];
int D[100010];

vector<int> V[420];
int M = 210;
int input[420];
int output[420];

const int UFSIZE = 420;
int union_find[UFSIZE];

vector<int> S[420];

void init() {
  for (auto i=0; i<UFSIZE; i++) {
    union_find[i] = i;
  }
}

int root(int a) {
  if (a == union_find[a]) return a;
  return (union_find[a] = root(union_find[a]));
}

bool issame(int a, int b) {
  return root(a) == root(b);
}

void unite(int a, int b) {
  union_find[root(a)] = root(b);
}

bool isroot(int a) {
  return root(a) == a;
}

void add_edge(int i) {
  int from, to;
  if (C[i] == 0) {
    from = A[i];
  } else {
    from = -C[i];
  }
  if (D[i] == 0) {
    to = -B[i];
  } else {
    to = D[i];
  }
  V[from + M].push_back(to + M);
  output[from + M]++;
  input[to + M]++;
}

int main () {
  init();
  cin >> N >> H;
  fill(input, input+420, 0);
  fill(output, output+420, 0);
  for (auto i = 0; i < N; ++i) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    add_edge(i);
  }
  for (auto i = 1; i <= H; ++i) {
    if (input[i + M] > output[i + M]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (auto i = 1; i <= H; ++i) {
    if (input[-i + M] < output[-i + M]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (auto i = 0; i < 420; ++i) {
    for (auto x : V[i]) {
      unite(i, x);
    }
  }
  for (auto i = 0; i < 420; ++i) {
    S[root(i)].push_back(i);
  }
  for (auto i = 0; i < 420; ++i) {
    if (!(S[i].empty())) {
      bool ok = false;
      for (auto x : S[i]) {
        if (input[x] > 0 && input[x] == output[x]) {
          
        } else {
          ok = true;
          break;
        }
      }
      if (!ok) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
