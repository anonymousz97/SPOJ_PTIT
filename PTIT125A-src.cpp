#include <iostream>
#include <algorithm>
using namespace std;
long t, n, stt;
long a[20000];

void xuli1(long n)
{
	for (long i = n - 1; i >= 1; i--)
	  if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
	  else return;
}

void xuli2(long n)
{
	sort(a + 1, a + 1 + n);
}

main()
{
//	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		cin >> stt >> n;
		cout << stt << " " << (n + 1) / 2 << endl;
		long d = 0;
		for (long i = 1; i <= n; i++)
		{
			cin >> a[i];
			xuli1(i);
			if (i % 2 != 0)
			{
				d++;
				cout << a[ (i + 1) / 2] << " ";
				if (d % 10 == 0) cout << endl;
			}
			if ((i == n) && (d % 10 != 0)) cout << endl;
		}
	}
}
