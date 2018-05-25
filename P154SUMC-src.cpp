#include <string>
#include <iostream>
using namespace std;
string s;
int d['z' + 1] = {0};
main()
{
	cin >> s;
	int l = s.length();
	int res = 0;
	for (int i = 0; i < l; i++) d[s[i]]++;
	for (int i = 'a'; i <= 'z'; i++)
	  if (d[i]) res++;
	if (res % 2 == 0) cout << "CHAT WITH HER!";
	else cout << "IGNORE HIM!";
}
