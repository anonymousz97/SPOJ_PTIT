#include<iostream>
using namespace std;
int n,k;
main()
{
	cin>>n;
	k=n;
	for (int i=0;i<=n;i++)
	{
		for (int j=1;j<=k;j++) cout<<"  ";
		for (int j=0;j<=i;j++) cout<<j<<" ";
		for (int j=i-1;j>=0;j--) cout<<j<<" ";
		for (int j=1;j<=k-1;j++) cout<<"  ";
		cout<<" "<<endl;
		k--;
	}
	k=1;
	for (int i=n-1;i>=0;i--)
	{
		for (int j=1;j<=k;j++) cout<<"  ";
		for (int j=0;j<=i;j++) cout<<j<<" ";
		for (int j=i-1;j>=0;j--) cout<<j<<" ";
		for (int j=1;j<=k-1;j++) cout<<"  ";
		cout<<" "<<endl;
		k++;
	}
}