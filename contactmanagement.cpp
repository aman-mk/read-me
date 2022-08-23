//time and some animation;
#include <iostream>
#include <string.h>
#include <fstream>
#include<stdlib.h>
//#include <conio.h>
#include <iomanip>
using namespace std;
 int total,Deleted=0,n,totalNumberOfContact=0;
class Contact{
    public:
    char fName[15],lName[15],phoneNumber[15],email[19];
    
    
    void create(Contact  addcontact ){
        Deleted=0;
      system("CLS");
      fstream file;
      file.open("phoneBook.dat" ,ios::binary|ios::app|ios::in|ios::out);
	if(!file.is_open()){
	cout<<" !!!!!file is not open!!!!!";
    }
char Continue;
   do{
    name:
        cout<<"first name:\t ";
          cin>>addcontact.fName; cin.ignore();
        cout<<"last name: \t";
          cin>>addcontact.lName; cin.ignore(); 
        cout<<"phone number:  \t";
          cin>>addcontact.phoneNumber; cin.ignore();
 	//the code goes here
        cout<<"email:  \t";
          cin>>addcontact.email; cin.ignore();
	//the code goes here
        cout<<"do you want to continue Y/N";
          cin>>Continue;
        file<<addcontact.fName<<" "<<addcontact.lName<<"\t"<<addcontact.phoneNumber<<"\t"<<addcontact.email<<"\n";
  }
      while(Continue==('y') || Continue==('Y'));
system("cls");
 }   
 
 
void display(Contact *contacts){
	system("cls");
//if(!(Deleted!=0||totalNumberOfContact==0){
	for(int i=0;i<totalNumberOfContact;i){ 
cout<<contacts[i].fName<<""<<contacts[i].lName<<"\t"<<contacts[i].phoneNumber<<"\t"<<contacts[i].email<<"\n";
}}
// }else
// 	cout<<"nothing to be seen";



void Search(Contact *contacts){
		system("cls");
if(Deleted!=0||totalNumberOfContact==0){
	cout<<"nothing to be seen";
}
else{
  SEARCH:
  char name[15],choice,numb[15];
  int Len ;
  cout<<"\n1.search by name: ";
  cout<<"\n2.search by phone number : ";
  cout<<"\n3.search by email: ";
cin>>choice;
switch(choice){
	case '1' :
  cout<<"\nenter the name you want to see";
  cin>>name;
  Len=strlen(name);
  for(int i=0;i<totalNumberOfContact;i++){
  if((strncasecmp(name,contacts[i].fName,Len)==0)|| strncasecmp(name,contacts[i].fName,Len)==0){
   cout<<contacts[i].fName<<" "<<contacts[i].lName<<"\t"<<contacts[i].phoneNumber<<"\t"<<contacts[i].email<<"\n";

  }
}
break;
    case '2' :
  cout<<"\nenter the phone number";
  cin>>numb;
   Len=strlen(numb);
  for(int i=0;i<totalNumberOfContact;i++){
  if(strncasecmp(numb,contacts[i].phoneNumber,Len)==0){
   cout<<contacts[i].fName<<" "<<contacts[i].lName<<"\t"<<contacts[i].phoneNumber<<"\t"<<contacts[i].email<<"\n";
  }
}
break;
case '3' :  
  cout<<"\nenter the email";
  cin>>email;
   Len=strlen(name);
  for(int i=0;i<totalNumberOfContact;i++){
  if(strncasecmp(name,contacts[i].email,Len)==0){
   cout<<contacts[i].fName<<" "<<contacts[i].lName<<"\t"<<contacts[i].phoneNumber<<"\t"<<contacts[i].email<<"\n";
  }
  }
break;
default:
  cout<<"\nunknown command please enter again";
  goto SEARCH;
}
}}


