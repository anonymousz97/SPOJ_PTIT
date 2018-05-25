#include <iostream>
#include <string>
using namespace std;
long n;
string b[51];

string cong(string a, string b)
{
	string s = "";
	long l1 = a. length(),
		 l2 = b. length();
	for (long i = l1 + 1; i <= l2; i++) a = "0" + a;
	for (long i = l2 + 1; i <= l1; i++) b = "0" + b;
	long nho = 0;
	l2 = b.length();
	for (long i = l2 - 1; i >= 0; i--)
		{
			long x = int (a[i]) + int (b[i]) - 96 + nho;
			nho = x / 10;
			x = x % 10;
			s = char (x + 48) + s;
		}
	if (nho) s = "1" + s;
	return s;
}

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

long ptich(long n, long a[])
{
	for (long i = 2; i <= n; i++)
	{
		while ((n > 0) && (n % i == 0))
		{
			a[i]++;
			n /= i;
		}
	}
	if (n > 1) a[n]++;
}

string xau(long n)
{
	string s = "";
	while (n > 0)
	{
		long x = n % 10;
		s = char (x + 48) + s;
		n /= 10;
	}	
	return s;
}

string tohop(long k, long n)
{
	long a[51], b[51], c[51];
	for (long i = 0; i <= n; i++) a[i] = 0;
	for (long i = 0; i <= n; i++) b[i] = 0;
	for (long i = n - k + 1; i <= n; i++) ptich(i, a);
	for (long i = 1; i <= k; i++) ptich(i, b);
	for (long i = 0; i <= n; i++) c[i] = a[i] - b[i];
	string res = "1";
	for (long i = 1; i <= n; i++)
	{
		string x = xau(i);
		for (long j = 1; j <= c[i]; j++) res = nhan(res, x);
	}
	return res;
	
}

void buildBell()
{
	b[0] = "1";
	b[1] = "1";
	for (long i = 2; i <= 50; i++)
	{
		b[i] = "0";
		for (long k = 0; k < i; k++) b[i] = cong(b[i], nhan(tohop(k, i - 1), b[k]));
	}
		
}

main()
{
	buildBell();
	while ((cin >> n) && (n > 0)) cout << n << " " << b[n] << endl;
}