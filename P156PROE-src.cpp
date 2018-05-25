#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int n;
string s;

int so(char c)
{
	if (c == '_') return 91;
	if (c == '.') return 92;
	if (c <  91) return c;
}

char ch(int x)
{
	if (x > 92) x -= 28;
	if (x < 91) return char(x);
	if (x == 91) return '_';
	if (x == 92) return '.';
}

void Process(string s, int k)
{
	string res = "";
	int l = s.length();
	for (int i = 0; i < l; i++)
	{
		int x = so(s[i]) + k;
		res = ch(x) + res; 
	}
	cout << res << endl;
}

main()
{
//	freopen("in.txt", "r", stdin);
	while ((cin >> n) && (n != 0))
	{
		cin >> s;
		Process(s, n);
	}
}