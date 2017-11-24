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

int N, M;
int X[100010];
int cnt[100010];
int mod[100010][2];

int get_cnt(int x) {
  return mod[x][0] + 2 * mod[x][1];
}

int same(int x) {
  int c = get_cnt(x);
  return c/2;
}

int odd(int x) {
  int c = get_cnt(x);
  int d = get_cnt(M - x);
  if (c < d) {
    swap(c, d);
    x = M - x;
  }
  int ans = d;
  if (d <= mod[x][0]) {
    ans += mod[x][1];
    return ans;
  } else {
    ans += (mod[x][1] * 2 - (d - mod[x][0]))/2;
    return ans;
  }
}

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; ++i) {
    cin >> X[i];
  }
  fill(cnt, cnt+100010, 0);
  for (auto i = 0; i < N; ++i) {
    cnt[X[i]]++;
  }
  fill(&mod[0][0], &mod[0][0]+100010*2, 0);
  for (auto i = 0; i < 100010; ++i) {
    mod[i%M][0] += cnt[i]%2;
    mod[i%M][1] += cnt[i]/2;
  }
  int ans = 0;
  ans += same(0);
  for (auto i = 1; i < M/2; ++i) {
    ans += odd(i);
  }
  if (M%2 == 0) {
    ans += same(M/2);
  } else {
    ans += odd(M/2);
  }
  cout << ans << endl;
}
