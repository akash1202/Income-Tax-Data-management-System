#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
//#include "conio.h"
using namespace std;
class check
{
	int pn,age;
	char name[20],pass[9];
	float fix,total,tax;
	public:
	void checkf()
{
	int ch,cn=1,k=0;
	char pass1[9],ch1;
	pass1[0]='a';
	strcpy(pass,"check123");		//password for checking
do{
	cout<<"enter right 1.admin 2.user 3.return";
	cin>>ch;
	check a;
	switch(ch)
	{
		case 1:if(pass1[0]=='a'||strcmp(pass,pass1))
		       {cout<<"enter password:";
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
			   cout<<"sorry wrong password:";
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

	void admin()
  { 
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
	int flag=0,pn1,year=2011;
	double total,tax;
	char name[20];
	cout<<"enter pancard no:";
	cin>>pn1;
	ifstream fin;
	fin.open("it2.txt",ios::app);
	while(fin>>pn>>name>>total>>age>>tax)
	{
		if(pn1==pn)
		{
		cout<<"\nyear:"<<year<<endl;year++;
		cout<<"\npancard:"<<pn<<"\tname:"<<name<<"\tTotal income:"<<total<<"\tage:"<<age<<"\tTax:"<<tax<<endl;flag=1;
	   }
	}
	if(flag==0)
	cout<<"sorry not found your record";
	fin.close();
  }

};

class enterdata
{
	int pn,age;
	char name[20],pass[9];
	double nfix,fix,total,tax;
	public:

   void enterdataf()
{
	char pass1[9],ch1;
	pass1[0]='a';
	strcpy(pass,"enter123");            //password                                
	int ch,cn=1,k;
 do{ 
	cout<<"enter right 1.admin 2.user 3.return";
	cin>>ch;
	switch(ch)
	{
		case 1:if(pass1[0]=='a'||strcmp(pass,pass1))
		       {
		       	k=0;
			     cout<<"enter password:";
			    // ch1=getch();
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
	
void admin_enter()
  {
   	ifstream fin;
   	ofstream fout;
   	pn=0;
	fin.open("it1.txt",ios::app);
	while(fin>>pn>>name>>age)
	{
	}
	fin.close();
    pn=pn+1;
	cout<<"enter name";cin>>name;
	cout<<"enter age:";cin>>age;	
    cout<<" new customer pancard no is:"<<pn;
    fout.open("it1.txt",ios::app);
	fout<<pn<<"\t"<<name<<"\t"<<age<<endl;
	fout.close();	
  }
  void user_enter()
  {
	ofstream fout;
	ifstream fin;
	int pn1,ans,age1,type;
	char name1[20];
	nfix=0;
	total=0;
	cout<<"enter pancard number:";cin>>pn1;
	fin.open("it1.txt");                              // checking record
	while(fin>>pn>>name>>age)
	{
		if(pn1==pn)
		{
			age1=age;
			strcpy(name1,name);
		    cout<<"your record found with\t"<<name<<"\tname.\t";
		    break;
	    } 
	}
	fin.close();
	if(pn1!=pn)
	{  cout<<"sorry your record not found enter proper pancard no!!!\n";
	   return; 
    } 
	cout<<"\nenter income(fix _monthly):";cin>>fix;
	cout<<"\nany other non-fix income yearly ?(1/0):";cin>>ans;
	if(ans==1)
    {cout<<"\nenter total amount of year(taxble):";cin>>nfix;
    }
	if(age1<60&&age1>0)                                 //type give  1.individual(m/f) 2.senior 3.super senior
	{
	 type=1;
	 cout<<"thnx for entering your DATA for tax count in cat:(GENERAL)\n";
    }
	if(age1>=60&&age1<80)
	{
	  type=2;
	  cout<<"thnx for entering your DATA for tax count in cat:(SENIOR CITIZEN) \n";
    } 
	if(age1>=80)
	{
	  type=3;
	  cout<<"thnx for entering your DATA for tax count in cat:(SUPER SENIOR CITIZEN) \n";
    }
	total=(fix*12)+nfix;                                //total count
	if(total>250000)                                   //tax count using function
	{
	  tax=count(total,type); 
      cout<<"\ntotal:"<<total<<"\ttax:"<<tax<<endl;
	}
	else
	{cout<<"\nyou are free from tax pay!!!!";
	tax=0;}  
	fout.open("it2.txt",ios::app);                                       
	fout<<pn<<"\t"<<name<<"\t"<<total<<"\t"<<age<<"\t"<<tax<<endl;  
	fout.close();
   }
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

};

int main()
{
	int ch,i=0;
	check a[10];
	enterdata b[10];
do{
	cout<<"\nwhat you want:1.check 2.enterdata 3.exit";
	cin>>ch;
	switch(ch)
	{
		case 1:a[i].checkf();
		       break;
		case 2:b[i].enterdataf();
		      break;
	    case 3:exit(0);
	           break;
	    default:cout<<"enter proper choice!";
	            break;
	}
	cout<<"continue?(1/0)";cin>>ch;
	i++;
   }while(ch==1);
   return 0;
}
