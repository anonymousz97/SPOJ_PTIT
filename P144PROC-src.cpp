#include <iostream>
#include <string>
using namespace std;
long long a, b;

long long lt(long long a, long long b)
{
	if (b == 1) return a;
	long long k = lt(a, b / 2) % 1000000007;
	k = k * k % 1000000007;
	if (b % 2 != 0) k = k * a % 1000000007;
	return k;
}
main()
{
	cin >> a >> b;
	while ((a != 0) || (b != 0))
	{
		if (a == 0) cout << 0;
		else if (b == 0) cout << 1;
		else
		{
			long long res = lt(a, b);
			cout << res;
		}
		cout << endl;
		cin >> a >> b;
	}
}