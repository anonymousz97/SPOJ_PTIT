#include<iostream>
using namespace std;
main()
{
	unsigned long long res,n;
	cin>>n;
	if (n<=2) res=n; else
	if (n==4) res=12; else
	if (n==6) res=60; else
	if (n%2!=0) res=n*(n-1)*(n-2); else
	if (n%3==0) res= (n-1)*(n-2)*(n-3); else
	 res=n*(n-1)*(n-3);
	cout<<res;
}