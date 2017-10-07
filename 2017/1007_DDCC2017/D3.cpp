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

int H, W;
ll A, B;
bool f[210][210];

class state {
public:
  ll ryoho, yobi, tate, yoko, zero;
  bool tate_ni_soroeru;
  void soroeru() {
    if (tate_ni_soroeru) {
      tate = yobi + tate;
      yobi = 0;      
    } else {
      yoko = yobi + yoko;
      yobi = 0;      
    }
  }
  bool tate_taisho() {
    return (zero == 0 && yoko == 0 && yobi == 0);
  }
  bool yoko_taisho() {
    return (zero == 0 && tate == 0 && yobi == 0);
  }
  bool ryoho_taisho() {
    return tate_taisho() && yoko_taisho();
  }
  ll sum() {
    return ryoho + yobi + tate + yoko + zero;
  }
  int next_delete() {
    if (zero > 0) return 4;
    if (tate_ni_soroeru) {
      if (yoko > 0) return 3;
      if (tate > 0) return 2;
      if (ryoho > 0) return 0;
    } else {
      if (tate > 0) return 2;
      if (yoko > 0) return 3;
      if (ryoho > 0) return 0;     
    }
  }
  ll tokuten() {
    int x = next_delete();
    if (x == 0) ryoho--;
    else if (x == 2) tate--;
    else if (x == 3) yoko--;
    else if (x == 4) zero--;
    cerr << "x = " << x << endl;
    if (ryoho_taisho()) {
      cerr << "ryoho" << endl;
      return A + B;
    } else if (tate_taisho()) {
      cerr << "tate" << endl;
      return A;
    } else if (yoko_taisho()) {
      cerr << "yoko" << endl;
      return B;
    }
    return 0;
  }
  ll ans() {
    ll ret = 0;
    while (sum() > 0) {
      ret += tokuten();
    }
    return ret;
  }
};

ll solve() {
  bool x[110][110][4];
  for (auto i = 1; i < H/2+1; ++i) {
    for (auto j = 1; j < W/2+1; ++j) {
      x[i][j][0] = f[i-1][j-1];
      x[i][j][1] = f[H-1-i+1][j-1];
      x[i][j][2] = f[i-1][W-1-j+1];
      x[i][j][3] = f[H-1-i+1][W-1-j+1];
    }
  }
  for (auto k = 0; k < 4; ++k) {
    cerr << "k = " << k << endl;
    for (auto i = 1; i < H/2+1; ++i) {
      for (auto j = 1; j < W/2+1; ++j) {
        cerr << (x[i][j][k] ? 'S' : '.');
      }
      cerr << endl;
    }
  }
  ll tryoho = 0;
  ll tyobi = 0;
  ll ttate = 0;
  ll tyoko = 0;
  ll tzero = 0;
  for (auto i = 1; i < H/2+1; ++i) {
    for (auto j = 1; j < W/2+1; ++j) {
      int cnt = 0;
      for (auto k = 0; k < 4; ++k) {
        if (x[i][j][k]) cnt++;
      }
      if (cnt == 4) tryoho++;
      else if (cnt == 3) tyobi++;
      else if (cnt == 2) {
        if (x[i][j][0] == x[i][j][1] && x[i][j][2] == x[i][j][3]) {
          ttate++;
        } else if (x[i][j][0] == x[i][j][2] && x[i][j][1] == x[i][j][3]) {
          tyoko++;
        } else {
          tzero++;
        }
      } else {
        tzero++;
      }
    }
  }
  state S;
  S.ryoho = tryoho;
  S.yobi = tyobi;
  S.tate = ttate;
  S.yoko = tyoko;
  S.zero = tzero;
  S.tate_ni_soroeru = true;
  state T;
  T = S;
  T.tate_ni_soroeru = false;
  S.soroeru();
  T.soroeru();
  return max(S.ans(), T.ans());
}

int main () {
  cin >> H >> W >> A >> B;
  string m[210];
  for (auto i = 0; i < H; ++i) {
    cin >> m[i];
  }
  fill(&f[0][0], &f[0][0]+210*210, false);
  for (auto i = 0; i < H; ++i) {
    for (auto j = 0; j < W; ++j) {
      f[i][j] = (m[i][j] == 'S');
    }
  }
  ll ans = solve();
  cout << ans << endl;
}
