#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void main()
{char messg[10];
int n,i=0,count=0;
printf("\n enter sender side ");
scanf("%s",messg);
n=strlen(messg);
for(i=0;i<n;i++)
{ if(messg[i]=='1')
   { 
    count=count+1;
   }
}
if(count%2!=0)
{messg[i]='1';
}
else
{
messg[i]='0';
}
printf("transmitted message %s",messg);
i=n-3;
if(messg[i]=='1')
messg[i]='0';
else
messg[i]='1';
printf("\n noised message %s",messg);
i=0;
count=0;
while(i<n)
{if(messg[i]=='1')
count++;
i++;
}
if(count%2!=0)
printf("\n error");
else
{printf("\n No error");
printf("\n %s ",messg);
}

}


