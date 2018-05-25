#include<iostream>
#include<math.h>
using namespace std;

long long n,nmax=123456*2+1;
bool ck[123456*2+1];
long long d[123456*2+1];
void snt(long long n)
{
	for (long long i=1;i<=n;i++)
	{ ck[i]=true;
	  d[i]=0;
    } 
    ck[1]=false;
	for (long long i=2;i<=n;i++)
	  if (ck[i])
	  {
	  	d[i]=d[i-1]+1;
	  	long long j=i*i;
	  	while (j<=n) 
	  	{
	  		if (ck[j]) ck[j]=false;
	  		j=j+i;
	  	}
	  } else d[i]=d[i-1];
}


main()
{
	cin>>n;
	snt(nmax);
	while (n!=0) 
	{
		long long count;
		count=d[2*n]-d[n];
		//if (ck[n]) count++;
		cout<<count<<endl;
		cin>>n;
	}
}
