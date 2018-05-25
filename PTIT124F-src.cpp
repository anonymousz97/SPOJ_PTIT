#include <iostream>
#include <math.h>
using namespace std;
long n, nt[100], x[100], cx[100];
long d = 0;
long ketQua[10] = {0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144};
long nguyenTo(long n)
{
	if (n == 1) return 0;
	if (n == 2) return 1;
	for (long i = 2; i <= sqrt(n); i++)
	  if (n % i == 0) return 0;
	return 1;
}

long process()
{
	d++;
	for (long i = 1; i <= 2 * n; i++) cout << x[i] << " ";
	cout << endl;
}


long Try(long i)
{
	for (long j = 2; j <= 2 * n; j++)
	{
	  if (d == 10000) return 0;	
	  if (cx[j] && nt[j + x[i - 1]])
	  {
	  	cx[j] = 0;
	  	x[i] = j;
	  	if (i == 2 * n)
	  	{
	  		if (nt[x[2 * n] + 1]) process();
	  	}
	  	else Try(i + 1);
	  	cx[j] = 1;
	  }
	}
}

main()
{
	cin >> n;
	for (long i = 1; i <= 4 * n; i++) nt[i] = nguyenTo(i);
	x[1] = 1;
	for (long i = 1; i <= 2 * n; i++) cx[i] = 1;
	cout << ketQua[n] << endl;
	Try(2);
}