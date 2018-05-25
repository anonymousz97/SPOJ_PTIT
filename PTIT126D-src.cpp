#include<iostream>
#include<math.h>
using namespace std;
long k,x,y;
main()
{
	cin>>k;
	while (k!=0)
	{
		x=0;
		for (int i=1;i<=k;i++)
		{
			cin>>y;
			for (int j=1;j<=(y-x);j++) cout<<i<<" ";
			x=y;
		}
		cout<<endl;
		cin>>k;
    }
}