#include<iostream>
#include<math.h>
using namespace std;
long n,a[100002];
long long f[1002][1002];
main()
{
	cin>>n;
	for (long i=1;i<=n;i++)
	  for (long j=1;j<=n;j++) cin>>f[i][j];
	f[n][n+1]=f[1][n];
	long long sum=0;
	for (long i=1;i<=n;i++) sum=sum+f[i][i+1];
	sum=sum/2;
	for (long j=1;j<=n;j++)
	{
		f[0][j]=0;
		for (long i=1;i<=n;i++) f[0][j]=f[0][j]+f[i][j];
	}
	for (long i=1;i<=n;i++) a[i]=(f[0][i]-sum)/(n-2);
	for (long i=1;i<=n;i++) cout<<a[i]<<" ";
}