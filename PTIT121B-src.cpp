#include <iostream>
#include <string>
using namespace std;
string s[20][1<<16];
int t[20], n;
main()
{
	cin >> n;
	t[1] = 2;
	s[1][1] = "0";
	s[1][2] = "1";
	for (int i = 2; i <= n; i++)
	{
		t[i] = 0;
		for (int j = 1; j <= t[i - 1]; j++) 
		{
			t[i]++;
			s[i][t[i]] = "0" + s[i - 1][j];
		}
		for (int j = t[i - 1]; j > 0; j--)
		{
			t[i]++;
			s[i][t[i]] = "1" + s[i - 1][j];
		}
	}
	for (int i = 1; i <= t[n]; i++) cout << s[n][i] << endl;
}