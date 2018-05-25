#include <iostream>
using namespace std;
long n, xmin, xmax, res = -1;
typedef pair<long, long> record;
record x[101];
main()
{
cin >> n;
xmin = 1000000001;
xmax = 0;
for (long i = 1; i <= n; i++)
{
cin >> x[i].first >> x[i].second;
if (x[i].first < xmin) xmin = x[i].first;
if (x[i].second > xmax) xmax = x[i].second;
}
for (long i = 1; i <= n; i++)
  if ((x[i].first == xmin) && (x[i].second == xmax)) 
{
res = i;
break;
}
cout << res;
}
