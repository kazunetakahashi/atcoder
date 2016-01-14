#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string S;
  cin >> S;
  string S1 = S.substr(0, 4);
  string S2 = S.substr(5, 2) + S.substr(8, 2);
  sort(S1.begin(), S1.end());
  sort(S2.begin(), S2.end());
  if (S1 == S2) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}
