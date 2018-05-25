#include <iostream>
#include <string>
#define ll long long
using namespace std;
const ll mod = 1000000007;
string s, t;
ll m, n, top;
ll st[1000006], hashS[1000006], pow[1000006];
ll hashT;

void setPow()
{
	pow[0] = 1;
	for (int i = 1; i <= m; i++) pow[i] = pow[i - 1] * 26 % mod;
}

void getHashT()
{
	hashT = 0;
	for (int i = 1; i <= n; i++) hashT = (hashT * 26 + t[i] - 'a') % mod;
}

void BuildHashS()
{
	hashS[0] = 0;
	for (int i = 1; i <= m; i++) hashS[i] = (hashS[i - 1] * 26 + s[i] - 'a') * mod;
}

void Init()
{
	top = 0;
	m = s.length();
	n = t.length();
	s = "*" + s;
	t = "*" + t;
	hashS[0] = 0;
	setPow();   // cai luy thua 26
	getHashT();	// lay duoc ma Hash cua T
//	BuildHashS();
}


ll getHashS(ll i, ll j)
{
	return (hashS[j] - hashS[i - 1] * pow[j - i + 1] + mod * mod) % mod;
}


void push(ll x)
{
	top++;
	st[top] = x;
	hashS[top] = (hashS[top - 1] * 26 + x) % mod;
}

void Process()
{
	for (int i = 1; i <= m; i++)
	{
		push(s[i] - 'a');
		if (top >= n)
		{
			ll h = getHashS(top - n + 1, top);
			if (h == hashT) top -= n;
		}
	}	
}

main()
{
	cin >> s >> t;
	Init();
	Process();
	for (int i = 1; i <= top; i++) cout << char (st[i] + 'a');
}
