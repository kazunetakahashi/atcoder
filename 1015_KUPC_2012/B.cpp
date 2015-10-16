#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S[0] == 'x' && S[S.size()-1] == 'x') {
    cout << "x" << endl;
  } else {
    cout << "o" << endl;
  }
}
