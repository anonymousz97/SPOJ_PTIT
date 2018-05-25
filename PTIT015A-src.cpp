#include <iostream>
#include <string>
using namespace std;
string a, b, c;
int d[20], t;

void Dem(string s)
{
	int l = s.length();
	for (int i = 0; i < l; i++) d[s[i] - '0']++;	
}

main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		for (int i = 0; i < 10; i++) d[i] = 0;
		Dem(a);
		Dem(b);
		Dem(c);
		string res = "";
		for (int i = 9; i >= 0; i--)
		  for (int j = 1; j <= d[i]; j++) res += char(i + 48);
		while (res.length() > 1 && (res[0] == '0')) res.erase(0, 1);
		cout << res << endl;
	}
}