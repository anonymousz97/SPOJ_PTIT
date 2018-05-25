#include <iostream>
#include <string>
using namespace std;

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
	if(d==k) return x;
	else
	{
		 string s = "";
		 for(int i=d;i<k;i++) s+= char (c[i] + 48);
		 return s;
	}
}

long kiemTra(string a, string b)
{
	long m = a.length();
	long n = b.length();
	string s = a + a;
	for (long i = 0; i < n; i++)
	{
		string ss = s.substr(i, n);
		if (ss == b) return 1;
	}	
	return 0;
}

string xau(long n)
{
	string s = "";
	while (n != 0)
	{
		long x = n % 10;
		s = char (x + 48) + s;
		n /= 10;
	}
	return s;
}

long soVong(string s)
{
	long n = s.length();
	for (long i = 1; i <= n; i++)
	{
		if (!kiemTra(s, nhan(s, xau(i)))) return 0;
	}
	return  1;
}

main()
{
	string s;
	while ((getline(cin, s)) && (s != ""))
	{
		if (soVong(s)) cout << s << " is cyclic";
		else cout << s << " is not cyclic";
		cout << endl;
	}
}