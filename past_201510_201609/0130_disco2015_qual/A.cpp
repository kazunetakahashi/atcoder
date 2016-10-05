#include <iostream>
#include <string>
using namespace std;

int main() {
  string S = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
  int W;
  cin >> W;
  int ind = 0;
  while (ind < (int)S.size()) {
    cout << S.substr(ind, W) << endl;
    ind += W;
  }
}
