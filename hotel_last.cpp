#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

//START OF CLASS



class hotel
{

int room_no;
char name[30];
char address[50];
char phone[10];


public:

void main_menu();		//to dispay the main menu
void add();			//to book a room
void display(); 		//to display the customer record
void rooms();			//to display alloted rooms
void edit();			//to edit the customer record
int check(int);			//to check room status
void modify(int);		//to modify the record
void delete_rec(int);		//to delete the record
     };
    //END OF CLASS



//FOR DISPLAYING MAIN MENU



void hotel::main_menu()
{

int choice;
while(choice!=5)
{

  system("cls");
cout<<"\n\t\t\t\t*********";
cout<<"\n\t\t\t\t  HOTEL MANAGEMENT ";
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*********";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Records";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;

switch(choice)
{

case 1:	add();
break;

case 2: display();
break;

case 3: rooms();
break;

case 4:	edit();
break;

case 5: break;

default:
{

cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();

}

}

}

}


//END OF MENU FUNCTION


//FUNCTION FOR BOOKING OF ROOM


void hotel::add()
{

  system("cls");
int r,flag;
ofstream fout("hotel_Record.dat",ios::app);

cout<<"\n Enter Customer Detalis";
cout<<"\n ----------------------";
cout<<"\n\n Room no: ";
cout<<"\n Total no. of Rooms - 50";
cout<<"\n Ordinary Rooms from 1 - 30";
cout<<"\n Luxuary Rooms from 31 - 45";
cout<<"\n Royal Rooms from 46 - 50";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;

flag=check(r);

if(flag)
cout<<"\n Sorry..!!!Room is already booked";

else
{

room_no=r;
cout<<" Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone No: ";
cin>>phone;

fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked...!!!";

}

cout<<"\n Press any key to continue.....!!";

getch();
fout.close();

}


//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PURTICULAR CUSTOMER`S RECORD





void hotel::display()
{

  system("cls");

ifstream fin("hotel_Record.dat",ios::in);
int r,flag;

cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

  system("cls");
cout<<"\n Customer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";

getch();
fin.close();
}


//END OF DISPLAY FUNCTION

//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void hotel::rooms()
{

  system("cls");

ifstream fin("hotel_Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;

}

cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();

}


//FUNCTION FOR EDITING RECORDS AND FOR BILL


void hotel::edit()
{

  system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

cout<<"\n Enter room no: " ;
cin>>r;

switch(choice)
{

case 1:	modify(r);
break;

case 2:	delete_rec(r);
break;


default: cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Press any key to continue....!!!";

getch();
}


int hotel::check(int r)
{

int flag=0;

ifstream fin("hotel_Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}


//FUNCTION TO MODIFY CUSTOMERS RECORD


void hotel::modify(int r)
{

long pos,flag=0;

fstream file("hotel_Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void hotel::delete_rec(int r)
{

int flag=0;
char ch;
ifstream fin("hotel_Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(yes/no): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;

}

else
fout.write((char*)this,sizeof(hotel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("hotel_Record.dat");
rename("temp.dat","hotel_Record.dat");

}

}


//END OF DELETE FUNCTION



//START OF MAIN PROGARM


int main()
{

hotel h;
system("cls");
h.main_menu() ;
return 0;
}
