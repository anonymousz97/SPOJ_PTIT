#include <iostream>
#include <math.h>
using namespace std;
long long a, b, c, d[1000002];

long tinh(long n)
{
	long res = 0;
	for (long i = 1; i <= sqrt(n); i++)
	  if (n % i == 0)
	  {
	  	if (i * i == n) res++;
	  	else res += 2;
	  }
	d[n] = res;
	return res;
}

long long ketQua()
{
	long du = 1073741824;
	long long res = 0;
	for (long i = 1; i <= a * b * c; i++) d[i] = -1;
	for (long i = 1; i <= a; i++)
	  for (long j = 1; j <= b; j++)
	    for (long k = 1; k <= c; k++)
	    {
	    	if (d[i * j * k] != -1) res += d[i * j * k];
	    	else res += tinh(i * j * k);
	    	res %= du;
	    }
	return res;
}

main()
{
	cin >> a >> b >> c;
	cout << ketQua();
}