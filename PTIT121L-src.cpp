#include <iostream>
#include <math.h>
using namespace std;
long long s, chv, x1, x2, x3, yy, y2, y3;
main()
{
	cin >> x1 >> yy;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	s = x1*yy + x2*y2 + x3*y3;
	chv = (long long) (sqrt(s));
	if (chv == sqrt(s)) cout << chv;
	else cout << 0;
}