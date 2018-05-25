#include <iostream>
using namespace std;

void push(long st[], long &t, long x)
{
	t++;
	st[t] = x;
}

long xuli(long n, long a[])
{
	long lim = 1;
	while (lim < n)
	{
		long b[300], t = 0;
		for (long i = 1; i <= lim; i++)
		{
			long tong = a[i], hieu = a[i + lim];
			push(b, t, (tong + hieu)/ 2);
			push(b, t, (tong - b[t]));
		}
		for (long i = 1; i <= 2 * lim; i++) a[i] = b[i];
		lim *= 2;		
	}	
}

main()
{
	long n;
	while ((cin >> n) && (n != 0))
	{
		long a[300];
		for (long i = 1; i <= n; i++) cin >> a[i];
		xuli(n, a);
		for (long i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
}