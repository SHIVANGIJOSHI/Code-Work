#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,j,k,temp=0, flag=0;
int M[15],r[4],T[20];
int g[4]={1,1,0,1};
//sender side
printf("\n enter message\n");
for(k=0;k<7;k++)
{scanf("%d",&M[k]);
}
printf("\n");
for(k=0;k<7;k++)
{T[k]=M[k];
}
for(k;k<11;k++)
{T[k]=0;
}
printf("\n");
for(k=0;k<10;k++)
{printf("%d\t",T[k]);
}
//crc implementation
for(i=0;i<9;i++)
{temp=i;
 if(T[i]==1)
  {for(j=0;j<4;j++)
   {if(T[temp]==g[j])
    {T[temp]=0;
     r[j]=0;
    }
    else
     {T[temp]=1;
      r[j]=1;
     }
   temp=temp+1;
   }
 }
}
printf("\n remainder\n");
for(k=1;k<4;k++)
{printf("%d\t",r[k]);
}
for(k=3;k>0;k--)
M[k+6]=r[k];
printf("\n SENDER SIDE\n");
for(k=0;k<10;k++)
printf("%d\t",M[k]);
//receiver side
for(i=0;i<10;i++)
{temp=i;
if(M[i]==1)
{
for(j=0;j<4;j++)
{
if(M[temp]==g[j])
{M[temp]=0;
r[j]=0;
}
else
{M[temp]=1;
r[j]=1;
}
temp=temp+1;
}}}
printf("\n receiver side");
printf("\n remainder\n");
for(k=0;k<4;k++)
{printf("%d",r[k]);
if(r[k]!=0)
{flag=1;
}
}
if(flag==0)
{printf("\n no error");
}
else
{printf("\n error");
}

}
