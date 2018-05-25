#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define X first
#define Y second
using namespace std;
const ll nmax = 5005;
const ll pmax = 20000;
ll n, p[pmax] = {0}, a[pmax] = {0}, b[pmax] = {0}, c[pmax] = {0};

string nhan(string x, string y)
{
	int k = x.length() + y.length();
	int c[k];
	int t;
	for(t=0;t<k;t++) c[t]=0;
	for(int i=x.length()-1;i>=0;i--){
		if(x[i]==48) continue;
		for(int j=y.length()-1;j>=0;j--){
			if(y[j]==48) continue;
			t=k-1-x.length()+1+i-y.length()+1+j;
			int p=((int)x[i]-48)*((int)y[j]-48);
			while(p>0){
				c[t]+=p%10;
				p/=10;
				p+=c[t]/10;
				c[t]%=10;
				t--;
			}
		}
	}
	int d=0;
	while(d<k&&c[d]==0) d++;
	if(d==k) return "0";
	else
	{
		 string s = "";
		 for(int i=d;i<k;i++) s+= char (c[i] + 48);
		 return s;
	}
}

void PT(ll n, ll a[]){
	FOR(i, 2, n){
		if (!p[i]){
			ll m = n, j = i;
			while (m/j > 0){
				a[i] += m/j;
				j *= i;
			}
		}
	}
}

string chuyen(int n)
{
	string ans = "";
	while (n > 0)
	{
		int x = n % 10;
		ans = char (x + '0') + ans;
		n /= 10;
	}
	return ans;
}

void Process(){
	PT(2 * (n + 1), a);
	PT(n + 1, b);
	PT(n + 2, b);
	string res = "1";
	FOR(i, 2, 2 * n + 2) c[i] = a[i] - b[i];
	FOR(i, 2, 2 * n + 2){
		if (c[i]){
			string s = chuyen(i);
			FOR(j, 1, c[i]) res = nhan(res, s);
		}
	}
	cout << res;
}

void SNT(){
	for (ll i = 2; i < pmax; i++){
		if (!p[i]){
			for (ll j = i * i; j < pmax; j += i) p[j] = 1;
		}
	}
}

main(){
	cin >> n;
	SNT();
	Process();
}
