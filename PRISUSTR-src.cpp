#include <iostream>
#include <string>
using namespace std;
long t = 0;
string s, nt[100001];

string conv( long n)
{
	long x, m;
	string s1, ss = "";
	m = n;
	while (m != 0)
	{
		x = m % 10;
		s1 = char (x+48);
		ss = s1 + ss;
		m = m / 10; 
	}	
	return ss;
}

void sangnt(long n)
{
	long ck[100001];
	for (long i = 2; i <= n; i++) ck[i] = 1;
	for (long long i = 2; i <= n; i++)
	  if (ck[i])
	  {
	  	long long j = i*i;
	  	while (j <= n)
	  	{
	  		ck[j] = 0;
	  		j += i;
	  	}
	  }
	for (long i = 2; i <= n; i++)
	  if (ck[i])
	  {
	  	t++;
	  	nt[t] = conv(i);
	  }
}
main()
{
	sangnt(100000);
	cin >> s;
	while (s != "0")
	{
		for (long i = t; i >= 1; i-- )
		  if ( (int) s.find(nt[i]) != -1)
		  {
		  	cout << nt[i] << endl;
		  	break;
		  }
		cin >> s;
	}
}