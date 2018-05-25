#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
long m,u,a,b,l,r,res,bb[100001],top;

long ucln(long a, long b)
{
	long m,n,t;
	m=a;n=b;
	while (n!=0)
	{
		t=m%n;
		m=n;
		n=t;
	}
	return m;
}

void uc(long n)
{
	top=0;
	for (long i=1;i<=sqrt(n);i++)
	 if (n%i==0)
	 {
	 	top++;
	 	bb[top]=i;
	 	if (i*i!=n) 
	 	{
	 		top++;
	 		bb[top]=n/i;
	 	}
	 }
	 sort(bb+1,bb+1+top);
}

long find(long l, long r)
{
	long d,c,mid,kq;
	d=1;c=top;kq=-1;
	while (d<=c)
	{
		mid=(d+c)/2;
		if ((l<=bb[mid])&&(bb[mid]<=r))
		{
			kq=bb[mid];
			d=mid+1;
		} else
		if (bb[mid]>r) c=mid-1; else
		if (bb[mid]<l) d=mid+1;
	}
	return kq;
}

main()
{
	cin>>a>>b>>m;
	u=ucln(a,b);
	uc(u);
	for (long i=1;i<=m;i++)
	{
		cin>>l>>r;
		res=find(l,r);
		cout<<res<<endl;
	}
}