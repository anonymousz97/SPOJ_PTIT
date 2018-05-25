#include <iostream>
#include <string>
using namespace std;

char dich(char s, string ss, long d)
{ 
	long x = long (s);
	long c = 0;
	long l = ss.length();
	
	for (long i = 0; i < l; i++)
		if (ss[i] == s) 
		{
			c++;
			if (c == 2)
			{
				c = i;
				break;
			}
		} 
	return (ss[c - d]);
}

void xuLi(string s, long x)
{
	long d;
	if (x >= 69) d = x - 69;
	else d = (90 - 69) + (x - 65 + 1); 
	cout << d << " ";
	//_____________________________________
	
	string ss = "";
	for (long i = 65; i <= 90; i++) ss += char (i);
	ss = ss + ss + ss;
	long l = s.length();
	for (long i = 0; i < l; i++)
	  if (s[i] == ' ') cout << " ";
	  else cout << dich(s[i], ss, d);
	cout << endl;
}

main()
{
	long t;
	cin >> t;
	cin.ignore();
	for (long q = 1; q <= t; q++)
	{
		string s;
		getline(cin, s);
		long l = s.length();
		long d[101];
		for (long i = 65; i <= 90; i++) d[i] = 0;
		for (long i = 0; i < l; i++)
		{
			long x = long (s[i]);
			d[x]++;
		}
		//for (long i = 65; i <= 90; i++) cout << i << " " << d[i] << endl;
		long c = 1, imax = 65;
		for (long i = 66; i <= 90; i++)
		  if (d[i] > d[imax])
		  {
		  	imax = i;
		  	c = 1;
		  }
		  else 
		  if (d[i] == d[imax]) c++;
		//cout << imax << endl;
		if (c != 1) cout << "NOT POSSIBLE" << endl; 
		else xuLi(s, imax);
	}
}