#include <iostream>
#include <string>
using namespace std;

string S[100010];
int P[100010];

int main() {
  int N;
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> S[i] >> P[i];
  }
  int sum = 0;
  int ind;
  int maxi = 0;
  for (auto i = 0; i < N; i++) {
    sum += P[i];
    if (maxi < P[i]) {
      ind = i;
      maxi = P[i];
    }
  }
  if (maxi > sum/2) {
    cout << S[ind] << endl;
  } else {
    cout << "atcoder" << endl;
  }
}
