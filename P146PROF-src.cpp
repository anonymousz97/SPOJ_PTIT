#include <iostream>
#include <math.h>
using namespace std;
long a[5];
long res = 0;

long tamGiac(long a, long b, long c)
{
	if ((a + b > c) && (fabs(a - b) < c)) return 1;
	return 0;
}

long doanThang(long a, long b, long c)
{
	if (a + b == c) return 1;
	if (a + c == b) return 1;
	if (b + c == a) return 1;
	return 0;
}
long xuli()
{
	for (long i = 1; i <= 2; i++)
	  for (long j = i + 1; j <= 3; j++)
	    for (long k = j + 1; k <= 4; k++)
		{
			if (tamGiac(a[i], a[j], a[k]))
			{
				res = 1;
				return 0;
			}
			if (!res) 
			{
				if (doanThang(a[i], a[j], a[k])) res = 2;
			}
		}	
}

main()
{
	cin >> a[1] >> a[2] >> a[3] >> a[4];
	xuli();
	if (res == 1) cout << "TRIANGLE";
	else if (res == 2) cout << "SEGMENT";
	else cout << "IMPOSSIBLE";
}