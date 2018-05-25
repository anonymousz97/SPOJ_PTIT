#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int r, c, t;
string s, key[100];
int dem = 0;

string chuoi(int n)
{
	string r = "";
	while (n > 0)
	{
		r = char (n % 2 + '0') + r;
		n /= 2;
	}
	while (r.length() < 5) r = "0" + r;
	return r;
}

void BuildKey()
{
	key[' '] = "00000";
	for (int i = 'A'; i <= 'Z'; i++) key[i] = chuoi(i - 64);
}

void BuildTB(string s)
{
	int a[25][25];
	for (int i = 1; i <= r; i++)
	  for (int j = 1; j <= c; j++) a[i][j] = 0;
	int m = 1, n = 1;
	int l = s.length();
	int d = 0;
	while (m <= r/2 + 1 && n <= c/2 + 1)
	{
		for (int i = n; i <= c - n + 1; i++)
		  if (d < l) a[m][i] = s[d++] - '0';
		for (int i = m + 1; i <= r - m + 1; i++)
		  if (d < l) a[i][c - n + 1] = s[d++] - '0';
		for (int i = c - n; i >= n; i--)
		  if (d < l) a[r - m + 1][i] = s[d++] - '0';
		for (int i = r - m; i >= m + 1; i--)
		  if (d < l) a[i][n] = s[d++] - '0';
		if (d == l) break;
		m++;
		n++;
	}
	cout << ++dem << " ";
	for (int i = 1; i <= r; i++)
	  for (int j = 1; j <= c; j++) cout << a[i][j];
	cout << endl;
}

main()
{
	BuildKey();
	cin >> t;
	while (t--)
	{
		cin >> r >> c;
		getline(cin, s);
		s.erase(0, 1);
		string s1 = "";
		int l = s.length();
		for (int i = 0; i < l; i++) s1 += key[s[i]];
		BuildTB(s1);
	}
}