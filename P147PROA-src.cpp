#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long long x,y,z,tich;
	cin>>x>>y>>z;
	tich=sqrt(x*y*z);
	long long a,b,c;
	a=tich/x;
	b=tich/y;
	c=tich/z;
	long long res;
	res= 4* (a+b+c);
	cout<<res;
}