#include<iostream>
#include<math.h>
#include<string>
using namespace std;
string s;
long m, w, k;
main()
{
	cin >> k >> s;
	w = 0; m = 0;
	long l = s.length();
	while (s != "")
	{
		if ((fabs(w-m) < k) || ((w == m + k) && (s[0] == 'M')) || ((m == w + k) && (s[0] == 'W')))
		{
			if (s[0] == 'M') m++;
			else w++;
			s.erase(0, 1);
		} else
		{
			if (w == m + k)
			{
				if (s[1] == 'M')
				{
					m++;
					s.erase(1, 1);
				}
				else break;
			} else
			if (m == w + k)
			{
				if (s[1] == 'W')
				{
					w++;
					s.erase(1,1);
				}
				else break;
			}
		}
	}
	cout << w+m;
}