#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string s;
int t;

int CB(string s)
{
	string r = "";
	int l = s.length();
	for (int i = l - 1; i >= 0; i--) r += s[i];
	for (int i = 1; i < l; i++)
	  if (fabs(s[i] - s[i - 1]) != fabs(r[i] - r[i - 1]))	return 0;
	return 1;
}

main()
{
	cin >> t;
	while (t--)
	{
		cin >> s;
		if (CB(s)) cout << "YES";
		else cout << "NO";
		cout << endl; 
	}
}
