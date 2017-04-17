#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  int k[3];
  cin >> k[0] >> k[1] >> k[2];
  sort(k, k+3);
  reverse(k, k+3);
  int i = 0;
  while (N > 0) {
    N -= k[(i++)%3];
  }
  cout << i << endl;
}
