#include <iostream>
using namespace std;
long xa, xb, xc, ya, yb, yc, t;
long a, b, c;

long det( long xa, long ya, long xm, long ym, long xc, long yc)
{
	long xam = xm - xa;
	long yam = ym - ya;
	
	long xac = xc - xa;
	long yac = yc - ya;
	
	return (xam * yac - yam * xac);
}

long kiemTra(long xm, long ym)
{
	a = det(xa, ya, xm, ym, xc, yc);
	b = det(xb, yb, xm, ym, xa, ya);
	c = det(xc, yc, xm, ym, xb, yb);
	if ((a > 0) && (b > 0) && (c > 0)) return 1;
	if ((a < 0) && (b < 0) && (c < 0)) return 1;
	return 0;
}
main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> xa >> ya >> xb >> yb >> xc >> yc;
		long res = 0;
		for (long xm = -500; xm <= 500; xm++)
		  for (long ym = -500; ym <= 500; ym++)
		    if (kiemTra(xm, ym)) res++;
		cout << res << endl;
	}
}