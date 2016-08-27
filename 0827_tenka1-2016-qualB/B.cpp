#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

string rep(string S) {
  reverse(S.begin(), S.end());
  for (auto it = S.begin(); it != S.end(); it++) {
    if (*it == '(') {
      *it = ')';
    } else {
      *it = '(';
    }
  }
  return S;
}

int main() {
  string S;
  cin >> S;
  int M = S.size();
  S = rep(S);
  string T = S;
  int ans = 100000000;
  for (auto i = 0; i < M; i++) {
    S = T;
    int cost = (M-1) - i;
    int cnt = 0;
    int right = 0;
    int left = 0;
    int nowright = 0;
    int nowleft = 0;
    int ok = false;
    for (auto j = 0; j < i; j++) {
      if (S[j] == ')') {
        if (right <= left) {
          goto EXIT;
        }
        left++;
      } else {
        right++;
      }
    }
    if (right - left > M-i) {
      goto EXIT;
    }
    nowleft = left;
    nowright = right;
    while (!ok) {
      ok = true;
      left = nowleft;
      right = nowright;
      for (auto j = i; j < M; j++) {
        if (S[j] == ')') {
          if (right <= left) {
            ok = false;
            for (auto k = i; k < M; k++) {
              if (S[k] == ')') {
                S[k] = '(';
                cnt++;
                goto EXIT2;
              }
            }
          }
          left++;
        } else {          
          right++;
        }
      }
      if (left != right) {
        ok = false;
        for (auto k = M-1; k >= i; k--) {
          if (S[k] == '(') {
            S[k] = ')';
            cnt++;
            goto EXIT2;
          }
        }
      }
    EXIT2:
      continue;
    }
    // cerr << cnt + cost << " : " << rep(S) << endl;
    ans = min(ans, cnt+cost);
  EXIT:
    continue;
  }
  cout << ans << endl;
}
