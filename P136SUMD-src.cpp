#include <iostream>
using namespace std;
long long c, k, t[20];

long sl0(long n)
{
	long p = 0;
	while (n != 0)
	{
		if (n % 10 == 0) p++;
		else break;
		n /= 10;
	}
	return p;
}

long long giaTri(long long c, long long &p)
{
	p = 0;
	long long x;
	while (c != 0)
	{
		x = c % 10;
		if (x == 0) p++;
		else break;
		c /= 10;
	}
	return x;
}

int main()
{
	cin >> c >> k;
	t[0] = 1;
	for (long i = 1; i <= 10; i++) t[i] = t[i - 1] * 10;	
	while (sl0(c) < k)
	{
		long long cs, p;
		cs = giaTri(c, p);
		if (cs < 5) c -= cs * t[p];
		else c += (t[p + 1] - cs * t[p]); 
		if (c == 0) break;
	}
	cout << c;
}