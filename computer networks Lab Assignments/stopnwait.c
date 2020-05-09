#include<stdio.h>
#include<stdlib.h>
void main()
{int n=0,m=0,r=0,i=0,count=0,RT[20];
printf("\n enter no. of packets");
scanf("%d",&n);
printf("\n enter the lost packet");
scanf("%d",&m);
for(i=1;i<=n;i++)
{
count++;
if(count==m)
{count=0;
RT[r]=i;
r++;
i--;
continue;
}
}
printf("\n no. of transmission count %d \n",r+n);
for(i=0;i<r;i++)
{printf("%d \t",RT[i]);}
}
