#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
float count(double total,int type)
{
	double a,b,c,tax;
	if(type==1)
	 {
	 	if(total>250000&&total<=500000)      //250001-500000
	    {a=total-250000;
	 	tax=(a*0.1);}
	    if(total>500000&&total<1000000)  //500001-1000000
	 	{a=25000;
	 	b=(total-500000);
	 	tax=(a+b*0.2);}
		if(total>1000000)               //1000001-*
	 	{a=25000;
	 	b=100000;
	 	c=total-1000000;
	 	tax=(a+b+c*0.3);}
	 }
	 if(type==2)
	 {
	 	if(total>300000&&total<=500000)   //300001-500000
	 	{a=total-300000;
	 	 tax=(a*0.1);}
	    if(total>500000&&total<1000000)   //500001-1000000
	 	{a=20000;
	 	b=total-500000;
	 	tax=(a+b*0.2);}
        if(total>1000000)                //1000001-*
	 	{a=20000;
	 	b=100000;
	 	c=(total-1000000);
	 	tax=(a+b+c*0.3);}
	 }
	 if(type==3)
	 {
	 	if(total>250000&&total<=500000)   //250001-500000
	 	{a=0;
	 	tax=(a*0.1);}
	    if(total>500000&&total<1000000)   //500001-1000000
	    {a=0;
	 	b=total-500000;
	 	tax=(a+b*0.2);}
	 	if(total>1000000)                //1000001-*
	    {a=0;
	 	b=100000;
	 	c=total-1000000;
	 	tax=(a+b+c*0.3);}
	 }
	 return tax;	 
}

void admin_enter()
{
   	ifstream fin;
   	ofstream fout;
	int pn=0,age;
	char name[20];
	float fix,total=0;
	fin.open("it1.txt",ios::app);
	while(fin)
	{
		fin>>pn>>name>>age;
	}
	fin.close();
    pn=pn+1;
	cout<<"\nenter name";cin>>name;
	cout<<"\nenter age:";cin>>age;	
    cout<<"\nnew customer pancard no is:"<<pn<<endl;
    fout.open("it1.txt",ios::app);
	fout<<pn<<"\t"<<name<<"\t"<<age<<endl;
	fout.close();	
}
void user_enter()
{
	ofstream fout;
	ifstream fin;
	int pn1,pn,ans,age,age1,type;
	char name1[20],name[20];
	float nfix=0,fix,tax;
	double total; 
	cout<<"\nenter pancard number:";cin>>pn1;
	fin.open("it1.txt");                              // checking record
	while(fin)
	{
		fin>>pn>>name>>age;
		if(pn1==pn)
		{
			age1=age;
			strcpy(name1,name);
		 cout<<"\nyour record found with\t"<<name<<"\tname.\t";
		 break;
	    } 
	}
	fin.close();
	if(pn1!=pn)
	{  cout<<"\nsorry your record not found enter proper pancard no!!!\n";
	   return; 
    } 
	cout<<"\nenter income(fix _monthly):";cin>>fix;
	cout<<"\nany other non-fix income yearly ?(1/0):";cin>>ans;
	if(ans!=0)
    {cout<<"\nenter total amount of year(taxable):";cin>>nfix;
    }
    cout<<"\nthnx for enter your income\n";
	if(age1<60&&age1>0)                                 //type give  1.individual(m/f) 2.senior 3.super senior
	type=1;
	if(age1>=60&&age1<80)
	type=2;
	if(age1>=80)
	type=3;
	total=(fix*12)+nfix;                              //total count
	if(total>250001)                                  
	{
	   tax=count(total,type);                          //tax count using function
	   cout<<"\ntotal:"<<total<<"\ttax:"<<tax;
    }
	else
	{cout<<"\nyou are free from tax pay!!!!";
	tax=0;}  
	fout.open("it2.txt",ios::app);                                           //*
	fout<<pn<<"\t"<<name<<"\t"<<total<<"\t"<<age<<"\t"<<tax<<endl;   //*
	fout.close();
}
void admin()
{
	int pn,age;
	double total,tax;
	char name[20];
	ifstream fin;
	fin.open("it2.txt");
	while(fin>>pn>>name>>total>>age>>tax)
	{
		cout<<"\npancard:"<<pn<<"\tname:"<<name<<"\tTotal income:"<<total<<"\tage:"<<age<<"\tTax:"<<tax<<endl;
	}
	fin.close();
	
}
void user()
{
	int pn,flag=0,age,pn1;
	double total,tax;
	char name[20];
	cout<<"\nenter pancard no:";
	cin>>pn1;
	ifstream fin;
	fin.open("it2.txt");
	while(fin>>pn>>name>>total>>age>>tax)
	{
		if(pn1==pn)
		cout<<"\npancard:"<<pn<<"\tname"<<name<<"\tTotal income:"<<total<<"\tage:"<<age<<"\tTax:"<<tax<<endl;flag=1;
	}
	if(flag==0)
	cout<<"\nsorry not found your record";
	fin.close();
	
}
void check()
{
	int ch,cn=1,k=0;
	char pass[9],pass1[9],ch1;
	pass[0]='a';
	strcpy(pass,"check123");
do{
	cout<<"\nenter right 1.admin 2.user 3.return";
	cin>>ch;
	switch(ch)
	{
		case 1:if(pass[0]=='a'||strcmp(pass,pass1))
		       {cout<<"\tenter password:";
		       ch1=getch();
		       cout<<"*";
			     do
			     {
			     	pass1[k]=ch1;
			     	k++;
					ch1=getch();
					cout<<"*";
				 }while(ch1!=13);
				  pass1[k]='\0';
		       }
		       if(!strcmp(pass1,pass))
		          admin();
		       else 
			   cout<<"\nsorry wrong password:";
		       break;
		case 2:user();
		      break;
		case 3:return;
	    default:cout<<"enter proper choice"; 
	            break;
	}
	cout<<"continue checking data?(1/0):";
	cin>>cn;
    }while(cn==1);
}
void enterdata()
{
	char pass[9],pass1[9],ch1;
	pass[0]='a';
	strcpy(pass,"enter123");                                 //password
	int ch,cn=1,k=0;
 do{ 
	cout<<"enter right 1.admin 2.user 3.return";
	cin>>ch;
	switch(ch)
	{
		case 1:if(pass[0]=='a'||strcmp(pass,pass1))
		       {
			     cout<<"enter password:";
			     ch1=getch();
			     cout<<"*";
			     do
			     {
			     	pass1[k]=ch1;
			     	k++;
					ch1=getch();
					cout<<"*";
				 }while(ch1!=13);
				  pass1[k]='\0';
		         //cin>>pass1;
		       }
		       if(!strcmp(pass1,pass))
		       admin_enter();
		       else cout<<"sorry wrong password:";
		       break;
		case 2:user_enter();
		      break;
		case 3:return;   
	    default:cout<<"enter proper choice"; 
	            break;
	}
	cout<<"continue entering data?(1/0):";
	cin>>cn;
   }while(cn==1);
}

int main()
{
	int ch;
do{
	cout<<"\nwhat you want:1.check 2.enterdata 3.exit";
	cin>>ch;
	switch(ch)
	{
		case 1:check();
		       break;
		case 2:enterdata();
		      break;
	    case 3:exit(0);
	           break;
	    default:cout<<"enter proper choice!";
	            break;
	}
	cout<<"continue?(1/0)";cin>>ch;
   }while(ch==1);
   return 0;
}
