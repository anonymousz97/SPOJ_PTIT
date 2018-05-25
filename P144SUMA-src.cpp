#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
char s[2];
long a[100002],f[100002],n;
main()
{
	cin>>n;
	for (long i=1;i<=n;i++)
	{
		cin>>s;
		if (strcmp(s,"10")==0) a[i]=1; else a[i]=2;
	}
	f[1]=1;;
	for (long i=2;i<=n;i++)
	  if (a[i]==a[i-1]) f[i]=f[i-1]; 
	  else f[i]=f[i-1]+1;
	cout<<f[n];
}
