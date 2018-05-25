#include <iostream>
#define x first
#define y second
using namespace std;
int t, n;
typedef pair <double, double> record;
double f[205];
record a[205];
main()
{
//	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		int res = 1;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
		f[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			f[i] = 1;
			for (int j = 1; j < i; j++)
			  if ((a[j].x < a[i].x) && (a[j].y > a[i].y))
			  {
			  	if (f[i] < f[j] + 1) f[i] = f[j] + 1;
			  }
			if (res < f[i]) res = f[i];
		}
		cout << res << endl;
	}
}