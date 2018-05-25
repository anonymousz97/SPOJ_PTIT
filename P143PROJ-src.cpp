#include <iostream>
using namespace std;
unsigned long long  n, a, m, res, r, c;
main()
{
	cin >> n >> m >> a;
	res = 0;
	r = n / a;
	c = m / a;
	res += r * c;
	if (n != a * r) res += c;
	if (m != a * c) res += r;
	if ((m != a * c) && (n != a * r)) res++;
	cout << res;
}