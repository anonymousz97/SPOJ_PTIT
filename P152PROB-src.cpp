#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n, a[1000006], k, res;
main()
{
	cin >> n >> k;	
	if (!n)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	res = 1;
	for (int i = 2; i <= n; i++)
	  if (a[i] - a[i - 1] > k) res++;
	cout << res;
}
