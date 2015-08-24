#include "stdio.h"
main()
{
int a[10],*p;
int i,n,t;
p=a;
for(i=0;i<10;i++)
{
scanf("%d",p);
p++;
}
for(n=0;n<5;n++)
{t=a[n];
a[n]=a[9-n];
a[9-n]=t;
}
for(i=0;i<10;i++) 
	printf("%4d",a[i]);
}
