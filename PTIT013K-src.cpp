#include<iostream>
#include<math.h>
using namespace std;
int t;
long long n,gt[10];
main()
{
	cin>>t;
	gt[1]=1;
	for (long i=2;i<=9;i++) gt[i]=gt[i-1]*i;
	for (int k=1;k<=t;k++)
	{
		cin>>n;
		long long sum=0,d=0,x=n;
		while (x!=0)
		{
			d++;
			sum=sum+(x%10)*gt[d];
			x=x/10;
		}
		cout<<sum<<endl;
	}
}