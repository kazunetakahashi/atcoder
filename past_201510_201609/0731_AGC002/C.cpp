#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
int N;
ll L;
ll a[100010];
 
int main() {
  cin >> N >> L;
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  int ind = -1;
  for (auto i = 0; i < N-1; i++) {
    if (a[i] + a[i+1] >= L) {
      ind = i;
      break;
    }
  }
  if (ind == -1) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (auto i = 0; i < ind; i++) {
    cout << i+1 << endl;
  }
  for (auto i = N-2; i > ind; i--) {
    cout << i+1 << endl;
  }
  cout << ind+1 << endl;
}

