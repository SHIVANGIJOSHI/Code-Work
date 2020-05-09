#include<stdio.h>
#include<stdlib.h>
int add(int,int,int);
int com(int); 
int main()
{
int i,j;
int A[8],R[8],checksum[8],B[8];
static int c=0;
printf("\n sender side");
printf("\n enter the message");
for(j=0;j<8;j++)
{scanf("%d",&A[j]);
}
printf("\n-----\n");
for(j=0;j<8;j++)
{scanf("%d",&B[j]);
}
for(j=7;j>=0;j--)
{
R[j]=add(A[j],B[j],c);
printf("%d   ",B[i]);
}
for(j=0;j<8;j++)
{checksum[j]=com(R[j]);
printf("%d   ",checksum[i]);
}
return 0;
}
int add(int x,int y,int c)
{
if(x==1&&y==1&&c==0)
{c=1;
return 0;
}
else if(x==1&&y==1&&c==1)
{c=1;
return 1;
}
else if(x==1&&y==0&&c==0)
{c=0;
return 1;
}
else if(x==1&&y==0&&c==1)
{c=1;
return 0;
}
else if(x==0&&y==1&&c==0)
{c=0;
return 1;
}
else if(x==0&&y==1&&c==1)
{c=1;
return 0;
}
else if(x==0&&y==0&&c==0)
{c=0;
return 0;
}
else 
{c=0;
return 1;
}

}
 
int com(int a)
{if(a==0)
return 1;
else 
return 0;
}
