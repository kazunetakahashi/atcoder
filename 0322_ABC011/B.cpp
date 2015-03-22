#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  transform(S.begin(), S.end(), S.begin(), ::tolower);
  transform(S.begin(), S.begin()+1, S.begin(), ::toupper);
  cout << S << endl;
}
