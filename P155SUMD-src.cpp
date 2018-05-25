#include <iostream>
#define nmax 1000000
using namespace std;
int n, m;
int d[nmax + 5];

main()
{
	cin >> n >> m;
	for (int i = 0; i <= nmax; i++) d[i] = 0;
	int x;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		d[x]++;
	}
	for (int i = 1; i <= nmax; i++) d[i] += d[i - 1];
	for (int i = 1; i <= m; i++)
	{
		cin >> x;
		cout << d[x] << endl;
	}
}

