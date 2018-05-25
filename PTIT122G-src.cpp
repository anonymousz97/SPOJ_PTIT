#include <iostream>
#include <string>
using namespace std;
string s;
long a[15], n;
long long res, e[12];
main()
{
	e[0] = 1;
	for (long i = 1; i < 12; i++) e[i] = e[i - 1] * 10;
	while ((cin >> s) && (s != "0"))
	{
		res = 0;
		n = s.length();
		for (long i = 0; i < n; i++) a[i + 1] = long (s[i]) - 48;
		long l = 1, r = n;
		while (l < r)
		{
			if (a[l] > a[r])
			{
				res += (a[l] - a[r]) * e[n - r];
				a[r] = a[l];
			}
			else 
			if (a[l] < a[r])
			{
				if (l != r - 1)
				{
					res += (10 + a[l] - a[r]) * e[n - r];
					long nho = 1;
					a[r] = a[l];
					long k = r - 1;
					while (nho)
					{
						if (a[k] == 9)
						{
							a[k] = 0;
							k--;
						}
						else
						{
							a[k]++;
							if (k == l) res += e[n - r];
							break;
						}
					}
				}
				else
				{
					res += (11 + a[l] - a[r]) * e[n - r];
					a[l]++;
					a[r] = a[l];
				}
			}
			l++;
			r--;
		}
		cout << res << endl;
	}
}