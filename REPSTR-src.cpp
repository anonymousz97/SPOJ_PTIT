#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
long m,n,a[100001],b[100001];
char s[100001];
main()
{
	cin>>s;
	n=strlen(s);
	for (long i=0;i<=n-1;i++) a[i+1]= int (s[i]) -48;
	cin>>s;
	m=strlen(s);
	for (long i=0;i<=m;i++) b[i+1]= int (s[i]) -48;
	sort(b+1,b+1+m);
	long i=1,j=m;
	while ((i<=n)&&(j>0))
	{
		if (a[i]>=b[j]) cout<<a[i];
		else
		 if	(a[i]<b[j]) 
		 	{
		 		cout<<b[j];
		 		j--;
		 	}
		i++;
	}
	if (i<=n) 
		for (long j=i;j<=n;j++) cout<<a[j];
}