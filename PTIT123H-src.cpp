#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const ll nmax = 250;
ll f[305][305] = {0}, n;

void Init()
{
	for (int i = 1; i <= nmax; i++)
	  for (int j = i; j >= 0; j--) f[i][j] = 1;
	for (int i = 0; i <= nmax; i++) f[0][i] = 1;
}

main()
{
	Init();
	for (int i = 2; i <= nmax; i++)
	  for (int j = i / 2; j > 0; j--) f[i][j] = f[i - 2 * j][j] + f[i][j + 1];
	while (cin >> n && n != 0) cout << n << " " << f[n][1] << endl;
}