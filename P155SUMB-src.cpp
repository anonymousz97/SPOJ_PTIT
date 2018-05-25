#include <iostream>
#include <string>
using namespace std;
string s;
int a[2000] = {0}, l;
main()
{
	cin >> s;
	l = s.length();
	for (int i = l - 1; i >= 0; i--)
	  if (s[i] == '1') a[l - i - 1] = 1;
	  else a[l - i - 1] = 0;
	for (int i = l - 1; i >= 0; i--)
	 if (a[i]) a[i + 4]++;
	for (int i = 0; i < l + 4; i++)
	  if (a[i] >= 2)
	  {
	  	a[i + 1]++;
	  	a[i] -= 2;
	  }
	if (a[l + 4]) cout << a[l + 4];
	for (int i = l + 3; i >= 0; i--) cout << a[i];
}
