#include<iostream>
using namespace std;
long long x1,x2,x3;
long long y1,y2,y3;
int res=0;
main()
{
cin>>x1>>y1>>x2>>y2>>x3>>y3;
long long hx21,hy21,hx32,hy32;

// khoi tao HIEU
hx21=x2-x1;
hy21=y2-y1;
hx32=x3-x2;
hy32=y3-y2;

if ((hx21*hx32) != (-hy21*hy32)) cout<<"TOWARDS"; else
//1 12h
if ((hx21==0)&&(hy21>0))
{
	if (hx32>0) res=1; else res=2;
} else
//2 6h
if ((hx21==0)&&(hy21<0))
{
	if (hx32<0) res=1; else res=2;
} else
//3 3h
if ((hy21==0)&&(hx21>0)) 
{
	if (hy32<0) res=1; else res=2;
} else 
//4 9h
if ((hy21==0)&&(hx21<0))
{
	if (hy32>0) res=1; else res=2;
} else 
//5 11h
if ((hx21<0)&&(hy21>0))
{
	if (hy32>0) res=1; else res=2;
} else 
//6 2h
if ((hx21>0)&&(hy21>0))
{
	if (hy32<0) res=1; else res=2;
} else 
//7 4h
if ((hx21>0)&&(hy21<0))
{
	if (hy32<0) res=1; else res=2;
} else 
//8 8h
if ((hx21<0)&&(hy21<0))
{
	if (hx32<0) res=1; else res=2;
}
if (res==1) cout<<"RIGHT";
if (res==2) cout<<"LEFT";
}