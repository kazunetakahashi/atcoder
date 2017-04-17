#include <iostream>
#include <string>
using namespace std;

string P[10010], Q[10010], R[10010];

int main() {
  int N;
  cin >> N;
  string ans = "";
  for (auto i = 0; i < N; i++) {
    cin >> P[i] >> Q[i] >> R[i];
  }
  for (auto i = 0; i < N; i++) {
    if (P[i] == "BEGINNING") {
      ans += R[i][0];
    } else if (P[i] == "MIDDLE") {
      ans += R[i][R[i].size()/2];
    } else {
      ans += R[i][R[i].size()-1];
    }
  }
  cout << ans << endl;
}
