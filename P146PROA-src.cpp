#include <iostream>
#include <string>
using namespace std;
const int oo = 999999999;
int x[10][10], a[10][10], b[10][10], res;
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, -1, 0, 1};

int kiemTra()
{
	int coLor = b[1][1];
	for (int i = 1; i < 5; i++)
	  for (int j = 1; j < 5; j++)
	    if (b[i][j] != coLor) return 0;
	return 1;
}

int Count()
{
	int res = 0;
	for (int i = 1; i < 5; i++)
	  for (int j = 1; j < 5; j++)
	    if (x[i][j]) res++;
	return res;
}

void Update()
{
	for (int i = 1; i < 5; i++)
	  for (int j = 1; j < 5; j++) b[i][j] = a[i][j];
	  
	for (int i = 1; i < 5; i++)
	  for (int j = 1; j < 5; j++)
	    if (x[i][j])
	    {
	    	for (int k = 0; k < 5; k++) b[i + dx[k]][j + dy[k]] = (b[i + dx[k]][j + dy[k]] + 1) % 2;
	    }
	if (kiemTra())
	{
		int d = Count();
		if (res > d) res = d;
	}
}

void Try(int i, int j)
{
	for (int k = 0; k < 2; k++)
	{
		x[i][j] = k;
		if (i == j && j == 4) Update();
		else
		  if (j == 4) Try(i + 1, 1);
		  else
		   Try(i, j + 1);
	}	
}

main()
{
//	freopen("in.txt", "r", stdin);
	string s;
	for (int i = 1; i <= 4; i++)
	{
		cin >> s;
		s = "*" + s;
		for (int j = 1; j < 5; j++)
		  if (s[j] == 'b') a[i][j] = 1;
		  else a[i][j] = 0;
	}
	res = oo;
	Try(1, 1);
	if (res == oo) cout << "Impossible";
	else cout << res;
}