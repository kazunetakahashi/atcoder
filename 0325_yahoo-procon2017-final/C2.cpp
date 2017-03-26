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

const int C = 350;
// const ll M = 1000000007;

int N, Q;
ll M;
ll A[100010];
int l[100010];
int r[100010];
ll d[100010];

ll sq[C][C];
map<ll, int> cnt[C];
ll added[C];

void make_cnt(int col) {
  cnt[col].clear();
  for (auto i = col*C; i < col*(C+1); ++i) {
    if (cnt[col].find(A[i]) == cnt[col].end()) {
      cnt[col][A[i]] = 1;
    } else {
      cnt[col][A[i]]++;
    }
  }
}

void add(int i, ll a) {
  sq[i/C][i%C] += a;
  sq[i/C][i%C] %= M;
  // cerr << "A[" << i << "] = " << sq[i/C][i%C] << endl;
}

ll val(int i) {
  return (sq[i/C][i%C] + added[i/C])%M;
}

void add_kukan(int x, int y, ll k) { // [x, y) に k を足す
  // cerr << x << " " << y << endl;
  int left = x;
  int right = y;
  bool done = false;
  while (left < right && left%C != 0) {
    add(left++, k);
    done = true;
  }
  if (done) {
    make_cnt(left/C - 1);
  }
  done = false;
  while (left < right && right%C != 0) {
    add(--right, k);
  }
  if (done) {
    make_cnt(right/C);
  }
  while (left < right) {
    int col = left/C;
    added[col] += k;
    left += C;
  }
}

int count_kukan(int x, int y) { // [x, y) で M の倍数探す。
  int left = x;
  int right = y;
  int ans = 0;
  while (left < right && left%C != 0) {
    if (val(left++) == 0) ++ans;
  }
  while (left < right && right%C != 0) {
    if (val(--right) == 0) ++ans;
  }
  while (left < right) {
    int col = left/C;
    int t = (M - added[col])%M;
    if (cnt[col].find(t) != cnt[col].end()) {
      ans += cnt[col][t];
    }
    left += C;
  }
  return ans;
}

int main () {
  cin >> N >> M >> Q;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] %= M;
  }
  for (auto i = 0; i < Q; ++i) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--;
    r[i]--;
  }
  fill(&sq[0][0], &sq[0][0]+C*C, 0);
  fill(added, added+C, 0);
  for (auto i = 0; i < N; ++i) {
    add(i, A[i]);
  }
  for (auto i = 0; i < N/C; ++i) {
    make_cnt(i);
  }
  for (auto i = 0; i < Q; ++i) {
    add_kukan(l[i], r[i]+1, d[i]);
    cout << count_kukan(l[i], r[i]+1) << endl;
  }
}
