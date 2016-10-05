#include <iostream>
#include <string>
using namespace std;

int main() {
  string S, T;
  cin >> S;
  while (true) {
    auto x = S.find("oookayama", 0);
    if (x == string::npos) {
      break;
    }
    auto y = x+9;
    while (x > 0 && S[x-1] == 'o') {
      x--;
    }
    T = S.substr(x, y-x);
    // cerr << "2 : T = " << T << endl;
    while (true) {
      auto z = T.find("oo", 0);
      if (z == string::npos) {
        break;
      } else {
        T = T.substr(0, z) + "O" + T.substr(z+2);
        // cerr << "3 : T = " << T << endl;
      }
      auto w = T.find("OO", 0);
      if (w == string::npos) {
        continue;
      } else {
        T = T.substr(0, w) + "o" + T.substr(w+2);
        // cerr << "4 : T = " << T << endl;
      }
    }
    S = S.substr(0, x) + T + S.substr(y);
    // cerr << "end. 4 : S = " << S << endl;
  }
  cout << S << endl;
}
