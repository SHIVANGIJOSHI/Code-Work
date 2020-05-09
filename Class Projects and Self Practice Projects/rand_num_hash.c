#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{int data;
struct node *link;
};

struct node *bucks[33];

void addtolist(int,int);
void printlist(void);
int search_list(int,int);

int main()
{int num,sflag;
char ch=' ';
while(1)
{printlist();
printf("\nDO YOU WANT TO GENERATE A RANDOM NUMBER? (Y/N):");
scanf(" %c",&ch);
ch=tolower(ch);
if(ch!='y')
break;
num=rand()%(32767-0+1)+0; 
//printf("\n%d",num);
sflag=search_list(num/1000,num);
if(sflag)
 printf("\n%d IS PRESENT IN THE LIST",num);
else
{printf("\n%d NOT PRESENT IN THE LIST",num);
printf("\nADD IT TO THE LIST(Y/N):");
scanf(" %c",&ch);

if(tolower(ch)=='y')
 addtolist(num/1000,num);
}
}
printf("\nTHANKS FOR USING MY RANDOM NUMBER GENERATOR USING HASHING-SJ\n");
return 0;
}

void printlist(void)
{struct node *p;
int i;
printf("list: \n");
for(i=0;i<33;i++)
{p=bucks[i];
while(p!=NULL)
{printf("%d\t",p->data);
p=p->link;
}
}
}

int search_list(int index,int data)
{struct node *p;
p=bucks[index];

if(p==NULL)
return 0;
else
{while(p!=NULL)
{if(p->data==data)
 return 1;
else
 p=p->link;
}return 0;
}
}

void addtolist(int index,int data)
{
struct node *q,*r,*temp;
temp=q=bucks[index];
r=malloc(sizeof(struct node));
r->data=data;
if(q==NULL||q->data>data)
{q=r;
q->link=temp;
bucks[index]=q;
}
else
{while(temp!=NULL)
{if((temp->data<data)&&(temp->link->data>data)||(temp->link==NULL))
{r->link=temp->link;
temp->link=r;
return;
}
temp=temp->link;
}
r->link=NULL;
temp->link=r;
}
}
