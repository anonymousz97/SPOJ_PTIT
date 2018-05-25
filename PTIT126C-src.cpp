#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long long s,sum,a[100001];
	long n,t,res,d,c;
	cin>>t;
	for (int k=1;k<=t;k++)
	{
		cin>>n>>s;
		for (long i=1;i<=n;i++) cin>>a[i];
		if (a[1]>=s) res=1; else
		{
			d=1;c=1;sum=a[1];res=n+1;
			while (d<=c)
			{
				while ((c<n)&&(sum<s))
				{
					c++;
					sum=sum+a[c];
					if (sum>=s)
					if ((c-d+1)<res) res=c-d+1;
				}
				if ((c==n)&&(sum<=s)) break;
				
				while ((d<=c)&&(sum>=s))
				{
					sum=sum-a[d];
					d++;
					if ((d<=c)&&(sum>=s)) 
					if ((c-d+1)<res) res=c-d+1;
				}
			}
		}
		if (res==n+1) res=0;
		cout<<res<<endl;	
	}
}