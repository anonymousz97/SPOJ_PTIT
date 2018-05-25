#include <iostream>
using namespace std;
long n, t1, t2, t3;
long res, tong;
main()
{
	while ((cin >> n) && (n != 0))
	{
		cin >> t1 >> t2 >> t3;
		res = 4 * n - 1;
		res += (t2 - t1) + (t2 - t3);
		if (t1 > t2) res += n;
		if (t2 < t3) res += n;
		cout << res << endl;
	}
}
