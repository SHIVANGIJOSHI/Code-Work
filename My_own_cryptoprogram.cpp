#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void encrypt();
void decrypt();
void red_zone();
void review_key(); 
void change_key(); 
void change_sys_pass(); 
void ENCode(string);
char ENTABLE(char x);
char DETABLE(char x);

int key=19;
int system_password=1603;
int super_password=2511;


int main()
{
 int ch,a=2,flag=0,i;
 int typed;
  
cout<<"ENTER THE SYSTEM PASSWORD:\n";
cin>>typed; 

while(a>0)
{
 if(system_password!=typed)
 {cout<<"\nWRONG PASSWORD !!! "<<"\nYOU HAVE "<<a<<" ATTEMPTS LEFT...";
 cout<<"\nENTER THE SYSTEM PASSWORD\n";
 cin>>typed;
 a--;
 }
 else 
 {
  flag=1;
  cout<<"\n**************************WELCOME**************************\n";
  break;
 }
}
if(flag==0)
{cout<<"\nWRONG PASSWORD !!! "<<"\nYOU HAVE "<<a<<" ATTEMPTS LEFT";
 cout<<"\nEXITING THE SYSTEM...";
 exit(0);
}
do
 {
  cout<<"\n-------------MENU OF MY CRYPTOGRAPHY SYSTEM----------------\n";
  cout<<"-----------------------------------------------------------\n";
  cout<<"-----------------------------------------------------------\n";
  cout<<"1. ENCRYPT THE MESSAGE \n";
  cout<<"2. DECRYPT THE MESSAGE \n";
  cout<<"3. RED ZONE\n";
  cout<<"\nENTER YOUR CHOICE : ";
  cin>>i;
  switch(i)
  {
   case 1: encrypt(); break;
   case 2: decrypt(); break;
   case 3: red_zone(); break;
   default: cout<<"\nWRONG CHOICE!!!\n";break;
  }
cout<<"\nWISH TO GO TO MAIN MENU(1/0): ";
cin>>ch;
}while(ch!=0);
cout<<"\nTHANKS FOR USING MY CRYPTOPROGRAM-SJ\n";
return 0;
}
//redzone
void red_zone()
{ int i,ch;
do
 {
  cout<<"\n---------------------MENU OF RED ZONE----------------------\n";
  cout<<"-----------------------------------------------------------\n";
  cout<<"-----------------------------------------------------------\n";
  cout<<"1. REVIEW THE KEY \n";
  cout<<"2. CHANGE THE KEY \n";
  cout<<"3. CHANGE THE SYSTEM PASSWORD\n";

  cout<<"\nENTER YOUR CHOICE : ";
  cin>>i;
  switch(i)
  {
   case 1: review_key(); break;
   case 2: change_key(); break;
   case 3: change_sys_pass(); break;
   default: cout<<"\nWRONG CHOICE!!!\n";break;
  }
cout<<"\nWISH TO GO TO RED ZONE MENU(1/0): ";
cin>>ch;
}while(ch!=0);

}

