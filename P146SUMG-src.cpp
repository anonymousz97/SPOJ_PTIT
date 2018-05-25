#include<iostream>
#include<string.h>
using namespace std;
char s[501];
long r,c,a,b;
main()
{
	cin>>r>>c>>a>>b;
	for (long i=1;i<=r;i++)
	{
		
		cin>>s;
		for (long k=1;k<=a;k++)
		{
			for (long j=0;j<=c-1;j++)
				for (long p=1;p<=b;p++) cout<<s[j];
			cout<<endl;
		}
	}
}