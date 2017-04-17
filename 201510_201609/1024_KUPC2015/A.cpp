#include <iostream>
#include <string>
using namespace std;

int solve(string S) {
  for (int i=0; i<(int)S.size()-4; i++) {
    string s = S.substr(i, 5);
    // cerr << s << endl;
    if (s == "kyoto" || s == "tokyo") {
      return solve(S.substr(i+5)) + 1;
    }
  }
  return 0;
}

int main() {
  int T;
  cin >> T;
  for (auto i=0; i<T; i++) {
    string S;
    cin >> S;
    cout << solve(S) << endl;;
  }
}
