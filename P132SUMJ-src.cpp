#include <iostream>
#include <string>
using namespace std;
string s;
long n, st, m, smax, c[7], x[7];

void xuli()
{
	st = 0;
	for (long i = 0; i < n; i++ ) st = st * 10 + int (s[x[i]]) - 48;
	if ((st > m ) && (st < smax)) smax = st;
}
void sinh(long i)
{
	for (long j = 0; j < n; j++)
	  if (c[j])
	  {
	  	x[i] = j;
	  	c[j] = 0;
	  	if (i == n - 1) xuli();
	  	else sinh(i + 1);
	  	if (c[j] == 0) c[j] = 1;
	  }
}
main()
{
	cin >> s;
	n = s.length();
	m = 0;
	for (long i = 0; i < n; i++) m = m * 10 + int (s[i]) - 48;
	for (long i = 0; i <= 7; i++) c[i] = 1;
	smax = 1000000000;
	sinh(0);
	if (smax == 1000000000) smax = 0;
	cout << smax;
}