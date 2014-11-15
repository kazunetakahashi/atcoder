#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ret = 0;
  for (auto i=0; i<S.size(); i++) {
    if (i%2 == 0) {
      ret += S[i] - '0';
    } else {
      ret -= S[i] - '0';
    }
  }
  cout << ret << endl;
}
