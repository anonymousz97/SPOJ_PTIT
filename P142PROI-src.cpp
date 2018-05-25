#include <iostream>
using namespace std;
long p, res;

long canNguyenThuy(long x)
{
	long du = 1;
	for (long i = 1; i <= p - 1; i++)
	{
		du = (du * x) % p;
		if ((i < p - 1) && (du == 1)) return 0;
	}
	if (du == 1) return 1;	
	
}

main()
{
	cin >> p;
	res = 0;
	for (long x = 1; x < p; x++)
	  if (canNguyenThuy(x)) res++;
	cout << res;
}