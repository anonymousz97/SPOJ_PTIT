#include <iostream>
#include <algorithm>
using namespace std;
int n, xr[20], a[20], x[20], d[5];
int s[5], res;

void update()
{
	int p[5];
	for (int i = 1; i <= 4; i++) p[i] = s[i];
	sort(p + 1, p + 1 + 4);
	if (res > p[4] - p[1]) res = p[4] - p[1];
}

void Try(int i)
{
	for (int j = 1; j <= 4; j++)
	  if (d[j] < 3)
	  {
	  	x[i] = j;
	  	d[j]++;
	  	s[j] += a[i];
	  	
	  	if (i == n) update();
	  			else Try(i + 1);
	  			
	  	x[i] = 0;
	  	d[j]--;
	  	s[j] -= a[i];
	  }
}

main()
{
	n = 12;
	res = 1e9;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) x[i] = 0;
	for (int i = 1; i <= 4; i++)
	{
		d[i] = 0;
		s[i] = 0;
	}
	Try(1);
	cout << res << endl;
}
