#include<iostream>
using namespace std;
double f,p,l,s,t;
main()
{
	cin>>t;
	for (long q=1;q<=t;q++)
	{
	
	cin>>p>>l>>f;
	l=l/100+1;
	s=p*l;
	long k=1;
	while (s<f)
	{
		k++;
		s*=l;
	}
	cout<<k<<endl;
	}
}