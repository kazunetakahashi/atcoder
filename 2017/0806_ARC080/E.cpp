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

class SegTree { // index starts at 0.
public:
  int N;
  int* dat;
  static int infty; // (1 << 31) - 1;

  SegTree(){}

  SegTree(int n) {
    N = 1;
    while (N < n) N *= 2;
    dat = new int[2 * N - 1];
    for (auto i = 0; i < 2 * N - 1; ++i) {
      dat[i] = infty;
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

  pair<int, int> find(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return make_pair(infty, k);
    if (a <= l && r <= b) return make_pair(dat[k], k);
    pair<int, int> vl = find(a, b, k * 2 + 1, l, (l + r) / 2);
    pair<int, int> vr = find(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }

  pair<int, int> find(int a, int b) {
    return find(a, b, 0, 0, N);
  }
  
};

int SegTree::infty = 2147483647; // (1 << 31) - 1;

typedef pair<int, int> unit;

SegTree st[2];

vector<unit> ans;

void solve(int l, int r) {
  if (l == r) return;
  int take = 0;
  if (l%2 == 1) {
    take = 1;
  }
  pair<int, int> p = st[take].find(l/2, r/2);
  int f = p.first;
  int indf = p.second * 2 + take;
  take++;
  take %= 2;
  pair<int, int> q = st[take].find((indf+1)/2, r/2);
  int s = q.first;
  int inds = q.second * 2 + take;
  cerr << f << " " << indf << " " << s << " " << inds << endl;
  ans.push_back(unit(f, s));
  solve(l, indf);
  solve(indf+1, inds);
  solve(inds+1, r);
}

int main () {
  int N;
  int p[200010];
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> p[i];
  }
  st[0] = SegTree(N/2);
  st[1] = SegTree(N/2);
  for (auto i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      st[i%2].update(i/2, p[i]);
    }
  }
  solve(0, N);
  sort(ans.begin(), ans.end());
  for (auto it = ans.begin(); it != ans.end(); ++it) {
    auto x = *it;
    cout << x.first << " " << x.second;
    if (it+1 == ans.end()) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}
