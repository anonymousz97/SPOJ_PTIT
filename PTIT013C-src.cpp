#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long long x1,x2,y1,y2,n;
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		if (y1*y2>0) y2=-y2;
		cout<<(long long)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<<endl;
	}
}