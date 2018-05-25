#include <iostream>
#include <string>
using namespace std;
string a, b, tong, hieu, tich;

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

string tru(string a, string b)
{
	string s = "";
	long l1 = a. length(),
		 l2 = b. length();
	for (long i = l1 + 1; i <= l2; i++) a = "0" + a;
	for (long i = l2 + 1; i <= l1; i++) b = "0" + b;
	string dau;
	if (a >= b) dau = "";
	else
	{
		dau = "-";
		string ss = a;
		a = b;
		b = ss;
	}
	long nho = 0;
	l1 = a.length();
	for (long i = l1 - 1; i >= 0; i--)
	{
		long x = int (a[i]) - int (b[i]) - nho;
		if (x < 0) 
		{
			x += 10;
			nho = 1;
		} else nho = 0;
		s = char (x + 48) + s;
	}
	while ((s != "") && (s[0] == '0')) s.erase(0, 1);
	s = dau + s;
	if (s == "") s = "0";
	return s;
}

/*
string nhan(string a, string b)
{
	string s = "";
	long k = 0;
	long l2 = b.length();
	for (long i = l2 - 1; i >= 0; i--)
	{
		long x = int (b[i]) - 48;
		string ss = "" ;
		for (long j = 1; j <= x; j++) ss = cong(ss, a);
		for (long j = 1; j <= k; j++) ss += "0";
		k++;
		s = cong(s, ss);
	}
	return s;
} */

/*string nhan(string a, string b)
{
	string s = "";
	long k = 0;
	long l2 = b.length(), l1 = a.length();
	for (long i = l2 - 1; i >= 0;  i--)
	{
		long nho = 0;
		long p = int (b[i]) - 48;
		string ss = "";
		for (long j = l1 - 1; j >= 0; j--)
		{
			long x = int (a[j]) - 48;
			x = x * p + nho;
			nho = x / 10;
			x = x % 10;
			ss = char (x + 48) + ss;
		}
		if (nho != 0) ss = char (nho + 48) + ss;
		for (long j = 1; j <= k; j++) ss += "0";
		k++;
		s = cong(s, ss);
	}
	return s;
} */
/*void Multiply(string x, string y)
{
	int k = a.length() + b.length();
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
	if(d==k) cout<<0;
	else for(int i=d;i<k;i++) cout<<c[i];
} */

string Multiply(string x, string y)
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


main()
{
	cin >> a;
	cin >> b;
	
	tong = cong(a, b);
	hieu = tru(a, b);
	cout << tong << endl;
	cout << hieu << endl;
	tich = Multiply(a, b);
	cout << tich;
}