#include <iostream>
using namespace std;
long n, a[100001], t1, t2, d1, d2;
main()
{
	cin >> n;
	long s = 0;
	for (long i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	d1 = 0; d2 = 0;
	t1 = s / 2;
	long i = 1;
	while ( t1 - a[i] >= 0)
	{
	 t1 -= a[i++];
	 d1++;
	}
	
	t2 = s / 2;
	long j = n;
	while ( t2 - a[j] >= 0)
	{
		 t2 -= a[j--];
		 d2++;
	}
	
	if (t1 > t2) d1++;
	else if (t1 < t2) d2++;
	else
		if (i == j) d1++;
	
	cout << d1 << " " << d2;
}