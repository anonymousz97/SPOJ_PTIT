#include <iostream>
#include <string>
using namespace std;
string s;
int st[100005], t;
main()
{
	cin >> s;
	t = 0;
	st[0] = 'z' + 1;
	int l = s.length();
	s = "*" + s;
	for (int i = 1; i <= l; i++)
	{
		while (s[i] > st[t]) t--;
		st[++t] = s[i];
	}
	for (int i = 1; i <= t; i++) cout << char (st[i]);
}