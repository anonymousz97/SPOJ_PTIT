#include <iostream>
using namespace std;
long gach[1000002], a[1000001], n, res, d, t;
main()
{
	cin >> t;
	for (long q = 0; q < t; q++)
	{
		cin >> n;
		long amax = -1;
		for (long i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] > amax) amax = a[i];
		}
		for (long i = 0; i <= amax + 1; i++) gach[i] = 0;
		a[n + 1] = amax + 1;
		res = 0;
		for (long k = 1; k <= n; k++)
		  {
		  	gach[a[k]] = 1;
		  	d = 1; long x = a[1];
		  	for (long i = 2; i <= n + 1; i++)
		  	  if (gach[a[i]] == 0)
		  	  {
		  	  	if (a[i] == x) d++;
		  	  	else
		  	  	{
		  	  		if (res < d) res = d;
		  	  		x = a[i];
		  	  		d = 1;
		  	  	}
		  	  }
		  	gach[a[k]] = 0;
		  }
		cout << res << endl;
	}
}