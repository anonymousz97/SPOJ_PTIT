#include <iostream>
using namespace std;
long n, a[300001], res, pos;
main()
{
	cin >> n;
	for (long i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == n)
		{
			pos = i;
			break;
		}
	}
	long d = 0, k = n;
	for (long i = pos; i >= 1; i--)
	  if (a[i] == k)
	  {
	  	d++;
	  	k--;
	  }
	res = n - d;
	cout << res;
}