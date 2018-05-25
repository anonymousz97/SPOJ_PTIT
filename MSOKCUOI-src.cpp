#include <iostream>
#include <string>
#include <math.h>
using namespace std;
long t;

long ptich(long n, long a[])
{
	if (n == 0) return 0;
	while (n % 2 == 0)
	{
		a[2]++;
		n /= 2;
	}
	while (n % 5 == 0)
	{
		a[5]++;
		n /= 5;
	}
}

long tinh(string s)
{
	long d[100];
	for (long i = 65; i <= 90; i++) d[i] = 0;
	long l = s.length();
	for (long i = 0; i < l; i++)
	{
		long x = long (s[i]);
		d[x]++;
	}
	long a[10];
	for (long i = 2; i <= 5; i++) a[i] = 0;
	for (long i = 2; i <= l; i++) ptich(i, a);
	long b[10];
	for (long i = 2; i <= 5; i++) b[i] = 0;
	for (long i = 65; i <= 90; i++)
	  for (long j = 2; j <= d[i]; j++) ptich(j, b);
	long c[10]; 
	c[2] = a[2] - b[2];
	c[5] = a[5] - b[5];	
	if (c[2] < c[5]) return (c[2]);
	return (c[5]);
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		string s;
		cin >> s;
		cout << tinh(s) << endl;
	}
}