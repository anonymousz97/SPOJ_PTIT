#include <iostream>
#include <algorithm>
#define nmax 400005
using namespace std;
int n, a[nmax], b[nmax];
main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];	
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	int res = 0;
	int i = 1, j = 1;
	while (1)
	{
		while ((j <= n) && (a[i] > b[j])) j++;
		if (j > n) break;
		res++;
		i++;
		j++;
	}
	cout << res;
}