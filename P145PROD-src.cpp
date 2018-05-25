#include <math.h>
#include <stdio.h>
double r, x, y;
main()
{
	scanf("%lf", &r);
	x = r * r * M_PI;
	y = r * r * 2;
	printf("%0.6lf\n", x);
	printf("%0.6lf", y);
}