#include <iostream>
using namespace std;
long res, n;
main()
{
cin >> n;
res = 0;
for (long i = 0; i <= n; i++)
  for (long j = i; j <= n; j++) res += (i + j);
cout << res;
}
