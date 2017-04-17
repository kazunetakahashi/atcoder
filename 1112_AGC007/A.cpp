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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;
 
typedef long long ll;
 
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
 
// const int C ;
// const int M = 1000000007;
 
int H, W;
string A[8];
bool F[8][8];
int S;
bool X[8][8];
 
bool dfs(vector<bool> V) {
  if ((int)V.size() == S) {
    fill(&X[0][0], &X[0][0]+64, false);
    X[0][0] = true;
    int nowx = 0;
    int nowy = 0;
    for (auto x : V) {
      if (x) {
        nowx++;
      } else {
        nowy++;
      }
      X[nowx][nowy] = true;
    }
    for (auto i = 0; i < H; i++) {
      for (auto j = 0; j < W; j++) {
        if (F[i][j] && !X[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
  bool res = false;
  V.push_back(true);
  res = (res || dfs(V));
  if (res) return true;
  V[V.size()-1] = false;
  res = (res || dfs(V));
  return res;
}
 
int main () {
  cin >> H >> W;
  for (auto i = 0; i < H; i++) {
    cin >> A[i];
  }
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      F[i][j] = (A[i][j] == '#');
    }
  }
  S = H+W-2;
  vector<bool> V;
  cout << (dfs(V) ? "Possible" : "Impossible") << endl;
}
