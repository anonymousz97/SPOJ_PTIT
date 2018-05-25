#include <iostream>
#include <string>
using namespace std;
string s;
long t, st[100001], res;

main()
{
	cin >> s;
	long l = s.length();
	t = 0;
	for (long i = 0; i < l; i++)
	  if (s[i] == '(')
	  {
	  	t++;
	  	st[t] = 0;
	  }
	  else if (s[i] == ')')
	  {
	  	long p = 0;
	  	while (st[t] != 0) p += st[t--];
	  	st[t] = p;
	  }	
	  else if (s[i] == 'C') 
	  {
	  	t++;
	  	st[t] = 12;
	  }
	  else if (s[i] == 'H')
	  {
	  	t++;
	  	st[t] = 1;
	  }
	  else if (s[i] == 'O')
	  {
	  	t++;
	  	st[t] = 16;
	  }
	  else if (('2' <= s[i]) && (s[i] <= '9'))
	  {
	  	long x = long (s[i]) - 48;
	  	st[t] *= x;
	  }
	res = 0;
	for (long i = 1; i <= t; i++) res += st[i];
	cout << res;
}