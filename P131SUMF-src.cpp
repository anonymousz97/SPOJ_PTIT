#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define x first
#define y second
using namespace std;
const ll mod = 1000000007;
const ll mod2 = 1000000009;
ll r, c, n;
char x[1005][1005];
string s[1005];
ll pow[1005], pow2[1005], hash2[1005][1005], hash[1005][1005], v[1005], v2[1005];

ll res;

typedef pair <ll, ll> record;
record q[1005];

void Init()
{
	//for (int i = 1; i <= c; i++) cout << s[i] << endl;
	n = c;
	pow[0] = 1;
	pow2[0] = 1;
	for (int i = 1; i <= r; i++)
	{
		pow[i] = pow[i - 1] * 26 % mod;
		pow2[i] = pow2[i - 1] * 26 % mod2;
	}
}

ll getHash(int k, int i, int j)
{
	return (hash[k][j] - hash[k][i - 1] * pow[j - i + 1] + mod * mod) % mod;
}

ll getHash2(int k, int i, int j)
{
	return (hash2[k][j] - hash2[k][i - 1] * pow2[j - i + 1] + mod2 * mod2) % mod2;
}

void tinhH(int k)
{
	string x = s[k];
	hash[k][0] = 0;
	for (int i = 1; i <= r; i++) hash[k][i] = (hash[k][i - 1] * 26 + x[i] - 'a') % mod;
}

void tinhH2(int k)
{
	string x = s[k];
	hash2[k][0] = 0;
	for (int i = 1; i <= r; i++) hash2[k][i] = (hash2[k][i - 1] * 26 + x[i] - 'a') % mod2;
}

int STOP()
{
	ll q2[1005];
	for (int i = 1; i <= n; i++) 
	{
		q[i].x = v[i];
		q[i].y = i;
	}
	for (int i = 1; i <= n; i++) q2[i] = v2[i];
	
	sort(q + 1, q + 1 + n);
	
	for (int i = 2; i <= n; i++)
	  if (q[i].x == q[i - 1].x && q2[q[i].y] == q2[q[i - 1].y]) return 1;
	
	  
	return 0;
}

void Xoa(int k)
{
	for (int i = 1; i <= n; i++) v[i] = getHash(i, k + 1, r);
	for (int i = 1; i <= n; i++) v2[i] = getHash2(i, k + 1, r);
}

void Process()
{
	for (int i = 1; i <= n; i++) tinhH(i);
	for (int i = 1; i <= n; i++) tinhH2(i);
	res = 0;
	for (int i = 1; i < r; i++)
	{
		Xoa(i);
		if (STOP()) break;
		res++;
	}
	return;
}

main()
{
//	freopen("in.txt", "r", stdin);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	  for (int j = 1; j <= c; j++) cin >> x[i][j];
	for (int j = 1; j <= c; j++)
	{
		s[j] = "*";
		for (int i = 1; i <= r; i++) s[j] += x[i][j];
	}
	Init();	
	Process();	
	cout << res;
}