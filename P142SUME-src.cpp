#include <iostream>
using namespace std;
long n, k, x[21], s, sum, res;

void Try(long i)
{
	for (long j = x[i - 1] + 1; j <= n; j++)
	{
		x[i] = j;
		sum += j;
		if ((sum == s) && (i == k)) res++;
		else 
		if ((sum < s) && (i < k)) Try(i + 1);
		sum -= j;
	}	
}

main()
{
	while ((cin >> n >> k >> s) && (n != 0))
	{
		x[0] = 0;
		sum = 0;
		res = 0;
		Try(1);
		cout << res << endl;
	}
}