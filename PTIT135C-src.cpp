#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, a[200], m, st[200005], t = 0;

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);	
}

main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	m = fabs(a[1] - a[2]);
	for (int i = 3; i <= n; i++) m = gcd(m, fabs(a[i] - a[i -1]));
	for (int i = 1; i <= sqrt(m); i++)
	  if (m % i == 0)
	  {
	  	st[++t] = i;
	  	int k = m / i;
	  	if (k != i) st[++t] = k;
	  }
	sort(st + 1, st + 1 + t);
	for (int i = 2; i <= t; i++) cout << st[i] << " ";
}