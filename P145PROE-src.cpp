#include <iostream>
#include <string>
using namespace std;
string x[6][200], s;
long r[8] = {-2, -1, 0, 1, 2, 1, 0, -1};
long c[8] = {0, -1, -2, -1, 0, 1, 2, 1};

void ghiTeo(long k, long u, long v)
{
	x[u][v] = s[k];
	for (long i = 0; i < 8; i++)
	{
		long p = u + r[i], q = v + c[i];
		x[p][q] = "*";
	}
}

void ghiTi(long k, long u, long v)
{
	x[u][v] = s[k];
	for (long i = 0; i < 8; i++)
	{
		long p = u + r[i], q = v + c[i];
		if (x[p][q] != "*") x[p][q] = "#";
	}
}

main()
{
	cin >> s;
	long l = s.length();
	s = "@" + s; 
	for (long i = 0; i <= 5; i++)
	  for (long j = 0; j <= 5 * l; j++) x[i][j] = '.';
	long xb = 3, yb = -1;
	for (long i = 1; i <= l; i++)
	  {
	  	yb += 4;
	  	if (i % 3 != 0) ghiTi(i, xb, yb);
	  	else ghiTeo(i, xb, yb);
	  }
	for (long i = 1; i <= 5; i++)
	 {
	 	for (long j = 1; j <= yb + 2; j++) cout << x[i][j];
	 	cout << endl;
	 }
}
