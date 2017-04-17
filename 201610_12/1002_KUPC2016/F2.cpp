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

string S;
unsigned int num = 0;

int number() {
  if (num+1 < S.size() && isdigit(S[num+1])) {
    string T = "";
    T += S[num];
    T += S[num+1];
    int x = atoi(T.c_str());
    num += 2;
    return x;
  } else {
    int x = S[num] - '0';
    num++;
    return x;
  }
}

int expression() {
  if (isdigit(S[num])) {
    return number();
  }
  if (S[num] == '^') {
    num++;
    assert(S[num] == '(');
    num++;
    int x = expression();
    assert(S[num] == ',');
    num++;
    int y = expression();
    assert(S[num] == ')');
    num++;
    return max(x, y);
  } else {
    assert(S[num] == '_');
    num++;
    assert(S[num] == '(');
    num++;
    int x = expression();
    assert(S[num] == ',');
    num++;
    int y = expression();
    assert(S[num] == ')');
    num++;
    return min(x, y);    
  }
}

int statement() {
  int x = expression();
  assert(S[num] == '?');
  num++;
  assert(num == S.size());
  return x;
}

int main () {
  int Q;
  cin >> Q;
  string state[210];
  int ans[210];
  int decide[210];
  for (auto i = 0; i < Q; i++) {
    cin >> state[i];
  }
  for (auto i = 0; i < Q; i++) {
    S = state[i];
    num = 0;
    ans[i] = expression();
    int has = 0;
    int ichi = 0;
    for (auto j = 0; j < (int)(S.size()); j++) {
      if (S[j] == '^' || S[j] == '_') {
        has++;
        ichi = j;
      }
    }
    if (has == 0) {
      if (S[0] == '0') {
        decide[i] = 0;
      } else {
        decide[i] = 1;
      }
    } else {
      if (S[ichi] == '_') {
        if (S.substr(ichi, 3) == "_(0") {
          decide[i] = ichi + 2;
        } else if (S[ichi+3] == ',') {
          int x = S[ichi+2] - '0';
          int z = S[ichi+4] - '0';
          if (x < z) {
            decide[i] = ichi+4;
          } else {
            decide[i] = ichi+5;
          }
        } else {
          decide[i] = ichi + 6;
        }
      } else {
        if (S.substr(ichi, 4) == "^(99") {
          decide[i] = ichi + 3;
        } else if (S[ichi+3] == ',') {
          decide[i] = ichi + 5;
        } else {
          int x = S[ichi+2] - '0';
          int y = S[ichi+3] - '0';
          int z = S[ichi+5] - '0';
          if (y != 9 && x < z) {
            decide[i] = ichi+5;
          } else if (y == 9 && x <= z){
            decide[i] = ichi+5;
          } else {
            decide[i] = ichi+6;
          }
        }        
      }
    }
  }
  for (auto i = 0; i < Q; i++) {
    cout << ans[i] << " " << decide[i]+1 << endl;
  }
}
