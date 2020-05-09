#include<iostream>
#include<fstream>
#include<stdlib.h>

void addData(); 
void displayData(); 
void searchData(); 
void deleteData(); 
void modifyData(); 

using namespace std;

class Student
{
 int admno;
 char name[20];
 char gender;
 int std;
 char DOB[20];
 
 public:
  void getData();
  void showData();
  int getAdmno(){return admno;}
}s;


void Student::getData()
{
 cout<<"\n\nENTER STUDENT DETAILS......\n";
 cout<<"ENTER ADMISSION NO. : "; cin>>admno;
 cout<<"ENTER FULL NAME     : "; cin.ignore(); cin.getline(name,20);
 cout<<"ENTER DATE OF BIRTH : "; cin.ignore(); cin.getline(DOB,20);
 cout<<"ENTER GENDER(M/F)   : "; cin>>gender;
 cout<<"ENTER STANDARD      : "; cin>>std;
 cout<<endl;
}

void Student::showData()
{
 cout<<"\n\n.......STUDENT DETAILS......\n";
 cout<<"ADMISSION NO.     : "<<admno<<endl;
 cout<<"FULL NAME         : "<<name<<endl;
 cout<<"DATE OF BIRTH     : "<<DOB<<endl;
 cout<<"GENDER            : "<<gender<<endl;
 cout<<"STANDARD          : "<<std<<endl;
 cout<<endl;
}
int main()
{
 int ch,a=2,flag=0,i;
 int system_password=1603;
 int typed;
  
cout<<"ENTER THE SYSTEM PASSWORD: \n";
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
  cout<<"\n**********************WELCOME*************************\n";
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
  cout<<"\n-------------STUDENT MANAGEMENT SYSTEM----------------\n";
  cout<<"------------------------------------------------------\n";
  cout<<"------------------------------------------------------\n";
  cout<<"1. ENTER STUDENT DETAILS\n";
  cout<<"2. READ STUDENT DETAILS\n";
  cout<<"3. SEARCH STUDENT DETAILS\n";
  cout<<"4. DELETE STUDENT DETAILS\n";
  cout<<"5. MODIFY STUDENT DETAILS\n";
  cout<<"\nENTER YOUR CHOICE : ";
  cin>>i;
  switch(i)
  {
   case 1: addData(); break;
   case 2: displayData(); break;
   case 3: searchData(); break;
   case 4: deleteData(); break;
   case 5: modifyData(); break;
   default: cout<<"\nWRONG CHOICE!!!\n";break;
  }
cout<<"\nWISH TO GO TO MENU(1/0): ";
cin>>ch;
}while(ch!=0);
cout<<"\nTHANKS FOR USING MY PROGRAM-SJ\n";
return 0;
}
void addData()
{
 ofstream fout;
 fout.open("Students.txt",ios::out|ios::app);
 s.getData();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"\n\nDATA SAVED SUCCESSFULLY...\n";
}

void displayData()
{
 ifstream fin;
 fin.open("Students.txt",ios::in);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nDONE...\n";
}

void searchData()
{
 int n, flag=0;
 ifstream fin;
 fin.open("Students.txt",ios::in);
 cout<<"\nENTER THE ADMISSION NO. YOU WANT TO SEARCH : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"\nTHE DETAILS OF ADMISSION NO. "<<n<<":\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"\nTHE ADMISSION NO. "<<n<<" NOT FOUND!!!\n\n";
 else
cout<<"\n\nDONE...\n";
}

void deleteData()
{
 int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("Students.txt",ios::in);
 fout.open("TempStud.txt",ios::out|ios::app);

 cout<<"\nENTER ADMISSION NO. YOU WANT TO DELETE : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"\nThe ADMISSION NO. "<<n<<" HAS BEEN REMOVED:\n";
   s.showData();
   tout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
   cout<<"\nTHE ADMISSION NO. "<<n<<" NOT FOUND!!!\n\n";
 remove("Students.txt");
 rename("tempStud.txt","Students.txt");
}
void modifyData()
{
 int n, flag=0, pos;
 fstream fio;

 fio.open("Students.txt",ios::in|ios::out);
 
 cout<<"\nENTER THE ADMISSION NO. YOU WANT TO MODIFY : ";
 cin>>n;
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getAdmno())
  {
   cout<<"\nTHE ADMISSION NO. "<<n<<" FOLLOWING HAS DETAILS :\n";
   s.showData();
   cout<<"\n\nNOW, ENTER NEW DETAILS...\n";
   s.getData();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"\nTHE ADMISSION NO. "<<n<<" NOT FOUND!!!\n\n";
 else
  cout<<"\n\nDATA SAVED SUCCESSFULLY...\n";
}

