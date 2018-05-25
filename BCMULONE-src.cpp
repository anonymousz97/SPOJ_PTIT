#include<iostream>
using namespace std;
main()
{
	long i,j,k,t,n;
	cin>>t;
	for (j=1;j<=t;j++)
	{
		cin>>n;
		for (i=1;i<=(n-1)/9;i++) cout<<"123456790";
		k=(n-1)%9;
		for (i=1;i<=k;i++) cout<<char(48+i);
		for (i=k+1;i>=2;i--) cout<<char(48+i);
		for (i=1;i<=(n-1)/9;i++) cout<<"098765432";
		cout<<"1"<<endl;
	}
}
