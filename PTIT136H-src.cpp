#include <iostream>
using namespace std;
long n, a[101], dem;

void swap(long &a, long &b)
{
	long tg = a;
	a = b;
	b = tg;
}

main()
{
	long vt;
	cin >> n;
	for (long i = 1; i <= n; i++) cin >> a[i];
	long d = 1, c = n;
	while (d <= c)
	{
		if (a[d] == d)
		{
			cout << 0 << endl;
			d++;
		}
		else
		{
			dem = 0;
			for (long i = d + 1; i <= n; i++)
			  if (a[i] == d)
			  {
			  	vt = i;
			  	break;
			  }
			for (long i = vt; i > d; i--)
			{
				swap(a[i], a[i - 1]);
				dem++;
			}
			cout << dem << endl;
			d++;
		}
		
		if (d > c) break;
		if (a[c] == c)
		{
			cout << 0 << endl;
			c--;
		}
		else
		{
			dem = 0;
			for (long i = c - 1; i >= 1; i--)
			  if (a[i] == c)
			  {
			  	vt = i;
			  	break;
			  }
			for (long i = vt; i < c; i++)
			{
				swap(a[i], a[i + 1]);
				dem++;
			}
			cout << dem << endl;
			c--;
		}
	}
}