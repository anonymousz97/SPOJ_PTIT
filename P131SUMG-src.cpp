#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long long m,n;
	cin>>m>>n;
	while (m!=0)
	{
		long long k=m*n;
		while (n!=0)
		{
			long long t=m%n;
			m=n;
			n=t;
		}
		cout<<m<<" "<<k/m<<endl;
		cin>>m>>n;
	}
}