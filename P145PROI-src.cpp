#include <iostream>
#include <string>
using namespace std;
string s;
long hoa, thuong, so;
long long res = 0;

long ok()
{
	if (hoa * thuong * so == 0) return 0;
	if (hoa + thuong + so >= 6) return 1;
	return 0;
}
main()
{
	cin >> s;
	long n = s.length();
	s = "@" + s;
	long l = 1, r = 0;
	hoa = 0;
	thuong = 0;
	so = 0;
	while (r <= n)
	{
		if (!ok())
		{
			r++;
			if (r > n) break;
			if (('0' <= s[r]) && (s[r] <= '9')) so++;
			if (('A' <= s[r]) && (s[r] <= 'Z')) hoa++;
			if (('a' <= s[r]) && (s[r] <= 'z')) thuong++;
		}
		else
		{
			res += (n - r + 1);
			if (r - l > 5)
			{
				if (('0' <= s[l]) && (s[l] <= '9')) so--;
				if (('A' <= s[l]) && (s[l] <= 'Z')) hoa--;
				if (('a' <= s[l]) && (s[l] <= 'z')) thuong--;
				l++;
			}
			else
			if (r - l == 5)
			{
				r++;
				if (r > n) break;
				if (('0' <= s[r]) && (s[r] <= '9')) so++;
				if (('A' <= s[r]) && (s[r] <= 'Z')) hoa++;
				if (('a' <= s[r]) && (s[r] <= 'z')) thuong++;
				
				if (('0' <= s[l]) && (s[l] <= '9')) so--;
				if (('A' <= s[l]) && (s[l] <= 'Z')) hoa--;
				if (('a' <= s[l]) && (s[l] <= 'z')) thuong--;
				l++;
			}
		}
	}
	cout << res;
}