#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
using namespace std;

int main() {
  int n;
  int x;
  cin >> n >> x;
  cout << min(n-x, x-1) << endl;
}
