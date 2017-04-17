#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<int, int, int> people;
typedef tuple<int, int, int, int> record;


int V[100010][3];
int W[100010];
people X[100010];
vector<record> U;


int main() {
  int N;
  cin >> N;
  fill(&V[0][0], &V[0][0]+100010*3, 0);
  fill(W, W+100010, 0);
  for (auto i = 0; i < N; i++) {
    int R, H;
    cin >> R >> H;
    H--;
    W[R]++;
    V[R][H]++;
    X[i] = make_tuple(R, H, i);
  }
  sort(X, X+N);
  people* p = X;
  int rate = 0;
  int lose_rate = 0;
  while (p < X+N) {
    int r = get<0>(*p);
    int h = get<1>(*p);
    int ind = get<2>(*p);
    while (rate < r) {
      lose_rate += W[rate++];      
    }
    int lose = lose_rate + V[r][(h+1)%3];
    int draw = V[r][h] - 1;
    int win = N-1 - lose - draw;
    U.push_back(make_tuple(ind, lose, win, draw));
    p++;
  }
  sort(U.begin(), U.end());
  for (auto x : U) {
    cout << get<1>(x) << " "
         << get<2>(x) << " "
         << get<3>(x) << endl;
  }
}
