#include <iostream>
using namespace std;
long d1, d2, d3;
long m, n, k, t;
void dem()
{
	for (long x = 100000; x <= 999999; x++)
	{
		long m = x, s = 0, sum = 0, c1 = 1;
		while (m != 0)
		{
			long cs = m % 10;
			sum += cs;
			s = s * 10 + cs;
			if (cs == 0) c1 = 0;
			m = m / 10;	
		}	
		if (s == x) 
		{
			d3++;
			if (sum % 10 == 0)
			{
				d2++;
				if (c1) d1++;
			}
		}
	}
}

int kiemtra(long d1, long d2, long d3)
{
	if (d1 < n) return 0;
	d2 -= n; d3 -= n;
	if (d2 < m) return 0;
	d3 -= m;
	if (d3 < k) return 0;
	return 1;
}
main()
{
	d1 = 0; d2 = 0; d3 = 0;
	dem();
	//cout << d1 << " " << d2 << " " << d3 << endl;
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n >> m >> k;
		if (kiemtra(d1, d2, d3)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}