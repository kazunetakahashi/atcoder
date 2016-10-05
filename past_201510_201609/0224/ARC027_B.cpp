#include <iostream>
#include <set>
using namespace std;

int moji(char x) {
  if (isupper(x)) {
    return x - 'A' + 10;
  } else {
    return x - '0';
  }
}

const int UFSIZE = 100010;
int union_find[UFSIZE];

void init() {
  for (auto i=0; i<UFSIZE; i++) {
    union_find[i] = i;
  }
}

int root(int a) {
  if (a == union_find[a]) return a;
  return (union_find[a] = root(union_find[a]));
}

bool issame(int a, int b) {
  return root(a) == root(b);
}

void unite(int a, int b) {
  union_find[root(a)] = root(b);
}

bool isroot(int a) {
  return root(a) == a;
}

int main() {
  init();
  int N;
  cin >> N;
  string S[2];
  cin >> S[0] >> S[1];
  for (auto i = 0; i < N; i++) {
    int a = moji(S[0][i]);
    int b = moji(S[1][i]);
    unite(a, b);
  }
  set<int> St;
  bool sento = false;
  for (auto i = 0; i < N; i++) {
    bool ischar = true;
    for (auto j = 0; j < 10; j++) {
      if (issame(j, moji(S[0][i]))) {
        ischar = false;
        break;
      }
    }
    if (ischar) {
      St.insert(root(moji(S[0][i])));
      if (i == 0) {
        sento = true;
      }
    }
  }
  long long ans = 1;
  for (unsigned i = 0; i < St.size(); i++) {
    ans *= (long long)10;
  }
  if (sento) {
    ans = (ans/10)*9;
  }
  cout << ans << endl;
}
