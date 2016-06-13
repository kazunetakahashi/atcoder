#include <iostream>
using namespace std;

int main() {
  int W, H;
  cin >> W >> H;
  cout << ((3*W == 4*H) ? "4:3" : "16:9") << endl;
}
