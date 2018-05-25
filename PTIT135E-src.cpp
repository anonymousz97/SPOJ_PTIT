#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
long a[20], b[20], st[20], n, t;
long x[20], xh[201];
long l;
string rs[2049];
long r = 0;

void update()
{
	for (long i = 0; i < l; i++) xh[i] = 1;
	for (long i = 1; i <= n; i++)
	  if (x[i] == 0)
	  {
	  	xh[a[i]] = 0;
	  	xh[b[i]] = 0;
	  }
	r++;
	rs[r] = "";
	for (long i = 0; i < l; i++) 
	  if (xh[i]) rs[r] += s[i];
}

void Try(long i)
{
	for (long j = 0; j <= 1; j++)
	{
		x[i] = j;
		if (i == n) update();
		else Try(i + 1);
	}
}
main()
{
	cin >> s;
	n = 0;
	t = 0;
	l = s.length();
	for (long i = 0; i < l; i++)
	  if (s[i] == '(')
	  {
	  	t++;
	  	st[t] = i;
	  }
	  else
	  if (s[i] == ')')
	  {
	  	n++;
	  	a[n] = st[t];
	  	b[n] = i;
	  	t--;
	  }
	Try(1);
	r--;
	sort(rs + 1, rs + 1 + r);
	rs[0] = "*";
	for (long i = 1; i <= r; i++) 
	  if (rs[i] != rs[i - 1]) cout << rs[i] << endl;
}
