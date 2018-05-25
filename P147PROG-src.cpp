#include <iostream>
#include <stdio.h>
using namespace std;
long sm, sy, sx, x, m, y, n, d;
main()
{
	d = 0;
	cin >> n;
	while (n > 0)
	{
		d++;
		sx = 0; sm = 0; sy = 0;
		for (long i = 1; i <= n; i++) 
		{
			cin >> x >> y >> m;
			sm += m;
			sx += x * m;
			sy += y * m;
		}
		float rx = (float) sx / sm, ry = (float) sy / sm;
		printf("Case %d: %0.2f %0.2f\n", d, rx, ry);
		cin >> n;
	}
}