#include<stdio.h>

void main()
{
int a[20],b[30],c[20],i,j,k,count,n;
printf("\n enter frame size ");
scanf("%d",&n);
printf("\n enter frame data\n");
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
}
i=0;
count=1;
j=0;
while(i<n)
{if(a[i]==1)
 {b[j]=a[i];
  for(k=i+1;a[k]==1&&k<n&&count<5;k++)
   {j++;
    b[j]=a[k];
    count++;
     if(count==5)
      {j++;
       b[j]=0;
      }
       i=k;
   }
 }
 else
 {b[j]=a[k];
 }
i++;
j++;
}
printf("After bit stuffing\n");
for(i=0;i<j;i++)
{printf(" %d ",b[i]);
}
i=0;
j=0;
k=0;
count=1;
while(i<=n)
{if(b[i]==1)
{c[j]=b[i];
for(k=i+1;b[k]==1&&k<n+1&&count<5;k++)
   {j++;
    c[j]=b[k];
    count++;
     if(count==5)
      {j++;
       k=k+2;
       c[j]=b[k];
      }
       i=k;
   }
 }
 else
 {c[j]=b[i];
 }
i++;
j++;
}
printf("\nAfter removing bit stuffing\n");
for(i=0;i<j;i++)
{printf(" %d ",c[i]);
}
}
