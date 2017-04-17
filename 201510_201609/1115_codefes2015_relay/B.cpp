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
  string S[10];
  for (auto i=0; i<10; i++) {
    cin >> S[i];
  }
  for (auto i=0; i<10; i++) {
    for (auto j=0; j<10; j++) {
      if (S[j][i] == 'o') goto EXIT;
    }
    cout << "No" << endl;
    return 0;
  EXIT:
    continue;
  }
  cout << "Yes" << endl;
}
