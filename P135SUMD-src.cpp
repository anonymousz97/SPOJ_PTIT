#include <iostream>
using namespace std;
long n, m, res, k;
int main()
{
	cin >> k;
	n = 1;
	while (n < k) n *= 2;
	if (n == k)
	{
		cout << n << " " << 0;
		return 0;
	}
	m = n;
	res = 0;
	while (k != 0)
	{
		if (k >= m) k -= m;
		if (k > 0) res++;
		m /= 2;
	}
	cout << n << " " << res;
}