#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;

static double upoint=0,ucredit=0;

/******************************************************************************/
class student{
        char *name;
        char *roll;
        char grade[10][10];
        float SGPA;
        float CGPA;
    public:
        student();
        void get_stinfo(ifstream &in);
        void cal_sgpa(void);
        void cal_cgpa(void);
        friend ostream &operator<<(ostream &I,student std);
        void print(const int, student*S);
        };
/******************************************************************************/

student::student()
    {
    name=new char[20];
    roll=new char[10];
    strcpy(name,"\0");
    strcpy(roll,"\0");
    SGPA=0;
     for(int i=0;i<8;i++)
       {
       strcpy(grade[i],"\0");
       }
    CGPA=0;
    }
/******************************************************************************/
void student::get_stinfo(ifstream &I)
{

	char a[100],*p=NULL,b[100];
	int sub=1;
		
		sub=1;
		I.getline(a,100);
		strcpy(roll,a);
		
		I.getline(b,50);
		strcpy(name,b);
   		
   	
   		I.getline(a,50);
    	p=strtok(a," ");
    	if (p!=NULL)
   	  		strcpy(grade[0],p);
   		do {
 	      		p=strtok(NULL," ");
        		if (p!=NULL)
        	    	strcpy(grade[sub],p);
        		sub++;
    		}while (p!=NULL);
    	
}
/*****************************************************************************/
void student::cal_sgpa()
{
int sub=0,i=0,sub1=1;
int tc=0;
char a[200],*p;
double crpoint[10],totlcrdt=0,totlpoint=0;
ifstream credit("C:\\c++\\credit.txt");
     
     	credit.seekg(0,ios::beg);
        credit.getline(a,100);
        p=strtok(a," ");
        
        totlcrdt=crpoint[0]=atof(p);
        while (p!=NULL)
		{
			p=strtok(NULL," ");
			crpoint[sub1]=atof(p);
			sub1++;
			if(!p)
			break;	
		}
		
		for(i=1;i<sub1;i++)
		{	
			
			totlcrdt=totlcrdt+crpoint[i];
		}	
			
        totlpoint=0;
        
        for(i=0;i<sub1;i++)
        {
        	fflush(stdout);
   		   
        	if(!strcmp(grade[i],"A+"))totlpoint+= 4*crpoint[i];
            else if(!strcmp(grade[i],"A"))totlpoint+= 3.75*crpoint[i];
            else if(!strcmp(grade[i],"A-"))totlpoint+= 3.5*crpoint[i];
            else if(!strcmp(grade[i],"B+"))totlpoint+= 3.25*crpoint[i];
            else if(!strcmp(grade[i],"B"))totlpoint+= 3.00*crpoint[i];
            else if(!strcmp(grade[i],"B-"))totlpoint+= 2.75*crpoint[i];
            else if(!strcmp(grade[i],"C+"))totlpoint+= 2.5*crpoint[i];
            else if(!strcmp(grade[i],"C"))totlpoint+= 2.25*crpoint[i];
            else if(!strcmp(grade[i],"D"))totlpoint+= 2*crpoint[i];
         }
        
       upoint+=totlpoint;
       ucredit+=totlcrdt;
       SGPA=totlpoint/totlcrdt;
       credit.close();
}

/*****************************************************************************************************/
void student::cal_cgpa(void)
    {
    CGPA=upoint/ucredit;
    upoint=0;
    ucredit=0;
    }


void student::print(const int std,student *S)
{
	cout<<"PRESS ENTER TO SEE DETAILS\n";
	
    getch();
    //clrscr();
ofstream output("C:\\c++\\output.txt");
    output<<"\n\n\t==========================================================\n\n";
    output<<setw(19)<<"SERIAL\tROLL"<<setw(33)<<"NAME"<<setw(13)<<"GPA";
    output<<"\n\n\t==========================================================\n\n\n";
    cout<<"\n\n\t============================================\n\n";
    cout<<"\tSERIAL\tROLL\t\t       NAME\tGPA";
    cout<<"\n\n\t============================================\n\n\n";

     for(int i=0;i<std;i++)
    {//OUTPUT TO THE STDOUT
    cout<<"\t  "<<(i+1)<<")\t"<<S[i].name;
    cout<<setw(30-strlen(S[i].name))<<S[i].roll;
    cout<<setiosflags(ios::showpoint)<<setprecision(2);
    cout<<"\t"<<S[i].SGPA<<"\n\n";


    //OUTPUT TO YHE OUTPUT FILE
    output<<setw(10)<<(i+1)<<")\t"<<S[i].name;
    output<<setw(40-strlen(S[i].name))<<S[i].roll;
    output<<setiosflags(ios::showpoint)<<setprecision(2);
    output<<setw(10)<<S[i].SGPA<<"\n\n";

    }
}

/************************************************************************************/
ostream &operator<<(ostream &I,student std)
{
//printing for individual STUDENT
fstream out1("C:\\c++\\output1.txt",ios::app|ios::out);
    I.precision(2);
    out1<<"NAME : "<<std.name<<endl;
    out1<<"ROLL : "<<std.roll<<endl;
    out1<<"CGPA : "<<std.CGPA<<"\n\n";
    I<<"NAME : "<<std.name<<endl;
    I<<"ROLL : "<<std.roll<<endl;
    I<<"CGPA : "<<std.CGPA<<"\n\n";
    I<<"SGPA : "<<std.SGPA<<"\n\n";
return I;
}


class login

{

protected:

    char login_un[20];

