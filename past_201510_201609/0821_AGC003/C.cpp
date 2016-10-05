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
#include <cassert>
using namespace std;

typedef long long ll;

ll A[100010];
vector<int> V;
map<int, int> M;

int main() {
  int N;
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
    V.push_back(A[i]);
  }
  sort(V.begin(), V.end());
  for (auto i = 0; i < (int)V.size(); i++) {
    M[V[i]] = i;
  }
  for (auto i = 0; i < N; i++) {
    A[i] = M[A[i]];
  }
  int wrong[2];
  wrong[0] = wrong[1] = 0;
  for (auto i = 0; i < N; i++) {
    if (i % 2 != A[i] % 2) {
      wrong[i%2]++;
    }
  }
  assert(wrong[0] == wrong[1]);
  cout << wrong[0] << endl;
}
