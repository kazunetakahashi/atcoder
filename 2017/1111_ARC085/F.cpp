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

class SegTree { // index starts at 0.
public:
  int N;
  int* dat;
  static int INFTY; // (1 << 31) - 1;
  
  SegTree(int n) {
    N = 1;
    while (N < n) N *= 2;
    dat = new int[2 * N - 1];
    for (auto i = 0; i < 2 * N - 1; ++i) {
      dat[i] = INFTY;
    }
  }

  ~SegTree() {
    delete[] dat;
  }

  void update(int k, int a) {
    k += N - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1)/2;
      dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

  int find(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INFTY;
    if (a <= l && r <= b) return dat[k];
    int vl = find(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = find(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }

  int find(int a, int b) {
    return find(a, b, 0, 0, N);
  }
  
};

int SegTree::INFTY = 2147483647; // (1 << 31) - 1;

int N;
int b[200020];
int Q;
vector<int> V[200020];

int score(int x) {
  if (b[x] == 0) return -1;
  return 1;
}

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> b[i];
  }
  cin >> Q;
  for (auto i = 0; i < Q; ++i) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    V[l].push_back(r);
  }
  for (auto i = 0; i < N; ++i) {
    sort(V[i].begin(), V[i].end());
  }
  int zeros = 0;
  for (auto i = 0; i < N; ++i) {
    if (b[i] == 0) ++zeros;
  }
  SegTree S(N+1);
  S.update(0, zeros);
  for (auto i = 0; i < N; ++i) {
    for (auto x : V[i]) {
      S.update(x+1, S.find(i, x+2));
    }
    S.update(i+1, min(S.find(i, i+1) + score(i), S.find(i+1, i+2)));
    // cerr << "DP[" << i+1 << "] = " << S.find(i+1, i+2) << endl;
  }
  cout << S.find(N, N+1) << endl;
}
