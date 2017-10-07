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
  ll ans = 0;
  ll tnokori = tryoho + tyobi + ttate + tyoko + tzero;
  ll temp = 0;
  // yoko ni soroeru
  ll ryoho = tryoho;
  ll yobi = tyobi;
  ll tate = ttate;
  ll yoko = tyoko;
  ll zero = tzero;
  ll nokori = tnokori;
  while (zero > 0) {
    zero--;
    nokori--;
    if (nokori == 0) temp += A+B;
  }
  while (tate > 0) {
    tate--;
    nokori--;
    if (nokori == 0) temp += A+B;    
  }
  while (yobi > 0) {
    yobi--;
    yoko++;    
  }
  while (yoko > 0) {
    yoko--;
    nokori--;
    temp += B;
    if (nokori == 0) temp += A;
  }
  while (ryoho > 0) {
    ryoho--;
    nokori--;
    temp += A + B + B;    
  }
  ans = max(ans, temp);
  // tate ni soroeru
  ryoho = tryoho;
  yobi = tyobi;
  tate = ttate;
  yoko = tyoko;
  zero = tzero;
  nokori = tnokori;
  while (zero > 0) {
    zero--;
    nokori--;
    if (nokori == 0) temp += A+B;
  }
  while (yoko > 0) {
    yoko--;
    nokori--;
    if (nokori == 0) temp += A+B;    
  }
  while (yobi > 0) {
    yobi--;
    tate++;    
  }
  while (tate > 0) {
    tate--;
    nokori--;
    temp += A;
    if (nokori == 0) temp += B;
  }
  while (ryoho > 0) {
    ryoho--;
    nokori--;
    temp += A + B + A;    
  }
  ans = max(ans, temp);
  return ans;
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
