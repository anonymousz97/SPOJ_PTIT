#include <iostream>
#include <string>
#define ll long long
using namespace std;
string s, a, c, b;
char dau;
int t, d1, d2, d3;
int rd = 127657;

void tachxau()
{
	a = ""; b = ""; c = "";
	int l = s.length();
	int vt1, vt2;
	vt2 = s.find("=");
	for (int i = vt2 + 1; i < l; i++) c += s[i];
	if (s[0] == '-')
	{
		d1 = -1;
		s.erase(0, 1);
		vt2--;
	} else d1 = 1;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '+' || s[i] == '-' || (s[i] == '*'))
		{
			dau = s[i];
			vt1 = i;
			break;
		}
		a += s[i];
	}
	for (int i = vt1 + 1; i < vt2; i++) b += s[i];
	//cout << a << " " << b << " " << c << endl;
}

void laydaubc()
{
	if (b[0] == '-')
	{
		d2 = -1;
		b.erase(0, 1);
	} else d2 = 1;
	
	if (c[0] == '-')
	{
		d3 = -1;
		c.erase(0, 1);
	} else d3 = 1;
}

ll chuyenso(string a, int x)
{
	ll res = 0;
	int l = a.length();
	for (int i = 0; i < l; i++)
	  if (a[i] == '?') res = res * 10 + x;
	  else res = res * 10 + a[i] - '0';
	if (a[0] == '?' && (x == 0) && l > 1) res += (++rd);
	return res;
}

int RES()
{
	int mark[20] = {0};
	for (int i = 0; i < s.length(); i++)
	  if ((s[i] >= '0') && (s[i] <= '9')) mark[s[i] - '0'] = 1;
	for (int i = 0; i < 10; i++)
	  if (!mark[i])
	  {
	  	ll aa, bb, cc;
	  	aa = chuyenso(a, i) * d1;
	  	bb = chuyenso(b, i) * d2;
	  	cc = chuyenso(c, i) * d3;
	  	if (dau == '+')
	  	{
	  		if (aa + bb == cc) return i;
	  	}
	  	if (dau == '-')
	  	{
	  		if (aa - bb == cc) return i;
	  	}
	  	if (dau == '*')
	  	{
	  		if (aa * bb == cc) return i;
	  	}
	  }
	return -1;
}

main()
{
//	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		cin >> s;
		tachxau();
		laydaubc();
		cout << RES() << endl;
	}
}