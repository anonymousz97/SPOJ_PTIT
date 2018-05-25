#include<iostream>
#include<string.h>
using namespace std;
char s[1001];
long d,t,a[1002];
main()
{
	cin>>t;
	for (long q=1;q<=t;q++)
	{
		cin>>s;
		long n=strlen(s);
		for (long i=0;i<=n-1;i++) a[i+1]=int (s[i]) -48;
		a[n+1]=a[n]+1;
		d=1;
		for (long i=2;i<=n+1;i++)
		 if (a[i]==a[i-1]) d++;
		 else
		 	{
		 		cout<<d<<a[i-1];
		 		d=1;
		 	}
		cout<<endl;
	}
}