#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  while (S.size() > 0) {
    if (S[0] == 'c' && S[1] == 'h') {
      S = S.substr(2);
    } else if (S[0] == 'o' || S[0] == 'k' || S[0] == 'u') {
      S = S.substr(1);
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
