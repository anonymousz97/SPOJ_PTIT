#include<iostream>
#include<math.h>
using namespace std;
main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int x,y,res;
	x=b-a-1;
	y=c-b-1;
	if (x>y) res=x;  else res=y;
	cout<<res;
}