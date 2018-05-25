#include<iostream>
#include<algorithm>
using namespace std;
main()
{
	int a[4],res;
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+1+3);
	if (a[2]-a[1]==a[3]-a[2]) res= 2*a[3] - a[2]; else
	if (a[2]-a[1]>a[3]-a[2]) res= (a[1]+a[2])/2;
	else res=(a[2]+a[3])/2;
	cout<<res;
}