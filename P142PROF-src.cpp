#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
long n, a[1001];

long uc(long a, long b)
{
	if (a % b == 0) return b;
	return (uc(b, a % b));
}
long ok(long x)
{
	for (long i = n; i > 0; i--)
	  if ((i != x) && (uc(a[x], a[i]) != 1)) return 0;
	return 1;	
}

long ketQua()
{
	for (long i = n; i > 0; i--)
	  if (ok(i)) return a[i];
}
main()
{
	while (scanf("%ld", &n) != EOF)
	{
		for (long i = 1; i <= n; i++) scanf("%ld", &a[i]);
		sort(a + 1, a + 1 + n);
		printf("%ld\n", ketQua());
	}
}