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

int N[2];
int bit[2][100010];

void add(int t, int a, int w) {
  for (int x=a; x<=N[t]; x += x & -x) {
    bit[t][x] += w;
  }
}

int sum(int t, int a) {
  int ret = 0;
  for (int x=a; x>0; x -= x & -x) {
    ret += bit[t][x];
  }
  return ret;
}

string S[2];
int q;
int a[2][100010], b[2][100010];

int h(char a) {
  return (a - 'A' + 1);
}

int main () {
  fill(&bit[0][0], &bit[0][0]+2*100010, 0);
  cin >> S[0] >> S[1];
  cin >> q;
  for (auto i = 0; i < q; ++i) {
    cin >> a[0][i] >> b[0][i] >> a[1][i] >> b[1][i];
  }
  for (auto t = 0; t < 2; ++t) {
    N[t] = S[t].size();
    for (auto i = 0; i < N[t]; ++i) {
      // cerr << "S[" << t << "][" << i << "] = " << h(S[t][i]) << endl;
      add(t, i+1, h(S[t][i]));
    }
  }
  for (auto i = 0; i < q; ++i) {
    int score[2] = {0, 0};
    for (auto t = 0; t < 2; ++t) {
      int genten = ((a[t][i] == 1) ? 0 : (sum(t, a[t][i] - 1)));
      int katen = sum(t, b[t][i]);
      score[t] = katen - genten;
    }
    cout << ((score[0]%3 == score[1]%3) ? "YES" : "NO") << endl;
  }
}
