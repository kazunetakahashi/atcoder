#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  string ans = "";
  while (cin >> S) {
    if (S == "Left") {
      ans += "< ";
    } else if (S == "Right") {
      ans += "> ";
    } else {
      ans += "A ";
    }
  }
  ans.erase(ans.end()-1);
  cout << ans << endl;
}
