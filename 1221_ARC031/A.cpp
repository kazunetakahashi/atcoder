#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string S;
  cin >> S;
  string T = S;
  reverse(S.begin(), S.end());
  cout << ( (T == S) ? "YES" : "NO" ) << endl;
}
