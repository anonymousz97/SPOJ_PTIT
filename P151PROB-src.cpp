#include <iostream>
#define ll long long
#define oo 1000000000000000
using namespace std;
int n;
ll res, f[2005], t[2005], c[2005];
main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> c[i];
		f[i] = oo;
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= 0; j--)
		{
			int x = t[i] + j + 1;
			if (x > n) x = n;
			f[x] = min(f[x], f[j] + c[i]);
		}
	}
	cout << f[n];
}
