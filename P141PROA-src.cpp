#include <iostream>
#include <string.h>
using namespace std;
int player, t, x, n;
string s;
main()
{
	cin >> player;
	cin >> n;
	t = 0;
	for (long i = 1; i <= n; i++)
	{
		cin >> x >> s;
		t += x;
		if (t > 210) break;
		else 
		if (s == "T") player = player % 8 + 1;
	}
	cout << player;
}