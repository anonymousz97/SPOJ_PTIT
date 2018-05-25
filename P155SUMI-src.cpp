#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[100];
int res;
main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + 1 + m);
	res = 1e6;
	for (int i = n; i <= m; i++)
	{
		int amax = -1e6;
		int amin = 1e6;
		for (int j = i; j > i - n; j--)
		{
			if (amax < a[j]) amax = a[j];
			if (amin > a[j]) amin = a[j];
		}
		if (amax - amin < res) res = amax - amin;
	}
	cout << res;
}
