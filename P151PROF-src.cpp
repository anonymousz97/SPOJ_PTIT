#include <iostream>
#include <string>
using namespace std;
int a, b, l, f[1000006], g[1000006];
string s;
int main()
{
	cin >> s;
	cin >> a >> b;
	f[0] = (s[0] - '0') % a;
	int l = s.length();
	for (int i = 1; i < l; i++) f[i] = ((f[i - 1] * 10) + s[i] - '0') % a;
	g[l - 1] = (s[l - 1] - '0') % b;
	int t = 1;
	for (int i = l - 2; i >= 0; i--)
	{
		t = t * 10 %  b;
		g[i] = (g[i + 1] + t * (s[i] - '0') % b) % b; 
	}
	for (int i = 0; i < l - 1; i++)
	{
		if (s[i + 1] == '0') continue;
		if ((!f[i]) && (!g[i + 1]))
		{
			cout << "YES" << endl;
			for (int j = 0; j <= i; j++) cout << s[j];
			cout << endl;
			for (int j = i + 1; j < l; j++) cout << s[j];
			return 0;
		}
	}
	cout << "NO";
}