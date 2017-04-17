#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string S;
vector<string> V;

string make(int n) {
  string A = "";
  for (auto i = 0; i < n; i++) {
    A += "x";
  }
  for (auto i = 0; i < 6; i++) {
    A += S;
  }
  return A;
}

bool ok() {
  /*
  cerr << "now : " << endl;
  for (auto x : V) {
    cerr << x << endl;
  }
  */
  bool X[100];
  int l = 0;
  fill(X, X+100, false);
  for (auto x : V) {
    l = max(l, (int)x.size());
    for (auto i = 0; i < (int)x.size(); i++) {
      X[i] = X[i] || x[i] == 'o';
    }
  }
  int start = (int)S.size();
  /*
  while (S[start] == 'x') {
    start++;
  }
  */
  l = min(l, (int)S.size() * 4);
  for (auto i = start; i < l; i++) {
    if (!X[i]) {
      //cerr << "failed : " << i << endl;
      return false;
    }
  }
  return true;
}

const int infty = 10000;

int main() {
  cin >> S;
  int ans = infty;
  for (auto i = 1; i < (1 << (int)S.size()); i++) {
    V.clear();
    for (auto j = 0; j < (int)S.size(); j++) {
      if (((i >> j) & 1) == 1) {
        V.push_back(make(j));
      }
    }
    if (ok()) {
      ans = min((int)V.size(), ans);
      /*
      if ((int)V.size() < 3) {
        cerr << "now : " << endl;
        for (auto x : V) {
          cerr << x << endl;
        }
      }
      */
    }
  }
  cout << ans << endl;
}
