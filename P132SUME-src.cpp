#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
long n, res;
float  xa, ya, xb, yb, xc, yc, xm, ym;

long det( float xa, float ya, float xm, float ym, float xc, float yc)
{
	float xam = xm - xa;
	float yam = ym - ya;
	
	float xac = xc - xa;
	float yac = yc - ya;
	
	return (xam * yac - yam * xac);
}

long kiemTra(float xm, float ym)
{
	float a, b ,c;
	a = det(xa, ya, xm, ym, xc, yc);
	b = det(xb, yb, xm, ym, xa, ya);
	c = det(xc, yc, xm, ym, xb, yb);
	if ((a >= 0) && (b >= 0) && (c >= 0)) return 1;
	if ((a <= 0) && (b <= 0) && (c <= 0)) return 1;
	return 0;
}

float dodai(float xa, float ya, float xb, float yb)
{
	return (sqrt((xa -xb) * (xa - xb) + (ya - yb) * (ya - yb)));
}

float dientich()
{
	float a = dodai(xa, ya, xb, yb),
		  b = dodai(xb, yb, xc, yc),
		  c = dodai(xa, ya, xc, yc);
	float p = (a + b + c) / 2;
	float s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

main()
{
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	res = 0;
	cin >> n;
	for (long i = 1; i <= n; i++)
	{
		cin >> xm >> ym;
		if (kiemTra(xm, ym)) res++;
	}
	printf("%0.1f\n", dientich());
	cout << res;
}