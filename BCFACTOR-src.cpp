#include<stdio.h>
#include<math.h>
main()
{long n,d;
scanf("%d",&n);
d=0;
for (long i=2;i<=long(sqrt(n));i++)
{while (n%i==0)
{d++;
n=n/i;
}
if (d!=0) 
{printf("%d %d\n",i,d);
d=0;
}
}
if (n>1) printf("%d 1",n);
}
