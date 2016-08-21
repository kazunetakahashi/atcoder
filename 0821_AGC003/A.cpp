#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long ll;

int c(char x) {
  if (x == 'N') return 0;
  if (x == 'W') return 1;
  if (x == 'S') return 2;
  return 3;
}

int main() {
  string S;
  cin >> S;
  int cnt[4];
  fill(cnt, cnt+4, 0);
  for (auto x : S) {
    cnt[c(x)]++;
  }
  for (auto i = 0; i < 4; i++) {
    if (cnt[i] == 0 && cnt[(i+2)%4] > 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
