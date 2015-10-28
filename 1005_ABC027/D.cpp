#include <iostream>
#include <string>
using namespace std;

int X[1010][2020];
const int C = 1010;
const int infty = -1 * (1 << 30);

int main() {
  string S;
  cin >> S;
  if (S.size() > 1000) return 0; // 部分点
  fill(&X[0][0], &X[0][0]+1010*2020, infty);
  X[0][C] = 0;
  for (unsigned t=0; t<S.size(); t++) {
    /*
    for (auto i=0; i<2020; i++) {
      if (X[t][i] != infty) {
        cerr << "X[" << t << "][" << i-C << "] = " << X[t][i] << endl;
      }
    }
    */
    char x = S[t];
    if (x == 'M') {
      for (auto i=1; i<2019; i++) {
        if (X[t][i] != infty) {
          X[t+1][i+1] = max(X[t+1][i+1], X[t][i]);
          X[t+1][i] = max(X[t+1][i], X[t][i]);
          X[t+1][i-1] = max(X[t+1][i-1], X[t][i]);
        }
      }
    } else if (x == '+') {
      for (auto i=0; i<2020; i++) {
        if (X[t][i] != infty) {
          X[t+1][i] = X[t][i] + (i-C);
        }
      }
    } else {
      for (auto i=0; i<2020; i++) {
        if (X[t][i] != infty) {
          X[t+1][i] = X[t][i] - (i-C);
        }
      }
    }
  }
  /*
  for (auto i=0; i<2020; i++) {
    if (X[S.size()][i] != infty) {
      cerr << "X[" << S.size() << "][" << i-C << "] = "
           << X[S.size()][i] << endl;
    }
  }
  */
  cout << X[S.size()][C] << endl;
}
