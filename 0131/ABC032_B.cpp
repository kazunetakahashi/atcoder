#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  if (k > (int)s.size()) {
    cout << 0 << endl;
    return 0;
  }
  set<string> S;
  for (auto i = 0; i < (int)s.size(); i++) {
    string T = s.substr(i, k);
    if ((int)T.size() == k) {
      S.insert(T);
    }
  }
  cout << S.size() << endl;
}
