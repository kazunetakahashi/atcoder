#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;
int bunpu[1000010];

int main() {
  cin >> N;
  fill(bunpu, bunpu+1000010, 0);
  for (auto i=0; i<N; i++) {
    int n;
    cin >> n;
    bunpu[n]++;
  }
  bunpu[0] = 0;
  for (auto i=1000009; i>0; i--) {
    bunpu[i-1] += bunpu[i];
  }
  cin >> Q;
  for (auto i=0; i<Q; i++) {
    int border;
    cin >> border;
    int ub = 1000010, lb = -1;
    while (ub - lb > 1) {
      int now = (ub + lb) / 2;
      if (bunpu[now] > border) {
        lb = now;
      } else {
        ub = now;
      }
    }
    cout << ub << endl;
  }
}
