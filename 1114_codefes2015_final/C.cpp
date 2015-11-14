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
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ind = 0;
  int amari[2] = {0, 0};
  int ans = 0;
  while (ind < 2*N) {
    if (ind+1 < 2*N &&
        ((S[ind] == '0' && S[ind+1] == '1') ||
         (S[ind] == '1' && S[ind+1] == '0'))) {
      ind += 2;
    } else if (amari[S[ind] - '0'] > 0) {
      amari[S[ind] - '0']--;
      ind++;
    } else {
      ans++;
      amari[0]++;
      amari[1]++;
      amari[S[ind] - '0']--;
      ind++;
    }
  }
  cout << ans << endl;
}
