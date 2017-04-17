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
  string S = "314159265358979323846264338327950";
  int N;
  cin >> N;
  for (unsigned i=0; i<S.size(); i++) {
    if (N == (S[i]-'0')) {
      cout << i << endl;
      return 0;
    }
  }
}
