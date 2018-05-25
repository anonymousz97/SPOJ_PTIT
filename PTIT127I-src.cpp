#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long n,c[50];
	cin>>n;
	while (n!=0)
	{
		for (long i=1;i<=50;i++) c[i]=0;
		for (long i=1;i<=n;i++)
		  for (long j=1;j<=6;j++)
		   {
		   	int x;
		   	cin>>x;
		   	c[x]=1;
		   }
		bool ck=true;
		for (long i=1;i<=49;i++)
		  if (c[i]==0)
		  {
		  	ck=false;
		  	break;
		  }
		if (ck) cout<<"Yes"<<endl; else cout<<"No"<<endl;
		cin>>n;
	}
}