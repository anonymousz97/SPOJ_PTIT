#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long n;
	long long m,s;
	cin>>n;
	for (long k=1;k<=n;k++)
	{
	cin>>m;
	s=0;
	for (long long i=1;i<=sqrt(m);i++)
	  if (m%i==0) 
	  {
	  	s=s+i+m/i;
	  	if (i*i==m) s=s-i;
	  }
	cout<<s<<endl;
    }
}