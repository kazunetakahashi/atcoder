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

using namespace std;
typedef long long ll;

bool ok() {
  int ht, mt, hn, mn;
  cin >> ht >> mt >> hn >> mn;
  if (hn < ht) {
    return true;
  } else if ((hn == ht) && (mn <= mt)) {
    return true;
  } else {
    if (hn < 6) {
      hn = 6;
      mn = 30;
    } else if (mn < 30) {
      mn = 30;
    }
    hn = (hn+6)%12;
    mn = (mn+30)%60;
    if (hn < ht) {
      return true;
    } else if ((hn == ht) && (mn <= mt)) {
      return true;
    } else {
      return false;
    }
  }
}

int main() {
  cout << (ok() ? "Yes" : "No") << endl;
}
