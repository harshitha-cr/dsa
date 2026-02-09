/*
Calculate x ^ n
where x - float
n - integers
*/

#include <iostream>
#include <vector>
// #include <cmath>
using namespace std;

double myPow(double x, int n)
{
  if (n == 1)
    return x;
  if (n == 0)
    return 1;

  double temp = myPow(x, n / 2);
  if (n % 2 == 1)
  {
    return temp * temp * x;
  }
  else
  {
    return temp * temp;
  }
}

int main()
{
  double x;
  cin >> x;
  int n;
  cin >> n;
  // cout << pow(x, n);
  return 0;
}