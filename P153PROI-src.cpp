#include <iostream>
#include <string>
using namespace std;
string s;
int t;

void Result(string s)
{
	int d['z' + 1] = {0};
	int l = s.length();
	int res = 0;
	string rs = "";
	for (int i = 0; i < l; i++)
	{
		if (s[i] == ' ') continue;
		if (s[i] < 97) s[i] = char (s[i] + 32);
		if (!d[s[i]]) rs += s[i];
		d[s[i]]++;
	}
	for (int i = 'a'; i <= 'z'; i++)
	  if (d[i] > 1) res += d[i];
	cout << res << " " << rs << endl;
}

main()
{
	//freopen("in.txt", "r", stdin);
	cin >> t;
	cin.ignore();
	while (t--)
	{
		getline(cin, s);
		Result(s);
	}
}
