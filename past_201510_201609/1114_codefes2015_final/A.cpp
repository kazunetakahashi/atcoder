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

int main() {
  string S, T, U;
  cin >> S >> T >> U;
  if (S.size() == 5 && T.size() == 7 && U.size() == 5) {
    cout << "valid" << endl;
  } else {
    cout << "invalid" << endl;
  }
}
