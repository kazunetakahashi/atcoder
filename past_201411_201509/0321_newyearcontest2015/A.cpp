#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S = "";
  for (auto i=0; i<32; i++) {
    if ((N >> i) == 0) break;
    if (((N >> i) & 1) == 1) {
      S += "1";
    } else {
      S += "0";
    }
  }
  string T = S;
  reverse(S.begin(), S.end());
  // cerr << S << endl;
  // cerr << T << endl;
  cout << ((S == T) ? "YES" : "NO") << endl;
}
