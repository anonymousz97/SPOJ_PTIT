#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double x, y, r, res;
double a[3000];
int n, t[3000], c[3000];
main()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	t[1] = 1;
	c[1] = 1;
	for (int i = 2; i <= n; i++)
	  if ((a[i] - a[i - 1]) / 2 * y <= x) 
	  {
	    t[i] = t[i - 1];
	    c[i] = c[i - 1];
	  }
	  else
	  {
	  	t[i] = i;
	  	c[i] = c[i - 1] + 1;
	  }
	  
	res = 0;
	int d = c[n];
	for (int i = n; i > 0; i--)
	  if (c[i] == d) 
	  {
	    res += ((a[i] - a[t[i]])/2 * y + x);
	    d--;
	  }
	if (res == (long) res) printf("%.0lf", res);
	else printf("%.1lf", res);
}