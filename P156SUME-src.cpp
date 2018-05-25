#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s1, s2;
int l1, l2;
int n, t, res;
int st[100005];

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);	
}

int kiemTra(int l)
{
	string s3, s4 = "";
	if (l1 > l2)
	{
		s3 = s1.substr(0, l);
		for (int i = 1; i <= l1/l; i++) s4 += s3;
	}
	else
	{
		s3 = s2.substr(0, l);
		for (int i = 1; i <= l2/l; i++) s4 += s3;
	}
	for (int i = 0; i < l1; i++)
	  if (s1[i] != s4[i]) return 0;
	for (int i = 0; i < l2; i++)
	  if (s2[i] != s4[i]) return 0;
	return 1;
}

main()
{
	cin >> s1 >> s2;
	l1 = s1.length();	
	l2 = s2.length();
	n = gcd(l1, l2);
	t = 0;
	for (int i = 1; i <= n; i++)
	  if (n % i == 0) st[++t] = i;
	res = 0;
	for (int i = 1; i <= t; i++)
	  if (kiemTra(st[i])) res++;
	cout << res;	
}
