#include <iostream>
#include <math.h>
using namespace std;
long a, b, x, res, t = 0;
main()
{
	cin >> a >> b;
	while (a != 0)
	{
		res = 0;
		t++;
		for (long n = sqrt(a) - 1; n <= sqrt(2 * b); n++)
		{
			x = n * (n + 1) / 2;
			if ((x + 1 > a) && (x + 1 < b))
			if (sqrt(x+1) == (long) (sqrt(x + 1))) res++;
		}
		cout << "Case " << t << ": " << res << endl;
		cin >> a >> b; 
	}
}