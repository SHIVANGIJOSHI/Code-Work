#include<stdio.h>
#include<stdlib.h>
void main()
{int k=0,n=0,m=0,r=0,i=0,temp=0,count=0,w=0,RT[20];
printf("\n enter no. of packets");
scanf("%d",&n);
printf("\n enter the lost packet");
scanf("%d",&m);
printf("\n enter the window size");
scanf("%d",&w);
for(i=1;i<=n;i++)
{
count++;
if(count==m)
{k=0;
temp=i;
printf("\n %d",i);
while(k<w&&temp<=n)
{RT[k+r]=temp;
printf("\n ***%d",RT[k+r]);
temp++;
k++;

}

if(temp>n)
{r+=w-1;
if(k==w)
{count=w-1;
r++;}
else
count=w-2;
}
else
{r+=w;
count=w-1;
}
i--;
continue;
}
}
printf("\n no. of transmission count %d \n",r+n);
for(i=0;i<r;i++)
{printf("%d \t",RT[i]);}

}
