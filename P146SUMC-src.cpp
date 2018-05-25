#include <iostream>
#include <cmath>
#define ll long long
#define x first
#define y second
#define oo 1e9
using namespace std;
typedef pair <int, int> record;
record p[200];
ll n, d, c[200][200], a[200] = {0};
main()
{
	cin >> n >> d;
	for (int i = 2; i < n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
	for (int i = 1; i <= n; i++)
	  for (int j = 1; j <= n; j++) c[i][j] = oo;
	for (int i = 1; i <= n; i++)
	  for (int j = 1; j <= n; j++)
	  {
	  	if (i == j) continue;
	  	c[i][j] = (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y)) * d - a[i];
	  }
	for (int i = 1; i <= n;  i++)
	  for (int j = 1; j <= n; j++)
	    for (int k = 1; k <= n; k++) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
	cout << c[1][n];
}
