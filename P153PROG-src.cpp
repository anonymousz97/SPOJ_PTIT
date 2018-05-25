#include <iostream>
#define ll long long
using namespace std;
ll x, res, k, n;
main()
{
	cin >> n >> k;
	x = n / 2;
	if (n % 2 != 0) x++;
	if (k <= x) res = 2 * k - 1;
	else res = (k - x) * 2;
	cout << res;
}