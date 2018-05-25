#include <iostream>
using namespace std;
long long n, k;
long d[10];

long kiemTra()
{
	for (long i = 0; i < 10; i++)
	  if (d[i] == 0) return 0;
	return 1;
}

main()
{
	while (cin >> n)
	{
		k = 0;
		for (long i = 0; i < 10; i++) d[i] = 0;
		do
		{
			k++;
			long long s = n * k;
			while (s != 0)
			{
				d[s % 10]++;
				s = s / 10;
			}
		}
		while (not kiemTra());
		cout << k << endl;
	}
}