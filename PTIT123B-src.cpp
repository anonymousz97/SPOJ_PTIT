#include <iostream>
#include <math.h>
using namespace std;
long t, n, a[101], d;
main()
{
	cin >> n; t = 0;
	while (n != 0)
	{
		t++;
		long c = 1;
		cin >> a[1];
		for (long i = 2; i <= n; i++)
		  {
		  	cin >> a[i];
		  	if ((c) && (a[i] != a[i - 1])) c = 0;
		  }
		if (c) cout << "Case " << t << ": " << "0 iterations" << endl;
		else
		{
			d = 1;
			while (d <= 1000)
			{
				long ck = 1;
				a[n + 1] = a[1];
				a[1] = fabs(a[1] - a[2]);
				for (long i = 2; i <= n; i++)
				{
					a[i] = fabs(a[i] - a[i + 1]);
					if ((ck) && (a[i] != a[i - 1])) ck = 0;
				}
				if (ck) break;
				d++;
			}
			if (d == 1001) cout << "Case " << t << ": " << "not attained" << endl;
			else
						   cout << "Case " << t << ": " << d << " iterations" << endl;
		}
		cin >> n;
	}
}