#include <iostream>
#include <string>
using namespace std;
long r, c;
string s[21];
long doc[21][21], ngang[21][21];
string res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

long timdoc(long x, long y)
{
	doc[x][y] = 0;
	string ss = "";
	while ((x < r) && s[x][y] != '#')
	{
		ss += s[x][y];
		doc[x][y] = 0;
		x++;
	}
	if (ss.length() < 2) return 0;
	if (ss < res) res = ss;
}

long timngang(long x, long y)
{
	ngang[x][y] = 0;
	string ss = "";
	while ((y < c) && (s[x][y] != '#'))
	{
		ss += s[x][y];
		ngang[x][y] = 0;
		y++;
	}	
	if (ss.length() < 2) return 0;
	if (ss < res) res = ss;
}

main()
{
	cin >> r >> c;
	for (long i = 0; i < r; i++) cin >> s[i];
	for (long i = 0; i < r; i++)
	  for (long j = 0; j < c; j++)
	  {
	  	doc[i][j] = 1;
	  	ngang[i][j] = 1;
	  }
	for (long i = 0; i < r; i++)
	  for (long j = 0; j < c; j++)
	  {
	  	if (doc[i][j]) timdoc(i, j);
	  	if (ngang[i][j]) timngang(i, j);
	  }
	cout << res;
}