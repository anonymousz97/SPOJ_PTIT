#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long n;
	cin>>n;
	long long s;
	for (long i=1;i<=n;i++)
	{
		cin>>s;
		long long sum,x;
		while (s>=10)
		{
			x=s;
			sum=0;
			while (x>0)
			{
				sum=sum+x%10;
				x=x/10;
			}
			s=sum;
		}
		cout<<s<<endl;
	}
}