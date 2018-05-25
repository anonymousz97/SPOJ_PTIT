#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long ptich(long n, long d[])
{
	for (long i = 2; i <= sqrt(n); i++)
	  if (n % i == 0)
	  {
	  	while ((n != 0) && (n % i == 0))
	  	{
	  		d[i]++;
	  		n /= i;
	  	}
	  }
	if (n != 1) d[n]++;
}

long long ketQua(long n)
{
	long a[100], b[100], c[100];
	for (long i = 0; i <= 2 * n; i++)
	{
		a[i] = 0;
		b[i] = 0;
	}	
	for (long i = n + 1; i <= 2 * n; i++) ptich(i, a);
	for (long i = 2; i <= (n + 1); i++) ptich(i, b);
	for (long i = 1; i <= 2 * n; i++) c[i] = a[i] - b[i];
	long long res = 1;
	for (long i = 2; i <= 2 * n; i++)
	  for (long j = 1; j <= c[i]; j++) res *= i;
	return res;
}

main()
{
	long n;
	while ((cin >> n) && (n != 0))
	{
		cout << ketQua(n) << endl;
	}
}