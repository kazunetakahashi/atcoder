#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  if (s.size() != t.size()) {
    cout << "-1" << endl;
    return 0;
  }
  int n = s.size();
  for (auto i=0; i<=n; i++) {
    if (s == t) {
      cout << i << endl;
      return 0;
    }
    s = s.substr(n-1, 1) + s.substr(0, n-1);
    // cerr << s << endl;
  }
  cout << "-1" << endl;
  return 0;
}
