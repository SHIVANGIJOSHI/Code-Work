#include<stdio.h>
#include<string.h>

void main()
{
int i=0,j=0,n=0,t=0;
char O[20],S[100],R[50];
printf("\n enter string ");
scanf("%s",O);
n=strlen(O);
S[0]='d';
S[1]='l';
S[2]='e';
S[3]=' ';
S[4]='s';
S[5]='t';
S[6]='x';
S[7]=' ';
j=8;
while(i<n)
{
 if(O[i]=='d'&&O[i+1]=='l'&&O[i+2]=='e'&&O[i+3]=='E'&&O[i+4]=='S'&&O[i+5]=='C')
  {S[j]='E';
 S[j+1]='S';
 S[j+2]='C';
 j=j+3;
 S[j+3]='E';
 S[j+4]='S';
 S[j+5]='C';
 j=j+3;
  }
if(O[i]=='d'&&O[i+1]=='l'&&O[i+2]=='e')
 {S[j]='E';
S[j+1]='S';
S[j+2]='C';
j=j+3;
 }
if(O[i]=='E'&&O[i+1]=='S'&&O[i+2]=='C')
 {S[j]='E';
S[j+1]='S';
S[j+2]='C';
j=j+3;
S[j]=O[i];
S[j+1]=O[i+1];
S[j+2]=O[i+2];
i=i+3;
j=j+3;
}
else{
S[j]=O[i];
j++;
i++;
}}
S[j]=' ';
S[j+1]='e';
S[j+2]='t';
S[j+3]='x';
S[j+4]=' ';
S[j+5]='d';
S[j+6]='l';
S[j+7]='e';
S[j+8]='\0';
printf("\n sender side:\n");
printf("%s",S);
//receiver side
i=0;
j=0;
t=strlen(S);
while(i<t)
{
 
if(S[i]=='E'&&S[i+1]=='S'&&S[i+2]=='C')
 {R[j]=S[i+3];
R[j+1]=S[i+4];
R[j+2]=S[i+5];
j=j+3;
i=i+6;
 }

R[j]=S[i];
j++;
i++;

}
printf("\n receiver side:\n");
printf("%s",R);
}

