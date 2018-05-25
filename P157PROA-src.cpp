#include <iostream>

using namespace std;
int t, n, res;
main()
{
//	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int x, a[2000] = {0};
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			a[x]++;
		}
		int amax = 0;
		for (int i = 1; i <= 1000; i++)
		  if (a[i] > amax) amax = a[i];
		for (int i = 1; i <= 1000; i++)
		  if (a[i] == amax)
		  {
		  	res = i;
		  	break;
		  }
		cout << res << endl;
	}
}