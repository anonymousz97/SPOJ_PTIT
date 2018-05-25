#include <stdio.h>
int n, d[30], t;

int Find(int k, int n)
{
	if (k == 0)
	{
		if (n == 1) return 1;
		return 0;
	}
	int x = d[k - 1];
	if (n <= x) return (Find(k - 1, n));
	if (n == x + 1) return 1;
	if ((x + 1 < n) && (n <= x + k + 3)) return 0;
	return (Find(k - 1, n - x - k - 3));
}

main()
{
	scanf("%d", &n);
	d[0] = 3;
	t = 0;
	do
	{
		t++;
		d[t] = d[t - 1] * 2 + (t + 3);
	}
	while (d[t] < n);
	if (Find(t, n)) printf("m"); else printf("o");
}
