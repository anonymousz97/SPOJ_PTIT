#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long long x,y,z;
	cin>>x>>y>>z;
	while (x!=0)
	{
		if ((x*x==y*y+z*z) || (y*y==x*x+z*z) || (z*z==x*x+ y*y)) cout<<"right"<<endl; else cout<<"wrong"<<endl;
		cin>>x>>y>>z;
	}
}