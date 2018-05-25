#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
long t, n;
double r, x[10001], y[10001];
double f, c;

double kc(double u, double v, double s, double t)
{
	return sqrt((u - s) * (u - s) + (v - t) * (v - t));	
}

double chuVi()
{
	double res = kc(x[1], y[1], x[n], y[n]);
	for (long i = 2; i <= n; i++) res += kc(x[i], y[i], x[i - 1], y[i - 1]);
	return res;	
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> r >> n;
		for (long i = 1; i <= n; i++) cin >> x[i] >> y[i];
		c = chuVi();
		f = (c - 2 * M_PI * r) / c;
		if (f < 0) cout << "Not possible";
		else printf("%0.9lf", f);
		cout << endl;
	}
}