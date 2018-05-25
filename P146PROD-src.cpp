#include<iostream>
using namespace std;
main()
{
	int x,y,z,s,n,d;
	cin>>n;
	d=0;
	for (long i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		s=x+y+z;
		if (s>=2) d++;
	}
	cout<<d;
}