    char login_pw[20];

    char username[20];

    char password[20];

    int c;
public:

    void of_user()

    {

        ofstream u_on;

        u_on.open("username.txt");

        u_on<<"\nUsername :";                         //write  a username

        u_on<<"yasir";

        u_on.close();
    }
 
    void of_pass()
    {
        ofstream p_on;
        p_on.open("password.txt");
        p_on<<"\nPassword :";
        p_on<<"abc123";

        p_on.close();
    }
 

    void if_user()
    {
        ifstream uin;
        uin.open("user.txt");
        uin.getline(username, 50);                              //read a username
        while (strcmp("bms",login_un)!=0)

            {
                cout<<"USERNAME: ";
                cin>>login_un;                                //cin.getline(login_un, 50);
                if (strcmp(login_un, "bms") ==0)
                    {
                        //cout<<"\n"<<"is correct username";
                        cout<<"\n PLEASE ENTER PASSWORD ";
                        break;
                    }
                else
                    {
                        cout<<"\n"<<"INVALID USERNAME ENTERED.\n";
                    }
        }
        uin.close();
    }
      

    void if_pass()
    
    
	{
		
		

        ifstream pin;
        pin.open("pass.txt");
        pin.getline(password,50);                                 // read a password
        while(strcmp("bms123",login_pw)!=0)
            {
                cout<<"\n";

                cout<<"\nPASSWORD:";
                cin>>login_pw;

                if(strcmp(login_pw, "bms123") ==0)

                    {

                        cout<<"\n"<<"LOGIN SUCCESSFUL\n";
                         

                        break;

                    }

                else

                    {
                        cout<<"\n"<<" INVALID PASSWORD. TRY AGAIN\n";
                    }
            }
        pin.close();
    }
 
    void display()
    {
        of_user();
        of_pass();
        if_user();
        if_pass();
    }
};


int main()
{
	
student S[60];


int i,j,std;
char buf[30];
ifstream I("C:\\c++\\student.txt");
login obj;
int op;

    //cout<<"STUDENT LOGIN\n";
    system("COLOR 9");
    cout<<"*******************************************  BMS COLLEGE OF ENGINEERING ***********************************************\n";
    cout<<"\n\n";
    cout<<"******************************************* 3RD SEMESTER GRADE SHEET ***************************************************\n";
    /*cout<<"press 1 to enter useranme and password\n";
    cin>>op;*/
    cout<<"\nENTER USERNAME AND PASSWORD TO LOGIN\n";
           cout<<"\n";
           obj.display();
           cout<<"\n";
           cout<<"\n STUDENT GPA CALCULATION\n";
           
	cout<<"ENTER NUMBER OF STUDENTS:\n";
	cin>>std;   
    
	for (i=0;i<std;i++)   
    {
	     	
       S[i].get_stinfo(I);
       S[i].cal_sgpa();
	}
	
	S[0].print(std,S);
    
   I.close();
   
   for(;;)
   {
   
	int ch;
   system("COLOR B");
   cout<<"ENTER 1 TO KNOW MORE ABOUT THE COURSES AND THE CREDITS\n";
   cout<<"ENTER 2 TO KNOW GPA IN TERMS OF PERCENTAGE\n";
   cout<<"PRESS ANY KEY TO EXIT\n";   
   cin>>ch;
   switch(ch)
   {
   		case 1: cout<<"THE COURSES IN 3RD SEMESTER SUBJECTS ARE AS FOLLOWS:-\n";
   				cout<<"1.DATA STRUCTURES(15CS3DCDST)-CREDITS-5\n\n";
   				cout<<"2.WEB PROGRAMMING(15CS3DCWEP)-CREDITS-6\n\n";
   				cout<<"3.PROGRAMMING WITH C++(15CI3GCPCP)-CREDITS-6\n\n";
   				cout<<"4.COMPUTER ORGANISATION AND ARCHITECTURE(15CS3DCCOA)-CREDITS-4\n\n";
   				cout<<"5.DISCRETE MATHEMATICS(15MA3GCDMS)-CREDITS-4\n";
   				cout<<"\n \n";
   				break;
   				
   		case 2: cout<<"LETTER GRADE \t \t \t PERCENT GRADE\t \t \t 4.0 SCALE\n";
   				cout<<"A+\t \t \t \t   97-100\t \t \t   4.0 \n";
   				cout<<"A \t \t \t \t   93-96 \t \t \t   4.0 \n";
   				cout<<"A-\t \t \t \t   90-92 \t \t \t   3.7 \n";
   				cout<<"B+\t \t \t \t   87-89 \t \t \t   3.3 \n";
   				cout<<"B \t \t \t \t   83-86 \t \t \t   3.0 \n";
   				cout<<"B-\t \t \t \t   80-82 \t \t \t   2.7 \n";
   				cout<<"C+\t \t \t \t   77-79 \t \t \t   2.3 \n";
   				cout<<"C \t \t \t \t   73-76 \t \t \t   2.0 \n";
   				cout<<"C-\t \t \t \t   70-72 \t \t \t   1.7 \n";
   				cout<<"D+\t \t \t \t   67-69 \t \t \t   1.3 \n";
   				cout<<"D \t \t \t \t   65-66 \t \t \t   1.0 \n";
   				cout<<"F \t \t \t \t   >65 	 \t \t \t   0.0 \n";
   				cout<<"\n \n";
			    break;
			    
		default : exit(0);
			
									
   	}
   }
   
   
   
   
   getch();
}

