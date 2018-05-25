#include <iostream>
#include <string>
using namespace std;
int m, k, len;
string s;
int a[3000000], l, r;

main()
{
	cin >> m >> k >> s;
	len = s.length() - 1;
	for (int i = 1; i <= m; i++) a[i] = i - 1;
	l = 1; r = m;
	for (int i = 0; i < len; i++)
	  if (s[i] == 'A') a[++r] = a[l++];
	  else 
	  {
	  	a[++r] = a[l + 1];
	  	a[l + 1] = a[l++];
	  }
	cout << a[l + k - 1] << " " <<  a[l + k] << " " <<  a[l + k + 1];
}