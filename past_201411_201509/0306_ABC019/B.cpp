#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  string S, T;
  cin >> S;
  char x = '0';
  int c = 1;
  for (auto i=0; i<S.size(); i++) {
    if (S[i] == x) {
      c++;
    } else {
      if (x != '0') {
        T += x;
        T += to_string(c);
      }
      x = S[i];
      c = 1;
    }
  }
  T += x;
  T += to_string(c);
  cout << T << endl;
}
