#include <iostream>
using namespace std;
int n, t, s, res;
main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		int x, k = 0;
		int ok = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			k += x;
			if (!ok)
			{
				if (k > s)
				{
					res = i - 1;
				}
				else 
				if (k == s) res = i;
				if (k >= s) ok = 1;
			}
		}
		cout << res << endl;
	}
}
