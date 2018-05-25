#include <iostream>
using namespace std;
int t, n;

int tinh(int m)
{
	int res = 0;
	while (m != 0)
	{
		res += m % 10;
		m /= 10;
	}
	return res;
}

int ketQua(int n)
{
	int res = n;
	while (res > 9) res = tinh(res);
	return res;
}

main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << ketQua(n) << endl;
	}
}