//change key
void change_key()
{int super_pass;
cout<<"\nENTER THE SUPER PASSWORD : ";
cin>>super_pass;
if(super_pass!=super_password)
{cout<<"\nACCESS DENIED...";
 exit(0);
}
 
 cout<<"\nENTER THE NEW KEY: ";
 cin>>key;
  cout<<"\nCHANGES SAVED...\n ";
}
//review key
void review_key()
{
 int super_pass;
cout<<"\nENTER THE SUPER PASSWORD : ";
cin>>super_pass;
if(super_pass!=super_password)
{cout<<"\nACCESS DENIED...";
 exit(0);
}
 cout<<"\nTHE KEY: "<<key<<"\n";
}
//change system password
void change_sys_pass()
{
 int super_pass;
cout<<"\nENTER THE SUPER PASSWORD";
cin>>super_pass;
if(super_pass!=super_password)
{cout<<"\nACCESS DENIED...";
 exit(0);
}
cout<<"\nENTER THE NEW PASSWORD: ";
cin>>system_password;
cout<<"\nCHANGES SAVED... ";
}
//encryption
void encrypt()
{ string text="";
string result = "";
cout<<"\nENTER MESSAGE TO BE ENCRYPTED(WITHOUT SPACE AND IN UPPER CASE ONLY): ";  cin>>text;  
    
  
    for (int i=0;i<text.length();i++) 
    { 
            result+=char((((int(text[i])-65)+key)%26)+65); 
    }     
ENCode(result);
}
//decryption
void decrypt()
{int i;
string text="";
string result1 = ""; 
cout<<"\nENTER MESSAGE TO BE DECRYPTED(WITHOUT SPACE AND IN UPPER CASE ONLY): ";  cin>>text;     
char result[20];   
for ( i = 0;i<text.length(); i++) 
    result[i]=DETABLE(text[i]); 
 result[i]='\0'; 
    for (i=0;i<strlen(result);i++) 
    { 
       result1+=char((((int(result[i])-65)+(26-key))%26)+65); 
    } 
 result1[i]='\0'; 
 cout<<"\nDECRYPTED MESSAGE: "<<result1;   
}
//ENTABLE
char ENTABLE(char x) { 
  switch (x) { 
  case 'A': 
    return 'S'; 
  case 'B': 
    return 'H'; 
  case 'C': 
    return 'I'; 
  case 'D': 
    return 'V'; 
  case 'E': 
    return 'A'; 
  case 'F': 
    return 'N'; 
  case 'G': 
    return 'G'; 
  case 'H': 
    return 'B'; 
  case 'I': 
    return 'J'; 
  case 'J': 
    return 'O'; 
  case 'K': 
    return 'C'; 
  case 'L': 
    return 'D'; 
  case 'M': 
    return 'F'; 
  case 'N': 
    return 'K'; 
  case 'O': 
    return 'Q'; 
  case 'P': 
    return 'W'; 
  case 'Q': 
    return 'L'; 
  case 'R': 
    return 'X'; 
  case 'S': 
    return 'P'; 
  case 'T': 
    return 'R'; 
  case 'U': 
    return 'E'; 
  case 'V': 
    return 'M'; 
  case 'W': 
    return 'Y'; 
  case 'X': 
    return 'Z'; 
  case 'Y': 
    return 'U'; 
  case 'Z': 
    return 'T';
  } 
} 
//ENcode
void ENCode(string s)
{ cout<<"\nENCRYPTED MESSAGE: ";
for (int i = 0; s[i]; i++) 
    cout<<ENTABLE(s[i]); 
cout << endl; 
} 

//DETABLE
char DETABLE(char x) { 
  switch (x) { 
  case 'S': 
    return 'A'; 
  case 'H': 
    return 'B'; 
  case 'I': 
    return 'C'; 
  case 'V': 
    return 'D'; 
  case 'A': 
    return 'E'; 
  case 'N': 
    return 'F'; 
  case 'G': 
    return 'G'; 
  case 'B': 
    return 'H'; 
  case 'J': 
    return 'I'; 
  case 'O': 
    return 'J'; 
  case 'C': 
    return 'K'; 
  case 'D': 
    return 'L'; 
  case 'F': 
    return 'M'; 
  case 'K': 
    return 'N'; 
  case 'Q': 
    return 'O'; 
  case 'W': 
    return 'P'; 
  case 'L': 
    return 'Q'; 
  case 'X': 
    return 'R'; 
  case 'P': 
    return 'S'; 
  case 'R': 
    return 'T'; 
  case 'E': 
    return 'U'; 
  case 'M': 
    return 'V'; 
  case 'Y': 
    return 'W'; 
  case 'Z': 
    return 'X'; 
  case 'U': 
    return 'Y'; 
  case 'T': 
    return 'Z'; 

  } 
} 
