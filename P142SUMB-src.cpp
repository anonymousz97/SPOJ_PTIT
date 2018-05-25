#include <iostream>
using namespace std;
long n, a[100001];
long amax = 0;
long long res = 0;

long F(long n)
{
	if (!n) return 0;
	if (n % 2 == 0) return F(n / 2);
	return F(n / 2) + 1;
}
main()
{
	cin >> n;
	long x;
	for (long i = 1; i <= n; i++)
	{
		cin >> x;
		a[i] = F(x);
		if (a[i] > amax) amax = a[i];
	}
	for (long p = 0; p <= amax; p++)
	{
		long long k = 0;
		for (long i = 1; i <= n; i++)
		  if (a[i] == p) k++;
		res += k * (k - 1) / 2;
	}
	cout << res;
}