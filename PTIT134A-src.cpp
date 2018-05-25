#include <iostream>
#include <string>
using namespace std;
string s;
int d, t, win, c['z' + 1], l;

void Process(string s)
{
	for (int i = 'a'; i <= 'z'; i++) c[i] = 0;
	d = 0;
	t = 0;
	win = 1;
	l = s.length();
	for (int i = 0; i < l; i++) c[s[i]]++;
	for (int i = 'a'; i <= 'z'; i++)
	  if (c[i] % 2) d++;
	if (d < 2)
	{
		cout << "First" << endl;
		return;
	}
	if (d % 2) cout << "First";
	else cout << "Second";
	cout << endl;
}

main()
{
	while (cin >> s)
	{
		Process(s);
	}
}