#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> V;

int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  int now = 0;
  for (auto x : S) {
    if (x == '+') {
      now++;
    } else if (x == '-') {
      now--;
    } else {
      V.push_back(now);      
    }
  }
  sort(V.begin(), V.end());
  long long ans = 0;
  for (unsigned i=0; i<V.size()/2; i++) {
    ans -= V[i];
  }
  for (unsigned i=V.size()/2; i<V.size(); i++) {
    ans += V[i];
  }
  cout << ans << endl;
}
