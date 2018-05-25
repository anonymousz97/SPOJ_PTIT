#include <iostream>
#include <math.h>
using namespace std;

long a, b, c, d;
main()
{
	cin >> a >> b >> c >> d;
	while (a != 0)
	{
		long res = 0;
		while (not ((a == b) && (b == c) && (c == d)))
		{
			res ++;
			long e = a;
			a =	fabs(a - b);
			b = fabs(b - c);
			c = fabs(c - d);
			d = fabs(d - e);
		//	cout << res << " " << a << " " << b << " " << c << " " << d << endl;
		}
		cout << res << endl;
		cin >> a >> b >> c >> d;
	}
}