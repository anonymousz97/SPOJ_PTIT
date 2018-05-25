#include <iostream>
using namespace std;
long n, m, a[100001];
long prev[100001], next[100001];
main()
{
	cin >> n >> m;
	next[0] = 1;
	for (long i = 1; i <= n; i++)
	{
		a[i] = i;
		prev[i] = i - 1;
		next[i] = i + 1;
	}
	long ik, jk;
	for (long k = 1; k <= m; k++)
	{
		cin >> ik >> jk;
		prev[next[ik]] = prev[ik];
		next[prev[ik]] = next[ik];
		prev[ik] = prev[jk];
		next[ik] = jk;
		next[prev[jk]] = ik;
		prev[jk] = ik; 
	}
	long k = next[0];
	while (k <= n)
	{
		cout << k << " ";
		k = next[k];
	}
}