#include<iostream>
#include<math.h>
using namespace std;

long h( long n)
{
	long d=1;
	while (n!=1)
	{
		d++;
		if (n%2==0) n=n/2; else n=n*3+1;
	}
	return d;
}
main()
{
	long n;
	cin>>n;
	while (n!=0)
	{
		cout<<h(n)<<endl;
		cin>>n;
	}
}