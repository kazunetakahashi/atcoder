#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>
#include <cassert>

using namespace std;
typedef long long ll;

int calc(string S, int x) {
  reverse(S.begin(), S.end());
  for (auto c : S) {
    if (c == '-') {
      x = -x;
    } else {
      if (x == 0) {
        x = -1;
      } else {
        x = 0;
      }
    }
  }
  return x;
}

string S;
string K[100] = {
  "!", "-!", "!-", "!!", "-!-", "-!!", "!-!", "!!-",
  "-!-!", "-!!-", "!-!-", "-!-!-"
};

string ans() {
  int X = calc(S, 2);
  if (X == 2) {
    return "";
  } else if (X == -2) {
    return "-";
  } else {
    for (auto i=0; ; i++) {
      string T = K[i];
      for (int i=-2; i<=2; i++) {
        if (calc(T, i) != calc(S, i)) {
          goto EXIT;
        }
      }
      return T;
    EXIT:
      continue;
    }
  }
  assert(false);
  cout << "0" << endl;
}

int main() {
  cin >> S;
  cout << ans() << endl;
}
