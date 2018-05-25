#include <iostream>
using namespace std;
long t, n, stt;
long a[10001];

long val(long n, long a[])
{
	long s = 0;
	for (long i = 1; i <= n; i++)
	 {
	 	s += a[i];
	 	long  j = i + 1;
	 	long r = 0;
	 	while (j <= n)
	 	{
	 		r += a[j];
	 		if (r == s)
	 		{
	 			if (j == n) return s;
	 			r = 0;
	 			j++;
	 		}
	 		else 
	 		if (r > s) break;
	 		else if (r < s) j++;
	 	}
	 }
	 return s;
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> stt >> n;
		for (long i = 1; i <= n; i++) cin >> a[i];
		cout << stt << " " << val(n, a) << endl;
	}
}