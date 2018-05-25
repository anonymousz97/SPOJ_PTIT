#include<stdio.h>
#include<math.h>
main()
{
	long n,x,y,z;
	scanf("%d",&n);
	for (long i=1;i<=n;i++)
	{
		scanf("%d",&x);
		y=x;z=0;
		while (y!=0)
		{
			z=z*10+y%10;
			y=y/10;
		}
		if (x==z) printf("YES\n"); else printf("NO\n");
	}
}

