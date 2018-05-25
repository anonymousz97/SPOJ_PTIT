#include <iostream>
#include <string>
using namespace std;
int m, n, d[500][500];
string s[500];
int res;

void Init()
{
	for (int i = 0; i <= m; i++)
	  for (int j = 0; j <= n; j++) d[i][j] = 0;
	res = 0;	
}

int type(char x)
{
	if (x == '.') return 1;
	return 0;
}

void BuildD()
{
	for (int i = 1; i <= m; i++)
	  for (int j = 1; j <= n; j++) d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + type(s[i][j]);
}

int tinh(int x, int y)
{
	int res = 1;
	for (int i = x - 1; i >= 0; i--)
	  for (int j = y - 1; j >= 0; j--)
	  {
	  	int k = d[x][y] - d[i][y] - d[x][j] + d[i][j];
	  	if (k != (x - i) * (y - j)) break;						// Break nay quan trong cat giam toi da truong hop. Neu khong co se bi TLE
	  	int tmp = x - i + y - j;
	  	tmp *= 2;
	  	if (res < tmp) res = tmp;
	  }	
	return --res;
}

void Process()
{
	for (int i = 1; i <= m; i++)
	  for (int j = 1; j <= n; j++)
	    if (s[i][j] == '.') res = max(res, tinh(i, j));
}

main()
{
//	freopen("in.txt", "r", stdin);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> s[i];
		s[i] = "*" + s[i];
	}
	Init();
	BuildD();
	Process();
	cout << res;
}
