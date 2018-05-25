#include <iostream>
#include <string>
using namespace std;
string s;

string kiemTra(string s)
{
	long long d = 0;
	long l = s.length();
	for (long i = 0; i < l; i++)
	{
		if (('0' <= s[i]) && (s[i] <= '9')) d += long (s[i]) - 48;
		else if (('A' <= s[i]) && (s[i] <= 'Z')) d += long (s[i]) - 55;
		else if (('a' <= s[i]) && (s[i] <= 'z')) d += long (s[i]) - 61;
	}
	if (d % 61 == 0) return "yes";
	return "no";
}
main()
{
	while ((cin >> s) && (s != "end"))
	{
		cout << kiemTra(s) << endl;
	}
}