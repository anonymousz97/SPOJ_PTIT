#include <iostream>
using namespace std;
long n, a[100001], b[100001];
long res, mark;

long daiNhat(long k)
{
	long d = 0, dmax = 0;
	for (long i = 1; i <= n; i++)
	  if ((a[i] == k) || (b[i] == k))
	  {
	  	d++;
	  	if (i == n) 
	  	{
	  		if (d > dmax) dmax = d;
	  	}
	  }
	  else
	  {
	  	if (d > dmax) dmax = d;
	  	d = 0;
	  }	
	return dmax;
}

main()
{
	cin >> n;
	for (long i = 1; i <= n; i++) cin >> a[i] >> b[i];
	long res = 0;
	for (long i = 1; i <= 5; i++)
	{
		long d = daiNhat(i);
		if (d > res)
		{
			res = d;
			mark = i;
		}
	}
	cout << res << " " << mark;
}