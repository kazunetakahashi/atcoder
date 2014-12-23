#include <iostream>
#include <algorithm>
using namespace std;

// Binary Indexed Tree は
// http://hos.ac/slides/20140319_bit.pdf を参照した。

int N;
int bit[100010];

void add(int a, int w) {
  for (int x=a; x<=N; x += x & -x) {
    bit[x] += w;
  }
}

int sum(int a) {
  int ret = 0;
  for (int x=a; x>0; x -= x & -x) {
    ret += bit[x];
  }
  return ret;
}

int main() {
  cin >> N;
  pair<int, int> B[100010];
  for (auto i=1; i<=N; i++) {
    int b;
    cin >> b;
    B[i] = make_pair(b, i);
  }
  fill(bit, bit+100010, 0);
  for (auto i=1; i<=N; i++) {
    add(i, 1);
  }
  sort(B+1, B+1+N);
  long long ans = 0;
  for (auto i=1; i<=N; i++) {
    int place = B[i].second;
    int left = sum(place-1);
    int right = sum(N) - left - 1;
    ans += min(left, right);
    add(place, -1);
  }
  cout << ans << endl;
}
