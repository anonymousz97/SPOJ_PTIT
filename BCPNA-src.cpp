#include<iostream>
#include<math.h>
using namespace std;
long a[100001],nt[100001],t,n,res,top;
void sangnt(long n)
{
	top=0;
	for (long i=2;i<=n;i++) nt[i]=0;
	for (long i=2;i<=n;i++)
	 if (nt[i]==0)
	 {
	 	top++;
	 	a[top]=i;
	 	long long j=(long long) i*i;
	 	while (j<=n)
	 	{
	 		nt[j]=1;
	 		j=j+i;
	 	}
	 }
}

main()
{
	sangnt(100000);
	cin>>t;
	for (long k=1;k<=t;k++)
	{
		cin>>n;
		long long sum=a[1];
		long d=1,c=1;
		res=0;
		if (n==2) cout<<1<<endl; else{
		
		while (d<=c)
		{
			while ((c<top)&&(sum<n))
			{
				c++;
				sum=sum+a[c];
				if (sum==n) res++ ;
			}
			if ((c==top)&&(sum<=n)) break;
			while ((d<=c)&&(sum>=n))
			{
				sum=sum-a[d];
				d++;
				if (sum==n) res++;
			}
			if (d>=n) break;
		}	
		cout<<res<<endl;}
	}
	
}