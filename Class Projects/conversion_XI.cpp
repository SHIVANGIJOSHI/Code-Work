#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void binary();
void octal();
void hexadec();
int main()
{
int i,ch=1;
do{
cout<<"\nCONVERSIONS MENU\n";
cout<<"1.BINARY CONVERSIONS\n";
cout<<"2.OCTAL CONVERSIONS\n";
cout<<"3.HEXADECIMAL CONVERSIONS\n";
cout<<"\nENTER YOUR CHOICE: ";
cin>>i;
switch(i)
{case 1: binary();
         break;
case 2:  octal();
         break;
case 3:  hexadec();
         break;
default: cout<<"\nWRONG CHOICE!!\n";
         break;
}
cout<<"\nWISH TO GO TO CONVERSIONS MENU(1/0): ";
cin>>ch;
}while(ch!=0);
cout<<"\nTHANKS FOR USING MY PROGRAM\n";
return 0;
}
//binary
void binary()
{int i,ch=1,num;
do{
cout<<"\nBINARY CONVERSIONS\n";
cout<<"1.BINARY TO DECIMAL CONVERSION\n";
cout<<"2.DECIMAL TO BINARY CONVERSION\n";
cout<<"\nENTER YOUR CHOICE: ";
cin>>i;
//1
if(i==1)
{cout<<"\nENTER BINARY NUMBER: ";
cin>>num; 
int dec_value=0; 
// 2^0=1(base) 
int base=1; 
int temp=num; 
while(temp)
{
int last_digit=temp % 10; 
temp=temp/10; 
dec_value+=last_digit*base; 
base=base*2; 
}
cout<<"EQUIVALENT DECIMAL NUMBER: "; 
cout<<dec_value; 
}
//2
else if(i==2)
{cout<<"\nENTER DECIMAL NUMBER: ";
cin>>num; 
int binaryNum[32];  
int k=0; 
while(num>0) 
{ 
// storing remainder (1 or 0) 
binaryNum[k]=num%2; 
num=num/2; 
k++; 
} 
cout<<"EQUIVALENT BINARY NUMBER: ";
for(int j=k-1;j>=0;j--) 
cout<<binaryNum[j];  
}
//wrong choice
else
{cout<<"\nWRONG CHOICE!!";
}
cout<<"\n\nWISH TO GO TO BINARY CONVERSIONS(1/0): ";
cin>>ch;
}while(ch!=0);

}
//octal
void octal()
{int i,ch=1,num;
do{
cout<<"\nOCTAL CONVERSIONS\n";
cout<<"1.OCTAL TO DECIMAL CONVERSION\n";
cout<<"2.DECIMAL TO OCTAL CONVERSION\n";
cout<<"\nENTER YOUR CHOICE: ";
cin>>i;
//1
if(i==1)
{cout<<"\nENTER OCTAL NUMBER: ";
cin>>num; 
int dec_value=0; 
// 8^0=1(base) 
int base=1; 
int temp=num; 
while(temp)
{
int last_digit=temp % 10; 
temp=temp/10; 
dec_value+=last_digit*base; 
base=base*8; 
}
cout<<"EQUIVALENT DECIMAL NUMBER: "; 
cout<<dec_value; 
}
//2
else if(i==2)
{cout<<"\nENTER DECIMAL NUMBER: ";
cin>>num; 
int binaryNum[32];  
int k=0; 
while(num>0) 
{ 
// storing remainder (1 or 0) 
binaryNum[k]=num%8; 
num=num/8; 
k++; 
}
cout<<"EQUIVALENT OCTAL NUMBER: "; 
for(int j=k-1;j>=0;j--) 
cout<<binaryNum[j];  
}
//wrong choice
else
{cout<<"\nWRONG CHOICE!!";
}
cout<<"\n\nWISH TO GO TO OCTAL CONVERSIONS(1/0): ";
cin>>ch;
}while(ch!=0);

}
//hexadecimal
void hexadec()
{int i,ch=1,num;
do{
cout<<"\nHEXADECIMAL CONVERSIONS\n";
cout<<"1.HEXADECIMAL TO DECIMAL CONVERSION\n";
cout<<"2.DECIMAL TO HEXADECIMAL CONVERSION\n";
cout<<"\nENTER YOUR CHOICE: ";
cin>>i;
//1
if(i==1)
{
char value[10];
cout<<"\nENTER HEXADECIMAL NUMBER: ";
cin>>value; 
int len=strlen(value); 
//16^0=1(base) 
int base = 1; 
int dec_val = 0; 
for(int k=len-1; k>=0; k--) 
{if(value[k]>='0' && value[k]<='9') 
{ 
dec_val+=(value[k]-48)*base; 
base=base*16; 
} 
else if(value[k]>='A' && value[k]<='F') 
{ 
dec_val+=(value[k]-55)*base; 
base=base*16; 
} 
}
cout<<"EQUIVALENT DECIMAL NUMBER: "; 
cout<<dec_val; 
}
//2
else if(i==2)
{cout<<"\nENTER DECIMAL NUMBER: ";
cin>>num; 
char hexaDeciNum[100]; 
int k=0; 
while(num!=0) 
{int temp=0; 
// storing remainder (0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F). 
temp=num%16; 
if(temp<10) 
{hexaDeciNum[k]=temp+48; 
 k++; 
}
else
{hexaDeciNum[k]=temp+55; 
k++; 
}num=num/16; 
} 
cout<<"EQUIVALENT HEXADECIMAL NUMBER: ";
for(int j=i-1; j>=0; j--) 
 cout<<hexaDeciNum[j]; 
}
//wrong choice
else
{cout<<"\nWRONG CHOICE!!";
}
cout<<"\n\nWISH TO GO TO HEXADECIMAL CONVERSIONS(1/0): ";
cin>>ch;
}while(ch!=0);

}

