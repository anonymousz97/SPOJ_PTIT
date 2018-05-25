#include <iostream>
#include <string>
using namespace std;
string s;
int d[10][10], res, doc[10], ngang[10], r, c;
main()
{
	cin >> r >> c;
	for (long i = 0; i < r; i++)
	  for (long j = 0; j < c; j++) d[i][j] = 0;
	for (long i = 0; i < r; i++) ngang[i] = 1;
	for (long j = 0; j < c; j++) doc[j] = 1;
	for (long i = 0; i < r; i++) 
	{
		cin >> s;
		for (long j = 0; j < c; j++)
		  if (s[j] == 'S')
		  {
		  	ngang[i] = 0;
		  	doc[j] = 0;
		  }
	}
	for (long i = 0; i< r; i++)
		  if (ngang[i])
		    for (long j = 0; j < c; j++) d[i][j] = 1;
	for (long j = 0; j < c; j++)
		  if (doc[j])
		    for (long i = 0; i < r; i++) d[i][j] = 1;
	res = 0;
	for (long i = 0; i < r; i++)
	  for (long j = 0; j < c; j++) res += d[i][j];
	cout << res;
}