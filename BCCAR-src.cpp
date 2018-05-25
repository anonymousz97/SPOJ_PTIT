#include <iostream>
using namespace std;
long n, t, x, res, xmin, xmax;
main()
{
  cin >> t;
  for (long q = 1; q <= t; q++)
  {
    xmin = 100; 
    xmax = -1;
    cin >> n;
    for (long i = 1; i <= n; i++)
       {
          cin >> x;
          if (x > xmax) xmax = x;
          if (x < xmin) xmin = x;
       }
    res = (xmax - xmin) * 2;
    cout << res << endl;
  }
}