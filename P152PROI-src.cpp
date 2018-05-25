#include <iostream>
#include <math.h>
using namespace std;
int t, a, x, p, q;

int ucln(int a, int b)
{
	if (!b) return a;
	return (ucln(b, a % b));
}
main()
{
	cin >> t;
	while (t--)
	{
		cin >> a;
		p = a % 360;
		q = 180;
		int k = ucln(p, q);
		p /= k;
		q /= k;
		if (!p) cout << "0$";
		else
		if (p == 1)
		{
			if (q == 1) cout << "$";
			else cout << "$/" << q;
		}
		else cout << p << "$/" << q;
		cout << endl;
	}
}
