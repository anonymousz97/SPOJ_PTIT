#include <iostream>
#include <string>
using namespace std;
string s;
int t, n;

string chuyen(int n)
{
	string res = "";
	while (n > 0)
	{
		int x = n % 10;
		res = char (x + 48) + res;
		n /= 10;
	}	
	return res;
}

void Process()
{
	int du = 0;
	while (s.length() > 1)
	{
		int l = s.length();
		string tam = "";
		for (int i = 0; i < l; i++)
		  if (i % 2 == du) tam += s[i];
		s = tam;
		du = (du + 1) % 2;
	//	cout << s << endl;
	}
	cout << s << endl;
}

main()
{
	cin >> t;
	while (t--)
	{
		s = "";
		cin >> n;
		for (int i = 1; i <= n; i++) s += chuyen(i);
		Process();
	}
}