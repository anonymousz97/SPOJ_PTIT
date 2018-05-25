#include <iostream>
const long long k = 1e8 + 1;
using namespace std;
long long n, t;

long long lt(long long n)
{
	if (n == 0) return 1;
	long long p = lt(n / 2) % k;
	if (n % 2 == 0) return (p * p % k);
	return p * p * 2 % k;
}
main()
{
	cin >> t;
	long d = 0;
	for (long q = 1; q <= t; q++)
	{
		cin >> n;
		d++;
		if (n == 0)
		{
			cout << "Case " << d << ": 1 0" << endl;
			continue;
		}
		long long lt1 = lt(n - 1);
		long long kq1 = (lt1 * ((lt1 * 2) % k + 1)) % k;
		long long kq2 = (lt1 * ((lt1 * 2) % k - 1)) % k;
		cout << "Case " << d << ": " << kq1 << " " << kq2 << endl;
	}
} 