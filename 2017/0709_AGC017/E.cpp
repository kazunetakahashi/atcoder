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
int from[420];
int visited[420];
bool ret = true;

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

void visit(int i, int p) {
  if (visited[i] == -1) {
    int now = p;
    bool ok = false;
    while (now != -1) {
      if (output[now] == input[now]) {
        now = visited[now];
      } else {
        ok = true;
        break;
      }
    }
    if (!ok) {
      ret = false;
    }
  } else if (visited[i] == -2) {
    visited[i] = -1;
    for (auto x : V[i]) {
      visit(x, i);
    }
    visited[i] = p;
  }
}

int main () {
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
  fill(visited, visited+420, -2);
  for (auto i = 1; i <= H; ++i) {
    visit(i + M, -3);
    visit(-i + M, -3);
  }
  cout << (ret ? "YES" : "NO") << endl;
}
