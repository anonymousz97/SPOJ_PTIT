#include <iostream>
#include <string>
using namespace std;
string s[30];
long n;

long hangNgang(long x, long y)
{
	if ((s[x][y] == s[x][y + 1]) && (s[x][y] == s[x][y + 2])) return 1;
	return 0;
}

long hangDoc(long x, long y)
{
	if ((s[x][y] == s[x + 1][y]) && (s[x][y] == s[x + 2][y])) return 1;
	return 0;
}

long duongCheo(long x, long y)
{
	if ((s[x][y] == s[x + 1][y + 1]) && (s[x][y] == s[x + 2][y + 2])) return 1;
	return 0;
}

long cheoNguoc(long x, long y)
{
	if ((s[x][y] == s[x + 1][y - 1]) && (s[x][y] == s[x + 2][y - 2])) return 1;
	return 0;
}

long check1(long i, long j)
{
	if ((i >= n - 2) || (j >= n - 2)) return 0;
	if (hangNgang(i, j) || hangDoc(i, j) || duongCheo(i, j)) return 1;
	return 0;
}

long check2(long i, long j)
{
	if ((i >= n - 2) && (j < n - 2))
		if (hangNgang(i, j)) return  1;
	return 0;
}

long check3(long i, long j)
{
	if ((j >= n - 2) && (i < n - 2))
		if (hangDoc(i, j)) return 1;
	return 0;
}

long check4(long i, long j)
{
	if ((i < n - 2) && (j > 1))
		if (cheoNguoc(i, j)) return 1;
	return 0;
}

long winner(char &res)
{
	for (long i = 0; i < n; i++)
	  for (long j = 0; j < n ; j++)
	    if (s[i][j] != '.')
	    {
	    	if (check1(i, j) || check2(i, j) || check3(i, j) || check4(i, j))
	    	{
	    		res = s[i][j];
	    		return 1;
	    	}
		}
	return 0;
}

main()
{
	cin >> n;
	for (long i = 0; i < n; i++) cin >> s[i];
	char res;
	if (winner(res)) cout << res; else cout << "ongoing";
}