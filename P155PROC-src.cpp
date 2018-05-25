#include <iostream>
#define mod 1000000007
#define ll unsigned long long
using namespace std;
ll e[2000], f[2000][2000], s[2000][2000];

void BuildE()
{
	e[0] = 1;
	for (int i = 1; i <= 1000; i++) e[i] = 2 * e[i - 1] % mod;
}

void Init()
{
	BuildE();
	for (int i = 1; i <= 1000; i++) s[i][0] = 0;
	for (int n = 1; n <= 1000; n++)
	  for (int k = 1; k <= n; k++)
	  {
	  	if (n == k) f[n][k] = 1;
	  	else f[n][k] = (s[n - 1][k] - s[n - k - 1][k] + mod + e[n - k]) % mod; 
		s[n][k] = (s[n - 1][k] + f[n][k]) % mod;	
	  }
}

main()
{
	int n, t, k;
	Init();
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cout << f[n][k] << endl;
	}
}
