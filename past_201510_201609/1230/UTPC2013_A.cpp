#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  string one = "ADOPQR";
  for (auto it = S.begin(); it != S.end(); it++) {
    if (*it == 'B') {
      *it = '2';
    } else if (one.find(*it) != string::npos) {
      *it = '1';
    } else {
      *it = '0';
    }
  }
  if (S == "0010") {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}
