#include <iostream>
#include <algorithm>
using namespace std;
long n, t;
double x[1001], y[1001];
typedef pair<double, double> trungDiem;
trungDiem a[600001];

long result(long t)
{
	long res = 0;
	long d = 1;
	for (long i = 2; i <= t; i++)
	{
		if (a[i] == a[i - 1])
		{
			d++;
			if (i == t) res += (d * (d - 1)) / 2;
		}
		else 
		{
			res += d * (d - 1) / 2;
			d = 1;
		}
	}
	return res;
}

long buildA()
{
	long t = 0;
	for (long i = 1; i < n; i++)
	  for (long j = i + 1; j <= n; j++)
	  {
	  	t++;
	  	a[t].first = (x[i] + x[j]) / 2;
	  	a[t].second = (y[i] + y[j]) / 2;
	  }
	sort(a + 1, a + 1 + t);
//	for (long i = 1; i <= t; i++) cout << a[i].first << " " << a[i].second << endl;
	cout << result(t) << endl;
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n;
		for (long i = 1; i <= n; i++) cin  >> x[i] >> y[i];
		buildA();
	}
}