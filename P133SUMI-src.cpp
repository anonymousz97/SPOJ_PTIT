#include <iostream>
#include <string>
#include <math.h>

using namespace std;
string s;
long r, c, l;
string a[100][100];
main()
{
	cin >> s;
	l = s.length();
	for (long i = sqrt(l) ; i >= 1; i--)
	 {
	 	if (l % i == 0)
	 	{
	 		r = i;
	 		c = l / i;
	 		break;
	 	}
	 }
	long d = 0;
	for (long j = 0; j < c; j++)
	  for (long i = 0; i < r; i++) a[i][j] = s[d++];
	for (long i = 0; i < r; i++)
	  for (long j = 0; j < c; j++) cout << a[i][j];
}