#include<iostream>
#include<string.h>
using namespace std;
long n;
long long res,a[100001],b[100001];
char s[100001];
main()
{
	cin>>s;
	n=strlen(s);
	for (long i=0;i<=n-1;i++) a[i+1]= int(s[i]) %39;
	b[n]=0;
	for (long i=n-1;i>=1;i--)
	  if ((a[i]==1)||(a[i]!=a[i+1])) b[i]=b[i+1]; else b[i]=b[i+1]+1;
	res=0;
	for (long i=2;i<=n-2;i++)
	  if ((a[i]==a[i-1])&&(a[i]==1)) res+=b[i+1];
	cout<<res;
}