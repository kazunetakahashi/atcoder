#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int string_to_sum(string S)
{
  int sum = 0;
  for (auto var : S)
  {
    sum += var - '0';
  }
  return sum;
}

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  int ans = 0;
  for (auto i = 1; i < N; i++)
  {
    int s = string_to_sum(to_string(i));
    if (A <= s && s <= B)
    {
      ans += i;
    }
  }
  cout << ans << endl;
}