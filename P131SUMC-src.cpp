#include <iostream>
#include <math.h>
using namespace std;
long res; 
double a, b, c, d, s, smax = 0;
main()
{
	cin >> a >> b >> c >> d;
	for (long i = 0; i < 4; i++)
	{
		s = (double) (fabs( a / c - b / d));
		if (s > smax)
		{
			smax = s;
			res = i;
		}
		long a1 = a, b1 = b, c1 = c, d1 = d;
		b = a1; d = b1; c = d1; a = c1;
	}
	cout << res;
}