  Contact modify( Contact *contacts){
  
 char phone[10];
 int check=0;
  cout<<"\nenter the phone you want to modify : ";
  cin>>phone;
  cin.ignore();
  fstream file;
  file.open("phoneBook.dat" ,ios::in|ios::binary|ios::out);
  for(int i=0;i<totalNumberOfContact;i++){
if(strcmp(contacts[i].phoneNumber,phone)==0)
 { cout<<"\nenter new name and last name : ";
  cin>>contacts[i].fName>>contacts[i].lName;
  cout<<"\nenter the phone : ";
  cin>>contacts[i].phoneNumber;
  cout<<"\nenter the email: ";
 cin>>contacts[i].email;
check=1;
cout<<"\nfile modified \n";
 }
 }
 file.close();
  fstream files;
  files.open("phoneBook.dat" ,ios::trunc|ios::in|ios::out);
  for(int i=0;i<totalNumberOfContact;i++){
   files<<contacts[i].fName<<" "<<contacts[i].lName<<"\t"<<contacts[i].phoneNumber<<"\t"<<contacts[i].email<<"\n";
  
  }
  
 if(check==0){
  cout<<"\nnot found\n"<<phone;
}
  files.close();
  return *contacts;
  }
  Contact Delete( Contact *contacts){
 char phone[10];
 int check=0;
  cout<<"\nenter the phone you want to delete : ";
  cin>>phone;
  cin.ignore();
  fstream file;
  file.open("phoneBook.dat" ,ios::in|ios::binary|ios::out);
  for(int i=0;i<totalNumberOfContact;i++){
if(strcmp(contacts[i].phoneNumber,phone)==0){
 strncpy( contacts[i].fName," " ,sizeof(contacts[i].fName));
 strncpy( contacts[i].lName," " ,sizeof(contacts[i].lName));
 strncpy( contacts[i].phoneNumber," " ,sizeof(contacts[i].phoneNumber));
 strncpy( contacts[i].email," " ,sizeof(contacts[i].email));
 cout<<"\nrecord deleted \n";
check=1;
 }
  }
  file.close();

 if(check==0){
  cout<<"\nnot found\n"<<phone;
}


  fstream files;
  files.open("phoneBook.dat" ,ios::trunc|ios::in|ios::out);
  for(int i=0;i<totalNumberOfContact;i++){
   files<<contacts[i].fName<<" "<<contacts[i].lName<<"\t"<<contacts[i].phoneNumber<<"\t"<<contacts[i].email<<"\n";
  
  }
  
  files.close();
  return *contacts;
  }
  void DeleteAll( ){
    system("cls");
	fstream files;
	files.open("phoneBook.dat" ,ios::trunc|ios::in|ios::out);
	remove("phoneBook.dat");
	cout<<"\nall files deleted \n";
	Deleted++;
	totalNumberOfContact=0;
  	files.close();
 } };
     
     
Contact getFromMemory(Contact *data);

void menu();
int main(){
	system("cls");
	menu();
	return 0;
}
void menu(){
	Contact contact,contacts[100]; int choice; 
	start:
        getFromMemory(contacts);    
    cout<<"\n1.create new contact";
    cout<<"\n2.see all contacts";
    cout<<"\n3.search";
    cout<<"\n4.modify contact";
    cout<<"\n5.delete contact";
    cout<<"\n6.delete all contact";
    cout<<"\no.exit";
    cout<<"\n";
    cin>>choice;
    switch(choice){
        case 1:       	
        	contact.create(contact);
          	break;
        case 2:
        	contact.display(contacts);
         	 break;
        case 3:
        	contact.Search(contacts);
        	break;
        case 4:
       		contact.modify(contacts);
      		break;
       case 5 :
       		contact.Delete(contacts);
       		break;
       case 6:
       		 contact.DeleteAll();
      		 totalNumberOfContact=0;
	  	 Deleted=1;
      		 break;
        case 0:
           	 exit(0);
            	 break;
            }
goto start;
  }
Contact getFromMemory(Contact data[]){
      fstream file;
      file.open("phoneBook.dat" , ios::app|ios::binary|ios::in|ios::out);
	int i=0;
	while(!file.eof()){
	file>>data[i].fName>>data[i].lName>>data[i].phoneNumber>>data[i].email;
	++i;
}
	totalNumberOfContact=i;
	file.close();
	return *data;
	
	//dsaifj
  }
