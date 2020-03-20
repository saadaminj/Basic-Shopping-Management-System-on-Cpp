



#include<stdio.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
#include <cstddef>
#include <ctime>
#include<math.h>
#include<iomanip>
#include<fstream>
using namespace std;

void delay(int x)
        {   char n;
        	long starttime=4409,i=starttime;
        	for(;i<starttime*(x*1000);i++)
        	{}
        	starttime=0;i=0;x=0;
        }

double profit=0;
/*
void getprofit()
{
	FILE *p=NULL;
	p=fopen("shopprofit.dat","r");
	if(p==NULL)
	{
		profit=10000000;
		p=fopen("shopprofit.dat","w");
		fprintf(p,"%lf",profit);
		fclose(p);
	}
	else 
	{
		fscanf(p,"%lf",&profit);
	}
}
*/
class accounts
{
	private:
		char username[20];
		char password[30];
		int flag;
		void delay(int x)
        {   
        	long starttime=4409,i=starttime;
        	for(;i<starttime*(x*1000);i++)
        	{}
        	starttime=0;i=0;x=0;
        }
	public:
		accounts()
		{
			flag=0;
		}
		char* getusername()
		{
			return username;
		}
	    void setusername()
		{
			again:
			cout<<"\n";
			cout<<"\n\t";
			cout<<"\n\tENTER USERNAME =  ";
			gets(username);
			int lmn;
			for(lmn=0;username[lmn]!='\0';lmn++)
			{
				if(username[lmn]==32)
				{
					cout<<"\n";
					cout<<"\n\t ____________________________________";
					cout<<"\n\t|                                    |";
			    	cout<<"\n\t|   USERNAME MUST NOT CONTAIN SPACE  |";
					cout<<"\n\t|____________________________________|\n";
					delay(80);
					system("cls");
					return;
				}
			}
			if(lmn==0)
				{
					cout<<"\n";
					cout<<"\n\t _____________________________________________";
					cout<<"\n\t|                                             |";
			    	cout<<"\n\t|   USERNAME MUST CONTAIN ATLEAST ONE LETTER  |";
					cout<<"\n\t|_____________________________________________|\n";
					delay(80);
					system("cls");
					return;
				}
			int x=checkusername();
			if(x==-1)
			{
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|  THIS USERNAME HAS BEEN TAKEN .... |";
				cout<<"\n\t|____________________________________|\n";
				delay(80);
				system("cls");
				return;
			}
			else 
			{
				setpassword();
			}
			
		}
		void setflag(int x)
		{
			flag=x;
		}
		void addusername()
		{
			ofstream f("C:\\Users\\Public\\Pictures\\11106.txt",ios::app);
			if(!f)
			{
				f.open("11106.txt",ios::app);
			}
			if(!f)
			{
				cout<<"\nunable to open";
			}
			else 
			{
				f<<username<<endl;
			}
			f.close();
		}
		void changepassword()
		{
			ifstream p;
			ofstream p2;
			p.open("C:\\Users\\Public\\Pictures\\11106.txt");
			if(!p)
			{
				p.open("11106.txt");
			}
			if(!p)
			{
				printf("\nunable to open");
			}
			else
			{
				char username2[20],un[20],ps[30];
				char password2[30],password3[30],password4[30],password5[30];
				int r=0,i=0,x=0;
				if(flag==0)
				{
					cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|  PLEASE FIRST SIGNUP OR SIGNIN.... |";
				cout<<"\n\t|____________________________________|\n";
					
					
					delay(80);
					system("cls");
					p.close();
					return ;
				}
				while(!p.eof())
				{
					p>>username2;
					r=p.tellg();
					p>>password3;
		    
		    		if((strcmp(username,username2))==0)
		    		{
		    			printf("\n\tENTER CURRENT PASSWORD =   ");
		    			i=0;
						password2[i]=getch();
					    while(password2[i]!='\r')
				    	{
				     		if(password2[i]=='\b')
				     		{
				     			if(i==0 ) return;
				     			i--;
				     			printf(" \b\b");
				     			goto h;
							}
				     		printf("%c",password2[i]);
				    		delay(5);
    				printf("\b0");
    				delay(5);
		    		printf("\bo");
							i++;
							h:
				    		password2[i]=getch();
				    	}
				    	password2[i]='\0';
				    	
				    	if(strcmp(password2,password3)==0)
				    	{
				    		printf("\n\tENTER NEW PASSWORD =   ");
				    		i=0;
							password4[i]=getch();
						    while(password4[i]!='\r')
					    	{
					    		
				     		if(password4[i]=='\b')
				     		{
				     			if(i==0 ) return;
				     			i--;
				     			printf(" \b\b");
				     			goto h2;
							}
					     		printf("%c",password4[i]);
					    		delay(5);
    				printf("\b0");
    				delay(5);
		    		printf("\bo");
								i++;
								h2:
					    		password4[i]=getch();
					    	}
					    	password4[i]='\0';
					    	printf("\n\tENTER NEW PASSWORD AGAIN TO CONFIRM =  ");
					    	i=0;
							password5[i]=getch();
						    while(password5[i]!='\r')
					    	{
					    		
				     		if(password5[i]=='\b')
				     		{
				     			if(i==0 ) return;
				     			i--;
				     			printf(" \b\b");
				     			goto h3;
							}
					     		printf("%c",password5[i]);
					    		delay(5);
    				printf("\b0");
    				delay(5);
		    		printf("\bo");
					    		i++;
					    		h3:
					    		password5[i]=getch();
					    	}
					    	password5[i]='\0';
					    	if(strcmp(password4,password5)==0)
					    	{
					    		goto doit;
							}
							else 
							{
								cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|  PASSWORD DOESNOT MATCH ....       |";
				cout<<"\n\t|____________________________________|\n";
								delay(80);
								p.close();
								return ;
							}
						}
						else 
						{cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t| YOUR CURRENT PASSWORD IS INCORRECT |";
				cout<<"\n\t|____________________________________|\n";
						
							delay(80);
							p.close();
							return ;
						}
						while(0)
						{
							doit:
							
		     				p.clear();
		     				p.seekg(0);
		     				
		     				p2.open("C:\\Users\\Public\\Pictures\\11101.txt");
		    	 		    
		    	 		    if(!p2)
		    	 		    {
		    	 		    	p2.open("11101.txt");
							}
		    	 		    p>>un;
		    	 		    while(!p.eof())
		    	 		    {
		    	 		    	p2<<un<<endl;
		    	 		    	
		    	 		    	p>>ps;
		    	 		    	x=p2.tellp();
								 if(strcmp(username,un)==0)
			    	 		    {
		    	 		    		p2<<password4<<endl;
		    	 		    	}
			    	 		    else p2<<ps<<endl;
			    	 		    
								p>>un;
		    	 		    }
		    	 		    
		     				p.close();
		     				p2.close();
		     				
		     				int cc=remove("C:\\Users\\Public\\Pictures\\11106.txt");
							int bb=rename("C:\\Users\\Public\\Pictures\\11101.txt","C:\\Users\\Public\\Pictures\\11106.txt");
							if(bb!=0 && cc!=0)
							{
								cc=remove("11106.txt");
						    	bb=rename("11101.txt","11106.txt");
							
							}
							if(bb==0 && cc==0)
							{
								strcpy(password,password4);
								cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|  PASSWORD CHANGING SUCCESSFUL....  |";
				cout<<"\n\t|____________________________________|\n";
							//	delay(80);
								return ;
							}
							else
							{
								cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|  PASSWORD CHANGING FAILED....      |";
				cout<<"\n\t|____________________________________|\n";
								getch();
							//	delay(80);
								return ;
							}
		     				delay(100);
		     				return ;
						}
		    			delay(50);
		    			system("cls");
		    			p.close();
						return ;
		     		}
				}
			}
			p.close();
		}
		void setpassword()
		{
			ofstream f;
			char password2[30],password3[30];
         	int i=0;
         	char l;
         	
         	f.open("C:\\Users\\Public\\Pictures\\11106.txt",ios::app);
         	if(!f)
         	{
         		f.open("11106.txt",ios::app);
			}
			 if(!f)
         	{
         		cout<<"\nunable to open";
			}
        	else 
        	{  		
     	    	again:
		    	i=0;
	        	printf("\n\tENTER NEW PASSWORD =  ");
	    		password3[i]=getch();
	    		while(password3[i]!='\r')
		    	{
				     		if(password3[i]=='\b')
				     		{
				     			if(i==0 ) return;
				     			i--;
				     			printf(" \b\b");
				     			goto h;
							}
		    		printf("%c",password3[i]);
		    		delay(5);
    				printf("\b0");
    				delay(5);
		    		printf("\bo");
    				i++;
    				h:
	    			password3[i]=getch();
		    	}
	    		password3[i]='\0';
	    		if(i==0)
	    		{
	    			cout<<"\n";
				cout<<"\n\t ___________________________________________________";
				cout<<"\n\t|                                                   |";
				cout<<"\n\t|  YOUR PASSWORD MUST CONTAIN ATLEAST ONE LETTER    |";
				cout<<"\n\t|___________________________________________________|\n";
		    		delay(90);
		    		return;
				}
    			printf("\n\tENTER NEW PASSWORD AGAIN TO CONFIRM =  ");	
	    		i=0;	
    			password2[i]=getch();
	    		while(password2[i]!='\r')
	    		{
	    			
				     		if(password2[i]=='\b')
				     		{
				     			if(i==0 ) return;
				     			i--;
				     			printf(" \b\b");
				     			goto h6;
							}
		    		printf("%c",password2[i]);
		    		delay(5);
    				printf("\b0");
    				delay(5);
		    		printf("\bo");
		    		i++;
		    		h6:
		    		password2[i]=getch();
		    	}
    			password2[i]='\0';
		    	if(strcmp(password3,password2)==0)
	    		{
	    			f<<username<<endl;
	    			f<<password3<<endl;
		    		cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|  PASSWORD SAVED ....               |";
				cout<<"\n\t|____________________________________|\n";
		    		delay(90);
		    		flag=1;
		    		strcpy(password,password3);
		    		
		    	}
		    	else 
		    	{
		    		cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t| ERROR !!!                          |";
				cout<<"\n\t|  PASSWORD DOESNOT MATCH ....       |";
				cout<<"\n\t|____________________________________|\n";
		    		
		    		f.close();
		    		delay(90);
		    		return;
	    		}
		   	}
		   	f.close();
		}
		void signup()
		{
			if(flag==1)
			{
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    FIRST CLOSE CURRENT ACCOUNT.... |";
				cout<<"\n\t|____________________________________|\n";
				delay(90);
				return;
			}
			setusername();
		}
		void signin()
		{
			if(flag==1)
			{
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    FIRST CLOSE CURRENT ACCOUNT.... |";
				cout<<"\n\t|____________________________________|\n";
				delay(90);
				return;
			}
			again:
			cout<<"\n\n\tENTER USERNAME =  ";
			cin>>username;
			int x=checkusername();
			char pass[30];
			char password2[30];
			if(x!=-1)
			{
				
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    THE USERNAME DOESNOT EXIST....  |";
				cout<<"\n\t|____________________________________|\n";
				delay(90);
				return;
			}
			printf("\n\tENTER PASSWORD =  ");
			int i=0;
			password2[i]=getch();
		    while(password2[i]!='\r')
	    	{
				     		if(password2[i]=='\b')
				     		{
				     			if(i==0 ) return;
				     			i--;
				     			printf(" \b\b");
				     			goto h8;
							}
	     		printf("%c",password2[i]);
	    		delay(5);
    				printf("\b0");
    				delay(5);
		    		printf("\bo");
	    		i++;
	    		h8:
	    		password2[i]=getch();
	    	}
	      	password2[i]='\0';
	      	if((strcmp(password2,password))==0)
	      	{
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|    ACCOUNT OPENED                  |";
				cout<<"\n\t|____________________________________|\n";
	      		flag=1;
	      		delay(90);
	      		system("cls");
			}
			else 
			{
				
				
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    PASSWORD IS INCORRECT ....      |";
				cout<<"\n\t|____________________________________|\n";
				delay(90);
				system("cls");
			}
	    } 
		int checkusername()
		{
			ifstream f;
			char username2[20],password2[30];
			f.open("C:\\Users\\Public\\Pictures\\11106.txt");
			if(!f)
			{
				f.open("11106.txt");
			}
			if(!f){
				
			}
			else
			{
				while(!f.eof())
				{
					f>>username2;
					f>>password2;
		    		if((strcmp(username,username2))==0)
		    		{
		    			strcpy(password,password2);
		    			f.close();
		    			return -1;
		     		}
				}
			}
			f.close();
			return 0;
			
		}	
        void checkpassword()
        {
        	ifstream f;
        	char pass2[30],username2[20];
        	f.open("C:\\Users\\Public\\Pictures\\11106.txt");
        	if(!f)
        	{
        		f.open("11106.txt");
			}
			if(!f)
        	{
        		cout<<"\nunable to open";
			}
        	while(!f.eof())
        	{
        		f>>username2;
        		f>>pass2;
        		if((strcmp(username2,username))==0)
        		{
        			strcpy(password,pass2);
				}
			}
			f.close();
		}
		void showpassword()
		{
			if(flag==1)
			{
				
				cout<<"\n";
				cout<<"\n\t _______________________________________";
				cout<<"\n\t|                                       |";
				cout<<"\n\t|YOUR CURRENT PASSWORD =                |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<password;
				cout<<"\n\t|_______________________________________|\n";
				delay(90);
			}
			else 
			{
				
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    FIRST OPEN AN ACCOUNT....       |";
				cout<<"\n\t|____________________________________|\n";
				delay(90);
			}
		}
		void closeaccount()
		{
			if(flag==1)
			{
				flag=0;
				
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|    ACCOUNT CLOSED....              |";
				cout<<"\n\t|____________________________________|\n";
				
				delay(90);
				system("cls");
			}
			else 
			{
				
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    THE ACCOUNT IS NOT OPENED YET.. |";
				cout<<"\n\t|____________________________________|\n";
				delay(90);
				system("cls");
			}
		}
		void deleteaccount()
		{
			if(flag==0)
			{
				
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    FIRST SIGNUP OR SIGNIN ....     |";
				cout<<"\n\t|____________________________________|\n";
				delay(90);
				return;
			}
			char confirm,password2[30];
			
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ARE YOU SURE                    |";
				cout<<"\n\t|       YOU WANT TO DELETE ACCOUNT ? |";
				cout<<"\n\t|_________________________(Y/N)______|\n";
			if((confirm=getche())=='n')
			{
				return ;
			}
			else 
			{	
				printf("\n\tENTER CURRENT PASSWORD =  ");
		   		int i=0;
				password2[i]=getch();
					    while(password2[i]!='\r')
				    	{
				     		if(password2[i]=='\b')
				     		{
				     			if(i==0 ) return;
				     			i--;
				     			printf(" \b\b");
				     			goto h9;
							}
				     		printf("%c",password2[i]);
				    		delay(5);
    				printf("\b0");
    				delay(5);
		    		printf("\bo");
				    		i++;
				    		h9:
				    		password2[i]=getch();
				    	}
				    	password2[i]='\0';
				if(strcmp(password,password2)!=0)
				{
					
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    YOU ENTERED INCORRECT PASSWORD..|";
				cout<<"\n\t|____________________________________|\n";
					delay(90);
					return;
				}
				ofstream p2;
				ifstream p;
				char un[20];
				char ps[30];
				p.open("C:\\Users\\Public\\Pictures\\11106.txt");
				if(!p)
				{
					p.open("11106.txt");
				}
				p2.open("C:\\Users\\Public\\Pictures\\11101.txt");
				if(!p2)
				{
					p2.open("11101.txt");
				}
				p>>un;
				while(!p.eof())
				{
					p>>ps;
					if(strcmp(un,username)==0)
					{
						continue;
					}
					else 
					{
						p2<<un<<endl;
						p2<<ps<<endl;
					}
					p>>un;
				}
				p.close();
				p2.close();
				
				int cc=remove("C:\\Users\\Public\\Pictures\\11106.txt");
				int bb=rename("C:\\Users\\Public\\Pictures\\11101.txt","C:\\Users\\Public\\Pictures\\11106.txt");
				if(bb!=0 && cc!=0)
				{
					cc=remove("11106.txt");
			    	bb=rename("11101.txt","11106.txt");
				
				}
				if(bb==0 && cc==0) 
				{
					flag=0;
					
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|                                    |";
				cout<<"\n\t|    ACCOUNT DELETED SUCCESSFULLY    |";
				cout<<"\n\t|____________________________________|\n";
				    
				    char filestring[35];
			    	ifstream firstfile("11102.dat");
			    	
			    	if(!firstfile)
			    	{
			    		return;
					}
				    ofstream newfile("11103.dat");
			    	while(!firstfile.eof())
			    	{
			    		firstfile.getline(filestring,30);
					    if(strcmp(filestring,username)==0)
			    		{
				    		newfile<<"UserDeleted\n";
				    	}
				    	else
				    	newfile<<filestring<<endl;
				    }
				    firstfile.close();
				    newfile.close();
	
			    	remove("11102.dat");
			    	rename("11103.dat","11102.dat");
				    
					delay(90);
					return;
				}
				else 
				{
					
				cout<<"\n";
				cout<<"\n\t ____________________________________";
				cout<<"\n\t|    ERROR !!!                       |";
				cout<<"\n\t|    ACCOUNT DELETION FAILED....     |";
				cout<<"\n\t|____________________________________|\n";
					delay(90);
					return;
				}
			}
		}
		int interface()
		{
			char x;
			while(1)
			{
	    		system("cls");
	    		
	    		
	cout<<"\n ____________________________________________________________________";
	cout<<"\n|                                                                    |";
	cout<<"\n|        PRESS                                                       |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|             1 - TO SIGNUP                                          |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|             2 - TO SIGNIN                                          |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|             3 - TO GO BACK                                         |";
	cout<<"\n|____________________________________________________________________|\n";
	    		
	    		x=getche();
	    		if(x=='\b') return flag;
				if(x=='1')
				{
					signup();
					return flag;
				}
				else if(x=='2')
				{
					signin();
					return flag;
				}
				else if(x=='3')
				{
					return flag;
				}
			}
		}
		int getflag()
		{
			return flag;
		}
		int settings()
		{
			char x;
			while(1)
			{
	    		system("cls");
				
				
	cout<<"\n ____________________________________________________________________";
	cout<<"\n|                                                                    |";
	cout<<"\n|        PRESS                                                       |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|             1 - TO CHANGE PASSWORD                                 |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|             2 - TO SHOW PASSWORD                                   |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|             3 - TO CLOSE ACCOUNT                                   |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|             4 - TO DELETE ACCOUNT                                  |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|             5 - TO GO BACK                                         |";
	cout<<"\n|____________________________________________________________________|\n";
	
	    		
				
				
				x=getche();
				if(x=='\b') return flag;
				if(x=='1')
				{
					changepassword();
				}
				else if(x=='2')
				{
					showpassword();
				}
				else if(x=='3')
				{
					closeaccount();
				}
				else if(x=='4')
				{
					deleteaccount();
				}
				else if(x=='5')
				{
					return flag;
				}
			}
		}
};

char* Getmobilesname(int);
char* Getelectronicsname(int);
char* Gethardwarename(int);
char* Getsportsname(int);

class stock
{
	private:
			int stockmobiles[10],stockelectronics[10],stockhardware[10],stocksports[10];
	public:
		int checksport(int id,int q)
		{
			if(q>stocksports[id])
			{
				return 1;
			}
			else return 0;
		}
		int checkhardware(int id,int q)
		{
			if(q>stockhardware[id])
			{
				return 1;
			}
			else return 0;
		}
		int checkelectronic(int id,int q)
		{
			if(q>stockelectronics[id])
			{
				return 1;
			}
			else return 0;
		}
		int checkmobile(int id,int q)
		{
			if(q>stockmobiles[id])
			{
				return 1;
			}
			else return 0;
		}
		int getstockmobiles(int id)
		{
			return stockmobiles[id];
		}
		int getstockelectronics(int id)
		{
			return stockelectronics[id];
		}
		int getstockhardware(int id)
		{
			return stockhardware[id];
		}
		int getstocksports(int id)
		{
			return stocksports[id];
		}
		void displaystock()
		{
			
			cout<<"\n";
			cout<<"\n _____________________________________";
			cout<<"\n|                                     |";
			cout<<"\n|     PLEASE OPEN IN FULLSCREEN       |";
			cout<<"\n|_____________________________________|\n";
			
			
				
	        cout<<"\n\n";
	    	cout<<"\n\t _______________________________________________________"; cout<<"\t\t _______________________________________________________";
	        cout<<"\n\t|                                                       |";cout<<"\t\t|                                                       |";
			cout<<"\n\t|                   STOCK OF MOBILES                    |";cout<<"\t\t|                 STOCK OF ELECTRONICS                  |";
          	cout<<"\n\t|_______________________________________________________|";cout<<"\t\t|_______________________________________________________|";
	        cout<<"\n\t|                                                       |";cout<<"\t\t|                                                       |";
			for(int item=0;item<10;item++)
			{
				cout<<endl<<"\t|"<<setw(30)<<Getmobilesname(item)<<setw(20)<<"|"<<right<<setw(5)<<stockmobiles[item]<<"|";
				cout<<"\t\t|"<<setw(30)<<Getelectronicsname(item)<<setw(20)<<"|"<<right<<setw(5)<<stockelectronics[item]<<"|";
			}
	    	cout<<"\n\t|_______________________________________________________|";cout<<"\t\t|_______________________________________________________|";
			
			
	    	
	        cout<<"\n\n";
	    	cout<<"\n\t _______________________________________________________"; cout<<"\t\t _______________________________________________________";
	        cout<<"\n\t|                                                       |";cout<<"\t\t|                                                       |";
			cout<<"\n\t|                   STOCK OF HARDWARE                   |";cout<<"\t\t|                   STOCK OF SPORTS                     |";
          	cout<<"\n\t|_______________________________________________________|";cout<<"\t\t|_______________________________________________________|";
	        cout<<"\n\t|                                                       |";cout<<"\t\t|                                                       |";
			for(int item=0;item<10;item++)
			{
				cout<<endl<<"\t|"<<setw(30)<<Gethardwarename(item)<<setw(20)<<"|"<<right<<setw(5)<<stockhardware[item]<<"|";
				cout<<"\t\t|"<<setw(30)<<Getsportsname(item)<<setw(20)<<"|"<<right<<setw(5)<<stocksports[item]<<"|";
			}
	    	cout<<"\n\t|_______________________________________________________|";cout<<"\t\t|_______________________________________________________|";
	    	
	    

			
			
			
		}
		void GetStock()
		{
			FILE *p=NULL;
			int i=0;
			p=fopen("11104.dat","r");
			if(p==NULL)
			{
				p=fopen("11104.dat","w");
				for(i=0;i<40;i++)
				{
					fprintf(p,"\n%d",1000);
				}
				fclose(p);
			}
			/*
			if(p==NULL)
			{
				p=fopen("shopstock.dat","w");
				while(i<10)
				{
					while(i<10)
					{
						fscanf(p,"\n%d",&stockmobiles[i]);
						i++;
					}
					i=0;
					while(i<10)
					{
						fscanf(p,"\n%d",&stockhardware[i]);
						i++;
					}
					i=0;
					while(i<10)
					{
						fscanf(p,"\n%d",&stockelectronics[i]);
						i++;
					}
					i=0;
					while(i<10)
					{
						fscanf(p,"\n%d",&stocksports[i]);
						i++;
					}
					fclose(p);
				}
			}
			*/
			p=fopen("11104.dat","r");
			i=0;
			while(i<10)
			{
				fscanf(p,"\n%d",&stockmobiles[i]);
				i++;
			}
			i=0;
			while(i<10)
			{
				fscanf(p,"\n%d",&stockhardware[i]);
				i++;
			}
			i=0;
			while(i<10)
			{
				fscanf(p,"\n%d",&stockelectronics[i]);
				i++;
			}
			i=0;
			while(i<10)
			{
				fscanf(p,"\n%d",&stocksports[i]);
				i++;
			}
			fclose(p);
		}
		void updatestock()
		{
			FILE *p;
			int i=0;
			p=fopen("11104.dat","w");
			while(i<10)
			{
				fprintf(p,"\n%d",stockmobiles[i]);
				i++;
			}
			i=0;
			while(i<10)
			{
				fprintf(p,"\n%d",stockhardware[i]);
				i++;
			}
			i=0;
			while(i<10)
			{
				fprintf(p,"\n%d",stockelectronics[i]);
				i++;
			}
			i=0;
			while(i<10)
			{
				fprintf(p,"\n%d",stocksports[i]);
				i++;
			}
			fclose(p);
			fclose(p);
			p=NULL;
		}
		void updateelectronicstock(int id,int n)
		{
			if(n==1000)
			stockelectronics[id]=1000;
			else 
			stockelectronics[id]=stockelectronics[id]+n;
		}
		void updatemobilestock(int id,int n)
		{
			if(n==1000)
			stockmobiles[id]=1000;
			else 
			stockmobiles[id]=stockmobiles[id]+n;
		}
		void updatehardwarestock(int id,int n)
		{
			if(n==1000)
			stockhardware[id]=1000;
			else 
			stockhardware[id]=stockhardware[id]+n;
		}
		void updatesportstock(int id,int n)
		{
			if(n==1000)
			stocksports[id]=1000;
			else
			stocksports[id]=stocksports[id]+n;
		}
};

stock stk;
class shop
{
	private:
		char   itemelectronics[10][30],itemmobiles[10][30],itemsports[10][30],itemhardware[10][30];
		int    itemelectronicsid[10],itemmobilesid[10],itemsportsid[10],itemhardwareid[10];
		double itemelectronicsprice[10],itemmobilesprice[10],itemsportsprice[10],itemhardwareprice[10];
		
	public:/*
		friend Getelectronicsname(int);
		friend Getmobilesname(int);
		friend Getsportsname(int);
		friend Getharwdarename(int);*/
		void updatestock()
		{
			stk.updatestock();
		}
		void incrementelectronicstock(int id,int n)
		{
			stk.updateelectronicstock(id,n);
			stk.updatestock();
		}
		void incrementhardwarestock(int id,int n)
		{
			stk.updatehardwarestock(id,n);
			stk.updatestock();
		}
		void incrementmobilestock(int id,int n)
		{
			stk.updatemobilestock(id,n);
			stk.updatestock();
		}
		void incrementsportstock(int id,int n)
		{
			stk.updatesportstock(id,n);
			stk.updatestock();
		}
		shop():
		    itemhardware{"Intel Core i5 7th Generation","AMD R7","AMD R8","Intel Core i7 8th Generation","Nvidia GTX 1080","Nvidia GTX 1080Ti","Nvidia GTX 1050","AMD Radeon RX 580","AMD Radeon RX 570","AMD Radeon 520M"},
			
			itemelectronics{"Dell Inspiron 3452","Hp Elitebook 8740w","Hp 15-BS1xx","Hp Elitebook 821-G1","Lenovo Ideapad 320","Macbook Pro MD101","Microsoft Surface Pro 4","Ideapad 310","Macbook Air MQD32","Lenovo Thinkpad X220"},
			
			itemmobiles{"Samsung S8","Samsung S8+","Iphone X","Iphone 8","Samsung S9","Oppo F5","Huawei Mate 10 Pro","HTC U Ultra","Sony Xperia XZ1","Xaomi Mi MIX 2"},
     		
			itemsports{"Cricket Bat","Hard Ball","Hockey Stick","Golf Stick","basket Ball","Football","Boxing Gloves","Badminton Racquet","Shuttlecock","Rugby Ball"},
			
			itemelectronicsid{0,1,2,3,4,5,6,7,8,9},
			itemelectronicsprice{40000,38000,62000,58000,55000,120000,90000,68000,380000,24000},
		    
			itemmobilesid{0,1,2,3,4,5,6,7,8,9},
			itemmobilesprice{82000,88000,132000,91000,112000,35000,61000,79000,61000,61500},
		    
			itemhardwareid{0,1,2,3,4,5,6,7,8,9},
		    itemhardwareprice{30000,28000,32000,48000,67000,76000,50000,55000,51000,19000},
		    
			itemsportsid{0,1,2,3,4,5,6,7,8,9},
		    itemsportsprice{8000,800,5000,20000,2000,6000,3500,2500,250,4000}
		
		{}
		void profitshop(double x)
		{
			profit=profit+x;
		}
		void displayelectronics()
		{
			string str;
			
			
		    cout<<"\n\n";
	    	cout<<"\n\t _________________________________________________________________";
	        cout<<"\n\t|                                                                 |";
			cout<<"\n\t|                           LAPTOPS                               |";
          	cout<<"\n\t|_________________________________________________________________|";
	        cout<<"\n\t|    |                                   |        |               |";
	        cout<<"\n\t| ID |          NAME                     |  PRICE |  STOCKCHECK   |";
          	cout<<"\n\t|____|___________________________________|________|_______________|";
	        cout<<"\n\t|    |                                   |        |               |";
	        for(int i=0;i<10;i++)
			{
				if(stk.getstockelectronics(i) > 0)
				{
					str=" IN STOCK";
				}
				else
				{
					str=" OUT OF STOCK";
				}
				cout<<"\n\t|"<<left<<setw(4)<<itemelectronicsid[i]<<"|"<<left<<setw(35)<<itemelectronics[i]<<fixed<<setprecision(1)
				<<"|"<<left<<setw(8)<<itemelectronicsprice[i]<<"|"<<right<<setw(15)<<str<<"|";
			}
	    	cout<<"\n\t|____|___________________________________|________|_______________|\n";
	    
			
		}
		void displayhardware()
		{
			
			string str;
			
			
		    cout<<"\n\n";
	    	cout<<"\n\t _________________________________________________________________";
	        cout<<"\n\t|                                                                 |";
			cout<<"\n\t|                          HARDWARE                               |";
          	cout<<"\n\t|_________________________________________________________________|";
	        cout<<"\n\t|    |                                   |        |               |";
	        cout<<"\n\t| ID |          NAME                     |  PRICE |  STOCKCHECK   |";
          	cout<<"\n\t|____|___________________________________|________|_______________|";
	        cout<<"\n\t|    |                                   |        |               |";
	        for(int i=0;i<10;i++)
			{
				if(stk.getstockhardware(i) > 0)
				{
					str=" IN STOCK";
				}
				else
				{
					str=" OUT OF STOCK";
				}
				cout<<"\n\t|"<<left<<setw(4)<<itemhardwareid[i]<<"|"<<left<<setw(35)<<itemhardware[i]<<fixed<<setprecision(1)
				<<"|"<<left<<setw(8)<<itemhardwareprice[i]<<"|"<<right<<setw(15)<<str<<"|";
			}
	    	cout<<"\n\t|____|___________________________________|________|_______________|\n";
	    
			
			
			
		}
		void displaymobiles()
		{
			
			
			string str;
			
			
		    cout<<"\n\n";
	    	cout<<"\n\t _________________________________________________________________";
	        cout<<"\n\t|                                                                 |";
			cout<<"\n\t|                          MOBILES                                |";
          	cout<<"\n\t|_________________________________________________________________|";
	        cout<<"\n\t|    |                                   |        |               |";
	        cout<<"\n\t| ID |          NAME                     |  PRICE |  STOCKCHECK   |";
          	cout<<"\n\t|____|___________________________________|________|_______________|";
	        cout<<"\n\t|    |                                   |        |               |";
	        for(int i=0;i<10;i++)
			{
				if(stk.getstockmobiles(i) > 0)
				{
					str=" IN STOCK";
				}
				else
				{
					str=" OUT OF STOCK";
				}
				cout<<"\n\t|"<<left<<setw(4)<<itemmobilesid[i]<<"|"<<left<<setw(35)<<itemmobiles[i]<<fixed<<setprecision(1)
				<<"|"<<left<<setw(8)<<itemmobilesprice[i]<<"|"<<right<<setw(15)<<str<<"|";
			}
	    	cout<<"\n\t|____|___________________________________|________|_______________|\n";
	    
			
			
		}
		void displaysports()
		{
			
			string str;
			
			
		    cout<<"\n\n";
	    	cout<<"\n\t _________________________________________________________________";
	        cout<<"\n\t|                                                                 |";
			cout<<"\n\t|                          SPORTS                                 |";
          	cout<<"\n\t|_________________________________________________________________|";
	        cout<<"\n\t|    |                                   |        |               |";
	        cout<<"\n\t| ID |          NAME                     |  PRICE |  STOCKCHECK   |";
          	cout<<"\n\t|____|___________________________________|________|_______________|";
	        cout<<"\n\t|    |                                   |        |               |";
	        for(int i=0;i<10;i++)
			{
				if(stk.getstocksports(i) > 0)
				{
					str=" IN STOCK";
				}
				else
				{
					str=" OUT OF STOCK";
				}
				cout<<"\n\t|"<<left<<setw(4)<<itemsportsid[i]<<"|"<<left<<setw(35)<<itemsports[i]<<fixed<<setprecision(1)
				<<"|"<<left<<setw(8)<<itemsportsprice[i]<<"|"<<right<<setw(15)<<str<<"|";
			}
	    	cout<<"\n\t|____|___________________________________|________|_______________|\n";
	    
			
			
			
		}
		char *getmobilesname(int id)
		{
			switch(id)
			{
				case 0:
					return itemmobiles[0];
				case 1:
					return itemmobiles[1];
				case 2:
					return itemmobiles[2];
				case 3:
					return itemmobiles[3];
				case 4:
					return itemmobiles[4];
				case 5:
					return itemmobiles[5];
				case 6:
					return itemmobiles[6];
				case 7:
					return itemmobiles[7];
				case 8:
					return itemmobiles[8];
				case 9:
					return itemmobiles[9];
			}
		}
		char *getsportsname(int id)
		{
			switch(id)
			{
				case 0:
					return itemsports[0];
				case 1:
					return itemsports[1];
				case 2:
					return itemsports[2];
				case 3:
					return itemsports[3];
				case 4:
					return itemsports[4];
				case 5:
					return itemsports[5];
				case 6:
					return itemsports[6];
				case 7:
					return itemsports[7];
				case 8:
					return itemsports[8];
				case 9:
					return itemsports[9];
			}
		}
		char *gethardwarename(int id)
		{
			switch(id)
			{
				case 0:
					return itemhardware[0];
				case 1:
					return itemhardware[1];
				case 2:
					return itemhardware[2];
				case 3:
					return itemhardware[3];
				case 4:
					return itemhardware[4];
				case 5:
					return itemhardware[5];
				case 6:
					return itemhardware[6];
				case 7:
					return itemhardware[7];
				case 8:
					return itemhardware[8];
				case 9:
					return itemhardware[9];
			}
		}
		char *getelectronicsname(int id)
		{
			switch(id)
			{
				case 0:
					return itemelectronics[0];
				case 1:
					return itemelectronics[1];
				case 2:
					return itemelectronics[2];
				case 3:
					return itemelectronics[3];
				case 4:
					return itemelectronics[4];
				case 5:
					return itemelectronics[5];
				case 6:
					return itemelectronics[6];
				case 7:
					return itemelectronics[7];
				case 8:
					return itemelectronics[8];
				case 9:
					return itemelectronics[9];
			}
		}
		double getmobilesprice(int id)
		{
			
			switch(id)
			{
				case 0:
					return itemmobilesprice[0];
				case 1:
					return itemmobilesprice[1];
				case 2:
					return itemmobilesprice[2];
				case 3:
					return itemmobilesprice[3];
				case 4:
					return itemmobilesprice[4];
				case 5:
					return itemmobilesprice[5];
				case 6:
					return itemmobilesprice[6];
				case 7:
					return itemmobilesprice[7];
				case 8:
					return itemmobilesprice[8];
				case 9:
					return itemmobilesprice[9];
			}
		}
		double getelectronicsprice(int id)
		{
			
			switch(id)
			{
				case 0:
					return itemelectronicsprice[0];
				case 1:
					return itemelectronicsprice[1];
				case 2:
					return itemelectronicsprice[2];
				case 3:
					return itemelectronicsprice[3];
				case 4:
					return itemelectronicsprice[4];
				case 5:
					return itemelectronicsprice[5];
				case 6:
					return itemelectronicsprice[6];
				case 7:
					return itemelectronicsprice[7];
				case 8:
					return itemelectronicsprice[8];
				case 9:
					return itemelectronicsprice[9];
			}
		}
		double getsportsprice(int id)
		{
			
			switch(id)
			{
				case 0:
					return itemsportsprice[0];
				case 1:
					return itemsportsprice[1];
				case 2:
					return itemsportsprice[2];
				case 3:
					return itemsportsprice[3];
				case 4:
					return itemsportsprice[4];
				case 5:
					return itemsportsprice[5];
				case 6:
					return itemsportsprice[6];
				case 7:
					return itemsportsprice[7];
				case 8:
					return itemsportsprice[8];
				case 9:
					return itemsportsprice[9];
			}
		}
		double gethardwareprice(int id)
		{
			
			switch(id)
			{
				case 0:
					return itemhardwareprice[0];
				case 1:
					return itemhardwareprice[1];
				case 2:
					return itemhardwareprice[2];
				case 3:
					return itemhardwareprice[3];
				case 4:
					return itemhardwareprice[4];
				case 5:
					return itemhardwareprice[5];
				case 6:
					return itemhardwareprice[6];
				case 7:
					return itemhardwareprice[7];
				case 8:
					return itemhardwareprice[8];
				case 9:
					return itemhardwareprice[9];
			}
		}
		void interface()
		{
			char ch;
			cout<<"\n\n";
				cout<<"\n\t ________________________________________________";
				cout<<"\n\t|                                                |";
				cout<<"\n\t|                   HOME                         |";
				cout<<"\n\t|________________________________________________|";
				
			while(1)
			{
				system("cls");
				cout<<"\n\n";
				cout<<"\n\t ________________________________________________";
				cout<<"\n\t|  PRESS  :                                      |";
				cout<<"\n\t|________________________________________________|";
				cout<<"\n\t|                                                |";
				cout<<"\n\t|       1-TO GO INTO LAPTOP CATEGORY             |";
				cout<<"\n\t|________________________________________________|";
				cout<<"\n\t|                                                |";
				cout<<"\n\t|       2-TO GO INTO MOBILES CATEGORY            |";
				cout<<"\n\t|________________________________________________|";
				cout<<"\n\t|                                                |";
				cout<<"\n\t|       3-TO GO INTO HARDWARE CATEGORY           |";
				cout<<"\n\t|________________________________________________|";
				cout<<"\n\t|                                                |";
				cout<<"\n\t|       4-TO GO INTO SPORTS CATEGORY             |";
				cout<<"\n\t|________________________________________________|";
				ch=getche();
				if(ch=='1')
				{
					displayelectronics();
				}
				if(ch=='2')
				{
					displaymobiles();
				}
				if(ch=='3')
				{
					displayhardware();
				}
				if(ch=='4')
				{
					displaysports();
				}
			}
		}
};



shop s;

char* Getmobilesname(int id)
{
	return s.getmobilesname(id);
}
char* Getelectronicsname(int id)
{
	return s.getelectronicsname(id);
}
char* Gethardwarename(int id)
{
	return s.gethardwarename(id);
}
char* Getsportsname(int id)
{
	return s.getsportsname(id);
}



class vendors
{
	protected:
		int p[10];
		double vendor_profit;
		string s1;
	public:
		vendors()
		{
			vendor_profit=0;
			for(int i=0;i<10;i++)
			{
				p[i]=0;
			}
		}
	void getstock(const int q[10],string ss)
	{
		ofstream f;
		if(ss=="sports")
		{
			f.open("11111.txt");
			s1=ss;
			for(int stoc=0;stoc<10;stoc++)
			{
			    p[stoc]=q[stoc];
			    f<<p[stoc]<<endl;
			}
			f.close();
		}
		else if(ss=="hardware")
		{
			f.open("11110.txt");
			s1=ss;
			for(int stoc=0;stoc<10;stoc++)
			{
				p[stoc]=q[stoc];
				f<<p[stoc]<<endl;
			}
			f.close();
		}
		else if(ss=="electronics")
		{
			f.open("11109.txt");
			s1=ss;
			for(int stoc=0;stoc<10;stoc++)
			{
				p[stoc]=q[stoc];
				f<<p[stoc]<<endl;
			}
			f.close();
		}
		else if(ss=="mobiles")
		{
			f.open("11112.txt");
			s1=ss;
			for(int stoc=0;stoc<10;stoc++)
			{
				p[stoc]=q[stoc];
				f<<p[stoc]<<endl;
			}
			f.close();
		}
	}
	int vendor_notifier()
	{
		int i,j;
		for(i=0;i<10;i++)
		{
			if(p[i]>0)
			{
				return 1;
			}
			else if(i==9)
			{
				return 0;
			}
		}
	}
	virtual void interface()
	{
		
	}	
	virtual ~vendors()
	{
		
	}
};
class Vendors_Electronics:public vendors
{
	private:
		double profit_electronics;
	public:	
	Vendors_Electronics()
	{
		for(int i=0;i<10;i++)
		{
			p[i]=0;
		}
		profit_electronics=0;
	}
	void vendor_electronics_profit()
	{
		cout<<"Profit of Electronic Vendor "<<profit_electronics<<"Rs"<<endl;
	}
	void stock_provider_electronics()
	{
         	    
	    for(int i=0;i<10;i++)
	    {
	    	if(*(p+i)>0)
			{
				int a;
				system("cls");
				cout<<"\n\n";
           		cout<<"\n\t ____________________________________________________________________________";
		        cout<<"\n\t|                                                                            |";
				cout<<"\n\t| DO YOU WANT TO TRANSFER "<<left<<setw(5)<<*(p+i)<<" STOCK OF "<<left<<setw(30)<<s.getelectronicsname(i)<<"      |";
				cout<<"\n\t|____________________________________________________________________________|";
				cout<<"\n\t|           PRESS :                                                          |";
				cout<<"\n\t|                    1- TO TRANSFER                                          |";
				cout<<"\n\t|                    2- TO REMOVE                                            |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				cin>>a;
				if(a==1)	
				{
				cout<<"\n\t ____________________________________________________________________________";
				cout<<"\n\t|                                                                            |";
				cout<<"\n\t| "<<left<<setw(5)<<*(p+i)<<" STOCK OF "<<left<<setw(30)<<s.getelectronicsname(i)<<" HAS BEEN TRANSFERED          |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				delay(100);
				profit_electronics=profit_electronics+*(p+i)*(s.getelectronicsprice(i)-(s.getelectronicsprice(i)*0.1));	
				s.incrementelectronicstock(i,1000);
				
				p[i]=0;
				}
				else
				{
				cout<<"\n\t ____________________________________________________________________________";
				cout<<"\n\t|                                                                            |";
				cout<<"\n\t| STOCK OF "<<left<<setw(30)<<s.getelectronicsname(i)<<" NOT TRANSFERED                     |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				delay(100);
				}
			}
		}
	
		profit=profit-profit_electronics;
		profit_electronics=0;
		s.updatestock();
		updateelectronicstock();
	}
	
	void updateelectronicstock()
	{
		ofstream f("11109.txt",ios::out);
		for(int stock=0;stock<10;stock++)
		{
			f<<p[stock]<<endl;
		}
	}
	virtual void interface()//vendors_electronics()
{
	int x,y,z,i;
	ifstream f("11109.txt");
	for(int j=0;j<10;j++)
	{
		f>>p[j];
	} 
	if(s1=="electronics"||s1=="Electronics"||s1=="electronic" || 1)
	{
	x=vendor_notifier();
	if(x==1)
	{
		cout<<"\n";
		cout<<"\n\t _________________________________________________";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|         NOTIFICATIONS FOR VENDOR                |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n";
		cout<<"\n\t _________________________________________________ ";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|   PRESS :                                       |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n\t|            1 - TO OPEN                          |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n\t|            2 - TO REMOVE                        |";
		cout<<"\n\t|_________________________________________________|\n";
		
		cin>>y;
		if(y==1)
		{
		    
		cout<<"\n\t _________________________________________________ ";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|   STOCK LIST OF "<<left<<setw(15)<<s1<<"                 |";
		cout<<"\n\t|_________________________________________________|";
			cout<<"\n\t"<<left<<setw(20)<<"ITEM ID | ITEM STOCK LIST ";
			for(i=0;i<10;i++)
			{
				cout<<"\n\t"<<left<<setw(20)<<i<<" | "<<setw(20)<<right<<setw(20)<<p[i];
			}
			/*cout<<endl;
			cout<<"<<ITEM STOCK LIST>>>"<<endl;
			for(i=0;i<10;i++)
			{
				cout<<*(p+i)<<" ";
			}
			*/
			cout<<endl;
			cout<<"\n";
			cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|     TRANSFER OF STOCK             |";
			cout<<"\n\t|___________________________________|\n";
			stock_provider_electronics();
			cout<<endl;
			cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|     STOCK IS TRANSFERED           |";
			cout<<"\n\t|___________________________________|\n";
			
			vendor_electronics_profit();
		}
		else
		{
			cout<<"\n\t _______________________________________";
			cout<<"\n\t|                                       |";
			cout<<"\n\t|     NOTIFICATION HAS BEEN REMOVED     |";
			cout<<"\n\t|_______________________________________|\n";
			
			delay(150);
			cout<<endl;
			return;
		}
	}
	else
	{       cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|         NO NOTIFICATION           |";
			cout<<"\n\t|___________________________________|\n";
			
		delay(150);
		cout<<endl;
		return;
	}
	}
	else
	{
		    cout<<"\n\t ____________________________________________";
			cout<<"\n\t|                                            |";
			cout<<"\n\t|   NO NOTIFICATION FOR ELECTRONIC VENDOR    |";
			cout<<"\n\t|____________________________________________|\n";
			
		delay(150);
		cout<<endl;
		return;
	}
}
};
class Vendors_Hardware:public vendors
{
	private:
		double profit_hardware;
	public:	
	Vendors_Hardware()
	{
		for(int i=0;i<10;i++)
		{
			p[i]=0;
		}
		profit_hardware=0;
	}
	void vendor_hardware_profit()
	{
		cout<<"Profit of Hardware vendor is Equal to"<<profit_hardware<<"Rs"<<endl;
	}
	void stock_provider_hardware()
	{
		for(int i=0;i<10;i++)
	    {
	    	if(*(p+i)>0)
			{
				int a;
				system("cls");
				cout<<"\n\n";
           		cout<<"\n\t ____________________________________________________________________________";
		        cout<<"\n\t|                                                                            |";
				cout<<"\n\t| DO YOU WANT TO TRANSFER "<<left<<setw(5)<<*(p+i)<<" STOCK OF "<<left<<setw(30)<<s.gethardwarename(i)<<"      |";
				cout<<"\n\t|____________________________________________________________________________|";
				cout<<"\n\t|           PRESS :                                                          |";
				cout<<"\n\t|                    1- TO TRANSFER                                          |";
				cout<<"\n\t|                    2- TO REMOVE                                            |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				cin>>a;
				if(a==1)	
				{
				cout<<"\n\t ____________________________________________________________________________";
				cout<<"\n\t|                                                                            |";
				cout<<"\n\t| "<<left<<setw(5)<<*(p+i)<<" STOCK OF "<<left<<setw(30)<<s.gethardwarename(i)<<" HAS BEEN TRANSFERED          |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				delay(100);
				profit_hardware=profit_hardware+*(p+i)*(s.gethardwareprice(i)-(s.gethardwareprice(i)*0.1));	
				s.incrementhardwarestock(i,1000);
				
				p[i]=0;
				}
				else
				{
				cout<<"\n\t ____________________________________________________________________________";
				cout<<"\n\t|                                                                            |";
				cout<<"\n\t| STOCK OF "<<left<<setw(30)<<s.gethardwarename(i)<<" NOT TRANSFERED                     |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				delay(100);
				}
			}
		}
		
		profit=profit-profit_hardware;
		profit_hardware=0;
		s.updatestock();
		updatehardwarestock();
	}
	
	void updatehardwarestock()
	{
		ofstream f("11110.txt",ios::out);
		for(int stock=0;stock<10;stock++)
		{
			f<<p[stock]<<endl;
		}
	}
	virtual void interface()//vendors_hardware()
 {
 	ifstream f("11110.txt");
	for(int j=0;j<10;j++)
	{
		f>>p[j];
	}
 	int x,y,z,i;
	if(s1=="Hardware"||s1=="hardwares"||s1=="hardware" || 1)
	{
	x=vendor_notifier();
	if(x==1)
	{
		cout<<"\n";
		cout<<"\n\t _________________________________________________";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|         NOTIFICATIONS FOR VENDOR                |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n";
		cout<<"\n\t _________________________________________________ ";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|   PRESS :                                       |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n\t|            1 - TO OPEN                          |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n\t|            2 - TO REMOVE                        |";
		cout<<"\n\t|_________________________________________________|\n";
		cin>>y;
		if(y==1)
		{
			
		cout<<"\n\t _________________________________________________ ";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|   STOCK LIST OF "<<left<<setw(15)<<s1<<"                 |";
		cout<<"\n\t|_________________________________________________|";
			cout<<"\n\t"<<left<<setw(20)<<"Item Id's | ITEM STOCK LIST ";
			for(i=0;i<10;i++)
			{
				cout<<"\n\t"<<left<<setw(20)<<i<<" | "<<setw(20)<<right<<setw(20)<<p[i];
			}
			/*	cout<<endl;
			cout<<"<<ITEM STOCK LIST>>>"<<endl;
			for(i=0;i<10;i++)
			{
				cout<<*(p+i)<<" ";
			}*/
			cout<<endl;
			
			cout<<"\n";
			cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|     TRANSFER OF STOCK             |";
			cout<<"\n\t|___________________________________|\n";
			stock_provider_hardware();
			cout<<endl;
			
			cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|     STOCK IS TRANSFERED           |";
			cout<<"\n\t|___________________________________|\n";
			vendor_hardware_profit();
		}
		else
		{
			
			cout<<"\n\t _______________________________________";
			cout<<"\n\t|                                       |";
			cout<<"\n\t|     NOTIFICATION HAS BEEN REMOVED     |";
			cout<<"\n\t|_______________________________________|\n";
			delay(150);
			cout<<endl;
			return;
		}
	}
	else
	{
		      cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|         NO NOTIFICATION           |";
			cout<<"\n\t|___________________________________|\n";
		delay(150);
		cout<<endl;
		return;
	}
	}
	else
	{
		
		    cout<<"\n\t ____________________________________________";
			cout<<"\n\t|                                            |";
			cout<<"\n\t|   NO NOTIFICATION FOR HARDWARE VENDOR      |";
			cout<<"\n\t|____________________________________________|\n";
		delay(150);
		cout<<endl;
		return;
	}
}	
};
class Vendors_Mobile:public vendors
{
	private:
		
	double profit_mobiles;
	
	public:
		Vendors_Mobile()
		{
		for(int i=0;i<10;i++)
		{
			p[i]=0;
		}
			profit_mobiles=0;
		}
	void vendor_mobile_profit()
	{
		cout<<"Profit of mobile vendor is Equal to"<<profit_mobiles<<"Rs"<<endl;
	}
		
	void stock_provider_mobile()
	{
		for(int i=0;i<10;i++)
	    {
	    	if(*(p+i)>0)
			{
				int a;
				system("cls");
				cout<<"\n\n";
           		cout<<"\n\t ____________________________________________________________________________";
		        cout<<"\n\t|                                                                            |";
				cout<<"\n\t| DO YOU WANT TO TRANSFER "<<left<<setw(5)<<*(p+i)<<" STOCK OF "<<left<<setw(30)<<s.getmobilesname(i)<<"      |";
				cout<<"\n\t|____________________________________________________________________________|";
				cout<<"\n\t|           PRESS :                                                          |";
				cout<<"\n\t|                    1- TO TRANSFER                                          |";
				cout<<"\n\t|                    2- TO REMOVE                                            |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				cin>>a;
				if(a==1)	
				{
				cout<<"\n\t ____________________________________________________________________________";
				cout<<"\n\t|                                                                            |";
				cout<<"\n\t| "<<left<<setw(5)<<*(p+i)<<" STOCK OF "<<left<<setw(30)<<s.getmobilesname(i)<<" HAS BEEN TRANSFERED          |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				delay(100);
				profit_mobiles=profit_mobiles+*(p+i)*(s.getmobilesprice(i)-(s.getmobilesprice(i)*0.1));	
				s.incrementmobilestock(i,1000);
				
				p[i]=0;
				}
				else
				{
				cout<<"\n\t ____________________________________________________________________________";
				cout<<"\n\t|                                                                            |";
				cout<<"\n\t| STOCK OF "<<left<<setw(30)<<s.getmobilesname(i)<<" NOT TRANSFERED                     |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				delay(100);
				}
			}
		}
		profit=profit-profit_mobiles;
		profit_mobiles=0;
		s.updatestock();
		updatemobilestock();
	}
	
	void updatemobilestock()
	{
		ofstream f("11112.txt",ios::out);
		for(int stock=0;stock<10;stock++)
		{
			f<<p[stock]<<endl;
		}
	}
	virtual void interface()//vendors_mobile()
{
	ifstream f("11112.txt");
	for(int j=0;j<10;j++)
	{
		f>>p[j];
	}
 	int x,y,z,i;
	if(s1=="Mobile"||s1=="mobiles"||s1=="mobile" || 1)
	{
	x=vendor_notifier();
	if(x==1)
	{
		
		cout<<"\n";
		cout<<"\n\t _________________________________________________";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|         NOTIFICATIONS FOR VENDOR                |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n";
		cout<<"\n\t _________________________________________________ ";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|   PRESS :                                       |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n\t|            1 - TO OPEN                          |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n\t|            2 - TO REMOVE                        |";
		cout<<"\n\t|_________________________________________________|\n";
		cin>>y;
		if(y==1)
		{
			
		cout<<"\n\t _________________________________________________ ";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|   STOCK LIST OF "<<left<<setw(15)<<s1<<"                 |";
		cout<<"\n\t|_________________________________________________|";
			cout<<"\n\t"<<left<<setw(20)<<"ITEM ID | ITEM STOCK LIST ";
			for(i=0;i<10;i++)
			{
				cout<<"\n\t"<<left<<setw(20)<<i<<" | "<<setw(20)<<right<<setw(20)<<p[i];
			}
			/*	cout<<endl;
			cout<<"<<ITEM STOCK LIST>>>"<<endl;
			for(i=0;i<10;i++)
			{
				cout<<*(p+i)<<" ";
			}*/
			cout<<endl;
			
			cout<<"\n";
			cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|     TRANSFER OF STOCK             |";
			cout<<"\n\t|___________________________________|\n";
			stock_provider_mobile();
			cout<<endl;
			cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|     STOCK IS TRANSFERED           |";
			cout<<"\n\t|___________________________________|\n";
			vendor_mobile_profit();
		}
		else
		{
			cout<<"\n\t _______________________________________";
			cout<<"\n\t|                                       |";
			cout<<"\n\t|     NOTIFICATION HAS BEEN REMOVED     |";
			cout<<"\n\t|_______________________________________|\n";
			delay(150);
			cout<<endl;
			return;
		}
	}
	else
	{
		      cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|         NO NOTIFICATION           |";
			cout<<"\n\t|___________________________________|\n";
		delay(150);
		cout<<endl;
		return;
	}
	}
	else
	{
		    cout<<"\n\t ____________________________________________";
			cout<<"\n\t|                                            |";
			cout<<"\n\t|   NO NOTIFICATION FOR MOBILE VENDOR        |";
			cout<<"\n\t|____________________________________________|\n";
		delay(150);
		cout<<endl;
		return;
	}
}	
};
class Vendors_sports:public vendors
{
	private:
		double profit_sports;
	public:	
	Vendors_sports()
	{
		for(int i=0;i<10;i++)
		{
			p[i]=0;
		}
		profit_sports=0;
	}
	void vendor_sports_profit()
	{
		cout<<"Profit of sports vendor is Equal to "<<profit_sports<<"Rs"<<endl;
	}
	void stock_provider_sports()
	{
		for(int i=0;i<10;i++)
	    {
	    	if(*(p+i)>0)
			{
				int a;
				system("cls");
				cout<<"\n\n";
           		cout<<"\n\t ____________________________________________________________________________";
		        cout<<"\n\t|                                                                            |";
				cout<<"\n\t| DO YOU WANT TO TRANSFER "<<left<<setw(5)<<*(p+i)<<" STOCK OF "<<left<<setw(30)<<s.getsportsname(i)<<"      |";
				cout<<"\n\t|____________________________________________________________________________|";
				cout<<"\n\t|           PRESS :                                                          |";
				cout<<"\n\t|                    1- TO TRANSFER                                          |";
				cout<<"\n\t|                    2- TO REMOVE                                            |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				cin>>a;
				if(a==1)	
				{
				cout<<"\n\t ____________________________________________________________________________";
				cout<<"\n\t|                                                                            |";
				cout<<"\n\t| "<<left<<setw(5)<<*(p+i)<<" STOCK OF "<<left<<setw(30)<<s.getsportsname(i)<<" HAS BEEN TRANSFERED          |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				delay(100);
				profit_sports=profit_sports+*(p+i)*(s.getsportsprice(i)-(s.getsportsprice(i)*0.1));	
				s.incrementsportstock(i,1000);
				
				p[i]=0;
				}
				else
				{
				cout<<"\n\t ____________________________________________________________________________";
				cout<<"\n\t|                                                                            |";
				cout<<"\n\t| STOCK OF "<<left<<setw(30)<<s.getsportsname(i)<<" NOT TRANSFERED                     |";
				cout<<"\n\t|____________________________________________________________________________|\n";
				delay(100);
				}
			}
		}
		profit=profit-profit_sports;
		profit_sports=0;
		s.updatestock();
		updatesportstock();
	}
	void updatesportstock()
	{
		ofstream f("11111.txt",ios::out);
		for(int stock=0;stock<10;stock++)
		{
			f<<p[stock]<<endl;
		}
	}
	virtual void interface()//vendors_sports()
{
	ifstream f("11111.txt");
	for(int j=0;j<10;j++)
	{
		f>>p[j];
	}
 	int x,y,z,i;
	if(s1=="Sports"||s1=="sports"||s1=="sport" || 1)
	{
	x=vendor_notifier();
	if(x==1)
	{
		cout<<"\n";
		cout<<"\n\t _________________________________________________";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|         NOTIFICATIONS FOR VENDOR                |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n";
		cout<<"\n\t _________________________________________________ ";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|   PRESS :                                       |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n\t|            1 - TO OPEN                          |";
		cout<<"\n\t|_________________________________________________|";
		cout<<"\n\t|            2 - TO REMOVE                        |";
		cout<<"\n\t|_________________________________________________|\n";
		cin>>y;
		if(y==1)
		{
		cout<<"\n\t _________________________________________________ ";
		cout<<"\n\t|                                                 |";
		cout<<"\n\t|   STOCK LIST OF "<<left<<setw(15)<<s1<<"                 |";
		cout<<"\n\t|_________________________________________________|";
			cout<<"\n\t"<<left<<setw(20)<<"ITEM ID | ITEM STOCK LIST ";
			for(i=0;i<10;i++)
			{
				cout<<"\n\t"<<left<<setw(20)<<i<<" | "<<setw(20)<<right<<setw(20)<<p[i];
			}
			/*	cout<<endl;
			cout<<"<<ITEM STOCK LIST>>>"<<endl;
			for(i=0;i<10;i++)
			{
				cout<<*(p+i)<<" ";
			}*/
			cout<<endl;
			cout<<"\n";
			cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|     TRANSFER OF STOCK             |";
			cout<<"\n\t|___________________________________|\n";
			stock_provider_sports();
			cout<<endl;
			cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|     STOCK IS TRANSFERED           |";
			cout<<"\n\t|___________________________________|\n";
			vendor_sports_profit();
		}
		else
		{
			cout<<"\n\t _______________________________________";
			cout<<"\n\t|                                       |";
			cout<<"\n\t|     NOTIFICATION HAS BEEN REMOVED     |";
			cout<<"\n\t|_______________________________________|\n";
			delay(150);
			cout<<endl;
			return;
		}
	}
	else
	{
		      cout<<"\n\t ___________________________________";
			cout<<"\n\t|                                   |";
			cout<<"\n\t|         NO NOTIFICATION           |";
			cout<<"\n\t|___________________________________|\n";
		delay(150);
		cout<<endl;
		return;
	}
	}
	else
	{
		    cout<<"\n\t ____________________________________________";
			cout<<"\n\t|                                            |";
			cout<<"\n\t|   NO NOTIFICATION FOR HARDWARE VENDOR      |";
			cout<<"\n\t|____________________________________________|\n";
		delay(150);
		cout<<endl;
		return;
	}
}
	
	
};


class user
{
	private:
		accounts a;
        char name[11][50];
        double price[11];
        int quantity[11];
        double totalprice;
        int discount;
        static int h;
        static int shoppingofuser;
    public:
    	int i;
    	static int ifshop()
    	{
    		return shoppingofuser;
		}
		user()
		{
			for(int i=0;i<10;i++)
			{
				strcpy(name[i],"0");
				quantity[i]=0;
				price[i]=0.0;
				totalprice=0;
			}
			discount=0;
    		h=0;
    		totalprice=0;
    	}
        virtual void interface()
		{
			home:
				system("cls");
				
				
    cout<<"\n\n";
	cout<<"\n\t ____________________________________________________________________";
	cout<<"\n\t|                                                                    |";
	cout<<"\n\t|                  WELCOME TO H3S SHOPING MALL                       |";
	cout<<"\n\t|____________________________________________________________________|";
	cout<<"\n\t ____________________________________________________________________";
	cout<<"\n\t|                                                                    |";
	cout<<"\n\t|               ITEMS AVAILABLE IN REASONABLE PRICE                  |";
	cout<<"\n\t|____________________________________________________________________|";
    cout<<"\n\n";
	cout<<"\n\t _______________________________________________________________________________";
	cout<<"\n\t|                                                                               |";
    cout<<"\n\t|        SPECIAL OFFER !!!!!!!!!!!                                              |";
    cout<<"\n\t|        -------------------------                                              |";
    cout<<"\n\t|        * IF YOUR SHOPING EXCEED 1,00,000 RS YOU WILL GET STRAIGHT 7% DISCOUNT |";
    cout<<"\n\t|          -------------------------------------------------------------------- |";
    cout<<"\n\t|              SHOP NOW AND AVAIL THIS AMAZING OFFER  !!!!!!!!!!                |";
    cout<<"\n\t|              -------------------------------------------------                |";
	cout<<"\n\t|_______________________________________________________________________________|";
    cout<<"\n\t|                                                                               |";
    cout<<"\n\t|            THE ITEMS AVAILABLE ARE ..........                                 |";
	cout<<"\n\t|_______________________________________________________________________________|\n";
				
				
				s.displaymobiles();
				s.displayelectronics();
				s.displaysports();
				s.displayhardware();
				
			
				char nn;
				printf("\n\nPRESS ANY KEY TO CONTINUE......");
				nn=getch();
				
				
				
			int l;	
			login:
			l=a.interface();
			if(l!=1)
			{
				return;
			}
			else if(l==1)
			{
				while(1)
				{
					userhomescreen:
						system("cls");
						
						
		    cout<<"\n\n";
	    	cout<<"\n\t ________________________________________";
	        cout<<"\n\t|                                        |";
			cout<<"\n\t|      PRESS :                           |";
          	cout<<"\n\t|________________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 1  |          TO ADD CART              |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 2  |     TO GO INTO ACCOUNT SETTINGS   |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 3  |      TO GET YOUR PREVIOUS DATA    |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 4  |          TO GO BACK               |";
          	cout<<"\n\t|____|___________________________________|\n\t";
						
						
	    			char option;
	    			option=getche();
	    			if(option=='\b') {	a.setflag(0);	
					                    goto home;    }
	    			if(option=='1')
	    			{
	    				goto usermainscreen;
	    			}
	    			else if(option=='2')
	    			{
	    				int l;
	    				l=a.settings();
	    				if(a.getflag()==0)
	    				goto login;
					}
					else if(option=='3')
					{
						readfile();
					}
					else if(option=='4')
					{
						a.setflag(0);
						goto home;
					}
				}	
			}
				usermainscreen:
            int x;
            
            
    cout<<"\n\n";
	cout<<"\n\t ____________________________________________________________________";
	cout<<"\n\t|                                                                    |";
	cout<<"\n\t|                        MAIN SCREEN :                               |";
	cout<<"\n\t|____________________________________________________________________|";
	cout<<"\n\t|                                                                    |";
	cout<<"\n\t|                       SHOPPING CART                                |";
	cout<<"\n\t|____________________________________________________________________|";
	cout<<"\n\t|                  *MAXIMUM ORDER LIMIT IS 10                        |";
	cout<<"\n\t|____________________________________________________________________|";
    cout<<"\n";
            
            while(1)
    		{
    			agn1:
    			x=0;
            	system("cls");
                
				
			cout<<"\n\t ________________________________________";
			cout<<"\n\t|                                        |";
			cout<<"\n\t|      PRESS :                           |";
		    cout<<"\n\t|________________________________________|";
			cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 1  |          TO ENTER ORDER           |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 2  |         TO REMOVE ORDER           |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 3  |         TO DISPLAY ORDER          |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 4  |     TO END ORDER AND CHECKOUT     |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 5  |         TO DISCARD ORDER          |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|                                        |";
	        cout<<"\n\t|       YOUR CURRENT TOTAL IS :          |\b\b\b\b\b\b\b\b\b\b"<<totalprice;
          	cout<<"\n\t|________________________________________|\n\t";
				
				
				fflush(stdin);
				cin>>x;
                switch(x)
		    	{
                	case 1:
            		{
            			enterorder();
            			break;
		    		}
    	    		case 2:	
		    		{        
       	    			remove();
    	    			break;
	           		}
	        		case 3:
		    		{
    	    			display();
    	    			break;
    	    		}
	        		case 4:
		    		{
	        			system("cls");
	        			makebill();
	        		}
	        		case 5:
	        		{
	        			system("cls");
	        			for(int kk=0;kk<10;kk++)
	        			{
	        				totalprice=0;
	        				price[kk]=0;
	        				quantity[kk]=0;
	        				strcpy(name[kk],"\0");
						}
						h=0;
						i=0;
	        			goto userhomescreen;
					}
					default:
						goto agn1;
	        	}
            }
        }
        void enterorder()
		{ 	
		    shop s;
		    int id;
		    back:
			system("cls");
		    
			char hold;
		    
		    if(h>=10)
		    {
		    	cout<<"\n\n";
		    	cout<<"\n\t _____________________________________________";
		    	cout<<"\n\t|                                             |";
		    	cout<<"\n\t|           MAXIMUM ORDER LIMIT EXCEEDS       |";
		    	cout<<"\n\t|_____________________________________________|\n";
		    	cout<<"\n\t";system("PAUSE");return;
			}
		    
		    
           	cout<<"\n\t ________________________________________";
           	cout<<"\n\t|                                        |";
         	cout<<"\n\t|      CHOOSE CATEGORY :                 |";
            cout<<"\n\t|________________________________________|";
        	cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 1  |          MOBILES                  |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 2  |          HARDWARE                 |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 3  |          LAPTOPS                  |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 4  |          SPORTS                   |";
          	cout<<"\n\t|____|___________________________________|";
	        cout<<"\n\t|    |                                   |";
	        cout<<"\n\t| 5  |       RETURN TO MAIN SCREEN       |";
          	cout<<"\n\t|____|___________________________________|\n\t";
		    
		    
		    char ch;
		    ch=getche();
		    while(1)
		    {
		    	if(ch=='1')
		    	{
		    		nostock:
		    			system("cls");
		    		s.displaymobiles();
		    		cout<<"\n\n\tCHOOSE ANY PRODUCT BY ID (-1 to back): ";
		    		cin>>id;
		    		if(id == -1)
		    		{
		    			goto back;
					}
					else if(id>9)
					{
						cout<<"\n";
						cout<<"\n\t _____________________________";
						cout<<"\n\t|                             |";
						cout<<"\n\t|      INVALID CHOICE         |";
						cout<<"\n\t|_____________________________|";
						delay(100);
						goto back;
					}
		    		cout<<"\n\tENTER QUANTITY (-1 to back): ";
		    		cin>>quantity[h];
		    		if(quantity[h] == -1)
		    		{
		    			goto back;
					}
					else if(quantity[h] <= 0)
					{
						cout<<"\n";
						cout<<"\n\t _____________________________";
						cout<<"\n\t|                             |";
						cout<<"\n\t|      INVALID CHOICE         |";
						cout<<"\n\t|_____________________________|";
						delay(100);
						goto back;
					}
		    		int checkstock=stk.checkmobile(id,quantity[h]);
		    		if(checkstock==1)
		    		{
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         NOT ENOUGH STOCK AVAILABLE              |";
		    			cout<<"\n\t|_________________________________________________|\n";
		    			delay(150);
		    			goto nostock;
					}
					for(int stockcheck=0;stockcheck<h;stockcheck++)
					{
						if(strcmp(name[stockcheck],s.getmobilesname(id))==0)
						{
							
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         THE ITEM IS ALREADY IN YOUR CART...     |";
		    			cout<<"\n\t|_________________________________________________|\n";
		    			delay(150);
						goto nostock;
						
						}
						
					}
		    		strcpy(name[h],s.getmobilesname(id));
		    		price[h]=s.getmobilesprice(id);
					
					int q=quantity[h];
		    		double p=price[h];
		    		totalprice=totalprice + (price[h]*quantity[h] );
		    		
		    		
	cout<<"\n\t ____________________________________________________________________";
	cout<<"\n\t|                           |                                        |";
	cout<<"\n\t|   YOUR ITEM NAME IS       |                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	<<name[h];
	cout<<"\n\t|___________________________|________________________________________|";
	cout<<"\n\t|                           |                                        |";
	cout<<"\n\t|  YOUR ITEM PRICE IS (Q*P) |                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	<<"("<<quantity[h]<<" * "<<price[h]<<")"<<"  =  "<<((price[h]*quantity[h]));
	cout<<"\n\t|___________________________|________________________________________|\n";
		    		
		    		
					
					cout<<"\n\n\tPRESS ANY KEY TO CONTINUE ........";
		    		hold=getch();
		    		i++;
		    		h++;
		    		goto back;
		    		//return;
				}
				else if(ch=='2')
				{
					nostock1:
		    			system("cls");
					s.displayhardware();
		    		cout<<"\n\n\tCHOOSE ANY PRODUCT BY ID (-1 to back): ";
		    		cin>>id;
		    		if(id == -1)
		    		{
		    			goto back;
					}
					else if(id>9)
					{
						cout<<"\n";
						cout<<"\n\t _____________________________";
						cout<<"\n\t|                             |";
						cout<<"\n\t|      INVALID CHOICE         |";
						cout<<"\n\t|_____________________________|";
						delay(100);
						goto back;
					}
		    		cout<<"\n\tENTER QUANTITY (-1 to back): ";
		    		cin>>quantity[h];
		    		if(quantity[h] == -1)
		    		{
		    			goto back;
					}
					else if(quantity[h] <= 0)
					{
						cout<<"\n";
						cout<<"\n\t _____________________________";
						cout<<"\n\t|                             |";
						cout<<"\n\t|      INVALID CHOICE         |";
						cout<<"\n\t|_____________________________|";
						delay(100);
						goto back;
					}
		    		
		    		int checkstock=stk.checkhardware(id,quantity[h]);
		    		if(checkstock==1)
		    		{
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         NOT ENOUGH STOCK AVAILABLE              |";
		    			cout<<"\n\t|_________________________________________________|\n";
		    			delay(150);
		    			goto nostock1;
					}
		    		
					for(int stockcheck=0;stockcheck<h;stockcheck++)
					{
						if(strcmp(name[stockcheck],s.gethardwarename(id))==0)
						{
							
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         THE ITEM IS ALREADY IN YOUR CART...     |";
		    			cout<<"\n\t|_________________________________________________|\n";
		    			delay(150);
						goto nostock1;
						
						}
						
					}
		    		strcpy(name[h],s.gethardwarename(id));
		    		price[h]=s.gethardwareprice(id);
		    		
		    		int q=quantity[h];
		    		double p=price[h];
		    		totalprice=totalprice + (price[h]*quantity[h] );
		    		
		    		
	cout<<"\n\t ____________________________________________________________________";
	cout<<"\n\t|                           |                                        |";
	cout<<"\n\t|   YOUR ITEM NAME IS       |                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	<<name[h];
	cout<<"\n\t|___________________________|________________________________________|";
	cout<<"\n\t|                           |                                        |";
	cout<<"\n\t|  YOUR ITEM PRICE IS (Q*P) |                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	<<"("<<quantity[h]<<" * "<<price[h]<<")"<<"  =  "<<(price[h]*quantity[h]);
	cout<<"\n\t|___________________________|________________________________________|\n";
		    		
		    	    cout<<"\n\n\tPRESS ANY KEY TO CONTINUE ........";
		    		hold=getch();
		    		//return;
		    		
		    		i++;
		    		h++;
					goto back;
				}
				else if(ch=='3')
				{
					nostock2:
		    			system("cls");
					s.displayelectronics();
		    		cout<<"\n\n\tCHOOSE ANY PRODUCT BY ID (-1 to back): ";
		    		cin>>id;
		    		if(id == -1)
		    		{
		    			goto back;
					}
					else if(id>9)
					{
						cout<<"\n";
						cout<<"\n\t _____________________________";
						cout<<"\n\t|                             |";
						cout<<"\n\t|      INVALID CHOICE         |";
						cout<<"\n\t|_____________________________|";
						delay(100);
						goto back;
					}
		    		cout<<"\n\tENTER QUANTITY (-1 to back): ";
		    		cin>>quantity[h];
		    		if(quantity[h] == -1)
		    		{
		    			goto back;
					}
					else if(quantity[h] <= 0)
					{
						cout<<"\n";
						cout<<"\n\t _____________________________";
						cout<<"\n\t|                             |";
						cout<<"\n\t|      INVALID CHOICE         |";
						cout<<"\n\t|_____________________________|";
						delay(100);
						goto back;
					}
		    		
		    		int checkstock=stk.checkelectronic(id,quantity[h]);
		    		if(checkstock==1)
		    		{
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         NOT ENOUGH STOCK AVAILABLE              |";
		    			cout<<"\n\t|_________________________________________________|\n";
		    			delay(150);
		    			goto nostock2;
					}
		    		
					for(int stockcheck=0;stockcheck<h;stockcheck++)
					{
						if(strcmp(name[stockcheck],s.getelectronicsname(id))==0)
						{
							
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         THE ITEM IS ALREADY IN YOUR CART...     |";
		    			cout<<"\n\t|_________________________________________________|\n";
		    			delay(150);
						goto nostock2;
						
						}
						
					}
		    		strcpy(name[h],s.getelectronicsname(id));
		    		price[h]=s.getelectronicsprice(id);
		    		
		    		int q=quantity[h];
		    		double p=price[h];
		    		totalprice=totalprice + (price[h]*quantity[h] );
		    		
					
	cout<<"\n\t ____________________________________________________________________";
	cout<<"\n\t|                           |                                        |";
	cout<<"\n\t|   YOUR ITEM NAME IS       |                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	<<name[h];
	cout<<"\n\t|___________________________|________________________________________|";
	cout<<"\n\t|                           |                                        |";
	cout<<"\n\t|  YOUR ITEM PRICE IS (Q*P) |                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	<<"("<<quantity[h]<<" * "<<price[h]<<")"<<"  =  "<<((price[h]*quantity[h]));
	cout<<"\n\t|___________________________|________________________________________|\n";
					
					cout<<"\n\n\tPRESS ANY KEY TO CONTINUE ........";
		    		hold=getch();
		    		//return;
		    	    i++;
		    		h++;
					goto back;
					
				}
				else if(ch=='4')
				{
					nostock3:
		    			system("cls");
					s.displaysports();
		    		cout<<"\n\n\tCHOOSE ANY PRODUCT BY ID (-1 to back): ";
		    		cin>>id;
		    		if(id == -1)
		    		{
		    			goto back;
					}
					else if(id>9)
					{
						cout<<"\n";
						cout<<"\n\t _____________________________";
						cout<<"\n\t|                             |";
						cout<<"\n\t|      INVALID CHOICE         |";
						cout<<"\n\t|_____________________________|";
						delay(100);
						goto back;
					}
		    		cout<<"\n\tENTER QUANTITY (-1 to back): ";
		    		cin>>quantity[h];
		    		if(quantity[h] == -1)
		    		{
		    			goto back;
					}
					else if(quantity[h] <= 0)
					{
						cout<<"\n";
						cout<<"\n\t _____________________________";
						cout<<"\n\t|                             |";
						cout<<"\n\t|      INVALID CHOICE         |";
						cout<<"\n\t|_____________________________|";
						delay(100);
						goto back;
					}
		    		
		    		int checkstock=stk.checksport(id,quantity[h]);
		    		if(checkstock==1)
		    		{
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         NOT ENOUGH STOCK AVAILABLE              |";
		    			cout<<"\n\t|_________________________________________________|\n";
		    			delay(150);
		    			goto nostock3;
					}
		    		
					for(int stockcheck=0;stockcheck<h;stockcheck++)
					{
						if(strcmp(name[stockcheck],s.getsportsname(id))==0)
						{
							
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         THE ITEM IS ALREADY IN YOUR CART...     |";
		    			cout<<"\n\t|_________________________________________________|\n";
		    			delay(150);
						goto nostock3;
						
						}
						
					}
		    		strcpy(name[h],s.getsportsname(id));
		    		price[h]=s.getsportsprice(id);
		    		
		    		int q=quantity[h];
		    		double p=price[h];
		    		totalprice=totalprice + (price[h]*quantity[h] );
		    		
		    		
	cout<<"\n\t ____________________________________________________________________";
	cout<<"\n\t|                           |                                        |";
	cout<<"\n\t|   YOUR ITEM NAME IS       |                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	<<name[h];
	cout<<"\n\t|___________________________|________________________________________|";
	cout<<"\n\t|                           |                                        |";
	cout<<"\n\t|  YOUR ITEM PRICE IS (Q*P) |                                        |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
	<<"("<<quantity[h]<<" * "<<price[h]<<")"<<"  =  "<<(price[h]*quantity[h]);
	cout<<"\n\t|___________________________|________________________________________|\n";
					
					cout<<"\n\n\tPRESS ANY KEY TO CONTINUE ........";
		    		hold=getch();
		    		//return;
					
					i++;
		    		h++;
					goto back;
					
				}
				else if(ch=='5')
				{
					return;
				}
				else goto back;
			}
		    
    	}
    	void display()
		{    
    		int a=0;
    		if(h<=0 || totalprice<=0)
    		{
    			
    			cout<<"\n\t __________________________________";
				cout<<"\n\t|                                  |";
    			cout<<"\n\t|   YOU HAVEN'T ENTER ANY ORDER    |";
    			cout<<"\n\t|__________________________________|\n";
    			char hold;
    			cout<<"\n\tPRESS ANY KEY TO CONTINUE....";
    			hold=getch();
				return;
			}
    		
    cout<<"\n\n";
	cout<<"\n\t ___________________________________________________________________________";
	cout<<"\n\t|    |                             |                   |                    |";
	cout<<"\n\t| ID |   NAME                      |   QUANTITY        |     PRICE          |";
	cout<<"\n\t|____|_____________________________|___________________|____________________|";
    		
    		for(a=0;a<h;a++)
			{
				
				
				
	cout<<"\n\t|    |                             |                   |                    |";
	cout<<"\n\t"<<"|"<<left<<setw(3)<<a<<" |"<<left<<setw(29)<<name[a]<<"|"<<left<<setw(19)<<quantity[a]<<"|"<<left<<setw(20)<<fixed<<setprecision(2)<<(price[a]*quantity[a])<<"|";
	cout<<"\n\t|____|_____________________________|___________________|____________________|";

	    	}
	    	cout<<"\n";
	    	char hold;
	    	cout<<" \n\n\tPRESS ANY KEY TO CONTINUE.....";
	    	hold=getch();
	    }
	    int end()
		{
    		return 0;
		}
    	void total()
		{
    		double sum1=0;
    		int sum2=0,j;
    		for(j=0;j<i;j++)
			{
    			sum1=sum1+price[j]*quantity[j];
    			//sum2=sum2+quantity[j];
    		}
    		cout<<"Total Price of Orders :"<<sum1<<endl;
	    	//cout<<"Total Quantity Of products :"<<sum2<<endl;
	    }
	    void remove()
		{
    		int kkk;
    		char *a;
    		a=new char[30];
    		if(h==0 || totalprice<=0)
			{
				cout<<"\n\t __________________________________";
				cout<<"\n\t|                                  |";
    			cout<<"\n\t|   YOU HAVEN'T ENTER ANY ORDER    |";
    			cout<<"\n\t|__________________________________|\n";
    			char hold;
    			cout<<"\n\tPRESS ANY KEY TO CONTINUE....";
    			hold=getch();
				return;
    		}
    		else
			{   
			    int rem;
			    display();
        		cout<<"\n\tENTER PRODCUCT ID YOU WANT TO REMOVE (-1 to back)= ";
        		fflush(stdin);
				cin>>rem;
				if(rem==-1)
				{
					return;
				}
				//gets(a);
        		if(h==0)
	    		{
				
				cout<<"\n\t __________________________________";
				cout<<"\n\t|                                  |";
    			cout<<"\n\t|   YOU HAVEN'T ENTER ANY ORDER    |";
    			cout<<"\n\t|__________________________________|\n";
    			
				}	
				
				int flagg=0;
				
        		for(kkk=0;kkk<h;kkk++)    
    			{
	        		if(kkk==rem)
	    			{
	    				flagg=1;
    	    			int m=kkk;
	    	    		while(m<(h))
		    			{	
	            			strcpy(name[m],name[m+1]);
	            			price[m]=price[m+1];
	    	        		quantity[m]=quantity[m+1];
	            			m++;
		           		}
						   
						   h--;
						   
				cout<<"\n\t __________________________________";
				cout<<"\n\t|                                  |";
    			cout<<"\n\t|         REMOVED SUCCESSFULLY     |";
    			cout<<"\n\t|__________________________________|\n";
    			
						   
						   char hold;
						   cout<<" \n\tPRESS ANY KEY TO CONTINUE....";
						   hold=getch();
						   break;	
	        		}	
	        	}
    	    	if(flagg==0)
    	    	{
    	    		
				cout<<"\n\t __________________________________";
				cout<<"\n\t|  ERROR !!!                       |";
    			cout<<"\n\t|          ID DOESNOT MATCH...     |";
    			cout<<"\n\t|__________________________________|\n";
    			cout<<"\n\t";system("PAUSE");
				}
    	    	totalprice=0;
    	    	for(kkk=0;kkk<h;kkk++)
    	    	{
    	    		totalprice=totalprice+price[kkk]*quantity[kkk];
				}
    	    	
    	    	
    	    	return;
	        }
	    }
	    void makebill()
		{
			
			if(h<=0 || totalprice<=0)
			{
				cout<<"\n\t __________________________________";
				cout<<"\n\t|                                  |";
    			cout<<"\n\t|   YOU HAVEN'T ENTER ANY ORDER    |";
    			cout<<"\n\t|__________________________________|\n";
    			char hold;
    			cout<<"\n\tPRESS ANY KEY TO CONTINUE....";
    			hold=getch();
				return;
			}
			
    cout<<"\n\n";
	cout<<"\n\t ______________________________________________________________________";
	cout<<"\n\t|                                                                      |";
	cout<<"\n\t|                    YOUR BILL                                         |";
	cout<<"\n\t|______________________________________________________________________|";
	cout<<"\n\t|                             |                   |                    |";
	cout<<"\n\t|   NAME                      | QUANTITY * PRICE  | TOTAL PRICE        |";
	cout<<"\n\t|_____________________________|___________________|____________________|";
			
			
			for(int bill=0;bill<h;bill++)
			{
				if(price[bill]<=0 || quantity[bill]<=0)
				{
					continue;
				}
				else
				
				
	cout<<"\n\t|                             |                   |                    |";
	cout<<"\n\t"<<"|"<<left<<setw(29)<<name[bill]<<"|"<<left<<setw(5)<<quantity[bill]<<" * "<<left<<setw(11)<<price[bill]<<"|"<<left<<setw(20)<<fixed<<setprecision(2)<<(price[bill]*quantity[bill])<<"|";
	cout<<"\n\t|_____________________________|___________________|____________________|";
				
				
				for(int ii=0;ii<10;ii++)
				{
					if(strcmp(s.getelectronicsname(ii),name[bill])==0)
					{
						s.incrementelectronicstock(ii,-(quantity[bill]));
					}
					else if(strcmp(s.getmobilesname(ii),name[bill])==0)
					{
						s.incrementmobilestock(ii,(-quantity[bill]));
					}
					else if(strcmp(s.gethardwarename(ii),name[bill])==0)
					{
						s.incrementhardwarestock(ii,(-quantity[bill]));
					}
					else if(strcmp(s.getsportsname(ii),name[bill])==0)
					{
						s.incrementsportstock(ii,(-quantity[bill]));
					}
				}
				s.updatestock();
				shoppingofuser=1;
			}
			
			
	cout<<"\n\t ______________________________________________________________________";
	cout<<"\n\t|                                                                      |";
	cout<<"\n\t|                   YOUR TOTAL = "<<left<<setw(15)<<totalprice<<"                       |";
	cout<<"\n\t|______________________________________________________________________|";
			
			
			
			if(totalprice>=100000.0)
			{
				discount=1;
				checkdiscount();
				
	cout<<"\n\t ______________________________________________________________________";
	cout<<"\n\t|                                                                      |";
	cout<<"\n\t|                    YOUR TOTAL AFTER 7% DISCOUNT = "<<left<<setw(15)<<totalprice<<"    |";
	cout<<"\n\t|______________________________________________________________________|";
				
				profit=profit+totalprice;
			}
			else 
			{
				discount=0;
				profit=profit+totalprice;
			}
			
			makefile();
		}
	    void makefile()
		{
			FILE *p;
			int k=0;
			time_t times;
			char *date;
			times=time(NULL);
			date=ctime(&times);
			char username[30];
			;
			strcpy(username,a.getusername());
			p=fopen("11102.dat","a");
			while(k<1)
			{
				fprintf(p,"\n%s",username);
				fprintf(p,"\n%s",date);
				fprintf(p,"\n%lf",totalprice);
				fprintf(p,"\n%d",discount);
				for(int useritem=0;useritem<10;useritem++)
			    {
			    	if(price[useritem]==0 || quantity[useritem]==0)
			    	{
			    		fprintf(p,"\n%s","0");
			    		fprintf(p,"\n%d",0);
			    		continue;
					}
					else
					{
					     fprintf(p,"\n%s",name[useritem]);
		    	    	 fprintf(p,"\n%d",quantity[useritem]);
					}
			    	 
			    }
			   //fprintf(p,"\n%s","^Z");
			   k++;
			}
			cout<<endl<<endl<<endl<<"\tFILE SUCCESSFULLY CREATED..... \n";
			fclose(p);
			char hold;
			cout<<"\n\tPRESS ANY KEY TO CONTINUE....";
			hold=getch();
			return;
		}
		void checkdiscount()
		{
			{
				totalprice=totalprice-(totalprice*0.07);
				discount=1;
			}
		}
		readfile()
		{
			
			    string discnt;
			int check=0;
			system("cls");
			FILE *p;
			char end[5],item1[10],username1[30],date1[30],username[30];
			strcpy(username,a.getusername());
			int quantity1,discount1=0;
			double totalprice1,grandtotal=0;
			p=fopen("11102.dat","r");
			if(p==NULL)
			{
				
	cout<<"\n\t ______________________________________________________________________";
	cout<<"\n\t|           ERROR !!!!                                                 |";
	cout<<"\n\t|                    NO SHOPPING HAS BEEN DONE BEFORE...               |";
	cout<<"\n\t|______________________________________________________________________|";
	
				goto hld;
			}
			fscanf(p,"\n%s",username1);
			
			
    cout<<"\n\n";
	cout<<"\n\t _________________________________________________";
	cout<<"\n\t|                                                 |";
	cout<<"\n\t|             YOUR PREVIOUS SHOPPING              |";
	cout<<"\n\t|_________________________________________________|";
			
			while(!feof(p))
			{
				
				if(strcmp(username1,username)!=0)
				{
					fscanf(p,"\n%[^\n]s",date1);
					fscanf(p,"\n%lf",&totalprice1);
     				fscanf(p,"\n%d",&discount1);
     				for(int i=0;i<10;i++)
			        {
		        		fscanf(p,"\n%[^\n]s",item1);
			    		fscanf(p,"\n%d",&quantity1);
			    	}
				    //fscanf(p,"\n%s",end);
					goto jump;
				}
				
				check=1;
				
				fscanf(p,"\n%[^\n]s",date1);
				
				
				
	cout<<"\n\t _________________________________________________";
	cout<<"\n\t|                                                 |";
	cout<<"\n\t|     DATE = "<<setw(30)<<date1<<"       |";
	cout<<"\n\t|_________________________________________________|";
	cout<<"\n\t|                                   |             |";
	cout<<"\n\t|   NAME                            | QUANTITY    |";
	cout<<"\n\t|___________________________________|_____________|";
				
				
				fscanf(p,"\n%lf",&totalprice1);
				discount1=0;
				fscanf(p,"\n%d",&discount1);
				
				for(int i=0;i<10;i++)
			    {
		    		fscanf(p,"\n%[^\n]s",item1);
					fscanf(p,"\n%d",&quantity1);
					if(quantity1<=0 && (strcmp(item1,"0")==0) )
					{
						continue;
					}
				    else 
					{
						
						
	cout<<"\n\t|"<<left<<setw(35)<<item1<<"|"<<left<<setw(13)<<quantity1<<"|";
	cout<<"\n\t|___________________________________|_____________|";
						
						
					}
			    }
			    
				if(discount1==1)
			    {
			    	discnt=" WITH DISCOUNT";
				}
				else discnt=" WITHOUT DISCOUNT";
			    
	cout<<"\n\t|                                                 |";
	cout<<"\n\t|    TOTAL = "<<left<<setw(14)<<fixed<<setprecision(2)<<totalprice1<<left<<setw(20)<<discnt<<"   |";
	cout<<"\n\t|_________________________________________________|\n";
			    
				grandtotal=grandtotal+totalprice1;
			    
			    //fscanf(p,"\n%s",end);
			    
			    jump:
			    	printf("\n");
			    
			    fscanf(p,"\n%[^\n]s",username1);
			}
			if(check==0)
			{
				system("cls");
	cout<<"\n\t _________________________________________________";
	cout<<"\n\t|                                                 |";
	cout<<"\n\t|      SORRY WE DONOT HAVE YOUR PREVIOUS DATA...  |";
	cout<<"\n\t|_________________________________________________|\n";
				
				
				fclose(p);
				goto hld;
			}
			fclose(p);
			if(grandtotal!=totalprice1 && grandtotal!=0)
			{
				
	cout<<"\n\n\n\t _______________________________________________________________________________";			
    cout<<"\n\t|                                                                               |";
    cout<<"\n\t|            THE GRAND TOTAL OF YOUR SHOPPING IS = "<<left<<setw(17)<<fixed<<setprecision(2)<<grandtotal<<"Rs          |";
	cout<<"\n\t|_______________________________________________________________________________|\n";
				
				
			}
			hld:
			char hold;
			cout<<"\n\n\tPRESS ANY KEY TO CONTINUE.....";
			hold=getch();
			return 0;
		}
	
};
int user::h=0;
int user::shoppingofuser=0;


class admin
{
	public:
		vendors *v;
		double    adminprofit;
		int       saleperday;
	
	public:
		void setvendor(vendors &ven)
		{
			v=&ven;
		}
		void withdraw()
		{
			double wd;
			system("cls");
			cout<<"\n\n\tENTER AMOUNT YOU WANT TO WITHDRAW FROM SHOP (-1 to exit) : ";
			cin>>wd;
			if(wd==-1)
			{
				return;
			}
			updateprofit();
			if(adminprofit<wd)
			{
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t| ERROR....                                       |";
		    			cout<<"\n\t|         SHOP DOESNOT HAVE ENOUGH AMOUNT         |";
		    			cout<<"\n\t|_________________________________________________|\n";
				delay(150);
				return;
			}
			else 
			{
				profit-=wd;
				updateprofit();
				
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t|          AMOUNT HAS BEEN WITHDRAWN              |";
		    			cout<<"\n\t|_________________________________________________|\n";
				delay(150);
				return;
			}
		}
		void deposit()
		{
			double d;
			system("cls");
			cout<<"\n\tENTER AMOUNT YOU WANT TO DEPOSIT TO SHOP (-1 to exit): ";
			cin>>d;
			if(d==-1)
			{
				return;
			}
			profit+=d;
			updateprofit();
			
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t|          AMOUNT HAS BEEN DEPOSIT                |";
		    			cout<<"\n\t|_________________________________________________|\n";
			
			delay(150);
			return;
		}
		admin()
		{
			ifstream f("11105.txt");
			if(!f)
			{
				ofstream l;
				l.open("11105.txt");
				if(!l)
 				{cout<<"\n";
		    			cout<<"\n\t _____________________________________________________________________________ ";
		    			cout<<"\n\t|   ERROR !!!                                                                 |";
		    			cout<<"\n\t|          FIRST TURN OFF CONTROLLED FOLDER ACCESS AND ANTIVIRUS THEN START...|";
		    			cout<<"\n\t|_____________________________________________________________________________|\n";
				system("PAUSE");
 					exit(0);
 				}
				l<<10000000;
				l.close();
				adminprofit=10000000;
				goto jump;
			}
			f>>adminprofit;
			f.close();
			jump:
			saleperday=0;
		}
		updateprofit()
		{
			adminprofit=profit+adminprofit;
			profit=0;
			ofstream f;
				f.open("11105.txt");
				f<<adminprofit;
				f.close();
		}
		virtual void interface()
		{
			
	    		char aa[30],bb[30],cc[30],dd[30],ee[30],checka[30],checkb[30],checkc[30],checkd[30];
				time_t times=time(NULL);
				char *date;
				date=ctime(&times);
				//cout<<date;
				fstream f("11108.txt",ios::out);
				f<<date;
				f.close();
			
				ifstream check("11107.txt");
				check>>checka;
				check>>checkb;
				check>>checkc;
				check>>checkd;
	
			     	f.open("11108.txt",ios::in);
					f>>aa;
					f>>bb;
					f>>cc;
					f>>dd;
					if(dd[0]<=checkd[0]) 
						if(dd[1]<=checkd[1])
							if(dd[3]<=checkd[3])
								if(dd[4]<checkd[4])
								{
								    system("cls");
									cout<<"\n\t ____________________________________________";
									cout<<"\n\t|                                            |";
									cout<<"\n\t| ADMIN PANEL IS LOCKED FOR SECURITY PURPOSE |";
									cout<<"\n\t|____________________________________________|";
									cout<<"\n\t|                                            |";
									cout<<"\n\t|    *   WAIT A MINUTE OR TWO                |";
									cout<<"\n\t|____________________________________________|";
								
									delay(220);
									exit(0);
								}
					f.close();
					check.close();
			
			
			int flag=0;
			static int nopin=0;
			if(nopin==3)
			{
				system("cls");
				
    cout<<"\n ____________________________________________________________________";
	cout<<"\n|                                                                    |";
	cout<<"\n|        ERROR # 101 !!!!!            :(                             |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|                                                                    |";
	cout<<"\n| YOU MUST NOT TRY TO BREAK INTO ADMIN ACCOUNT ...STAY AWAY !!!!!    |";
	cout<<"\n|                PROGRAM IS CLOSING FOR SECURITY PURPOSE....         |";
	cout<<"\n|____________________________________________________________________|";
	cout<<"\n|                                                                    |";
	cout<<"\n|                                                                    |";
	cout<<"\n|           THE ADMIN PANEL IS LOCKED FOR 2 MINUTES                  |";
	cout<<"\n|           ---------------------------------------                  |";
	cout<<"\n|____________________________________________________________________|";
	
				
				    f.open("11108.txt",ios::in);
             		f>>aa;
                  	f>>bb;
             		f>>cc;
            		f>>dd;
             		if(dd[4]<='7')
             		{ 
             			 dd[4]+=2;
		             	 f>>ee;
	             		 f.close();
             			 ofstream ss("11107.txt"); 
	             		 ss<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<ee<<endl; 
	             		 ss.close();
            		}
            		else if(dd[4]=='8' && dd[3]<'5')
            		{
            			 dd[3]+=1;
            			 dd[4]=='0';
		             	 f>>ee;
	             		 f.close();
             			 ofstream ss("11107.txt"); 
	             		 ss<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<ee<<endl;
	             		 ss.close();
					}
					else if(dd[4]=='9' && dd[3]<'5')
					{
						 dd[3]+=1;
					     dd[4]=='1';
		             	 f>>ee;
	             		 f.close();
             			 ofstream ss("11107.txt"); 
	             		 ss<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<ee<<endl;
	             		 ss.close();
					}
	            	else
	             	{
	             		f>>ee;
	             		ofstream ss("11107.txt"); 
	             		ss.close();
	            		f.close();
	              	}
               	
				updateprofit();
				delay(250);
				exit(0);
			}
			{
				pin:
					system("cls");
				
				
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|        PLEASE ENTER PIN TO LOG INTO ADMIN ACCOUNT             |";
	cout<<"\n|_______________________________________________________________|";
	
	cout<<"\n\n\n         ENTER PIN : ____ \b\b\b\b\b";
					
				flag=0;
				int input=0;
				char ch[10],p[]="1023";
				while(1)
				{
					jkl:
					ch[input]=getche();
					if(ch[input]=='\b')
					{
						if(input==0) 
						{
							return;
							printf(" ");
							goto jkl;
						}
						input--;
						printf("__\b\b");
						goto jkl;
					}
					delay(5);
					printf("\b#");
					if(input==3)
					{
						if(ch[0]==p[0] && ch[1]==p[1] && ch[2]==p[2] && ch[3]==p[3])
						{
							flag=1;
							break;
						}
					}
					input++;
					if(input>3)
					{
						
						
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|        !!!!!!!!!!!!!!!    ALERT   !!!!!!!!!!!!!!!!!           |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|              SORRY WRONG PIN...                               |"; 
	cout<<"\n|                        PLEASE ENTER CORRECT PIN !!!!          |";
	cout<<"\n|_______________________________________________________________|";
						
						nopin++;
						delay(150);
						return;
					}
				}
			}
			if(flag==0)
			{
		     	return;
		    }
			else if(flag==1)
			{
				nopin=0;
				ofstream ll("11107.txt");
				ll.close();
			}
			
			int *q,l[10];
			system("cls");
			stk.GetStock();
			stk.displaystock();
			char hold;
			cout<<"\n\n\tPRESS ANY KEY TO CONTINUE....";
			hold=getch();
			while(1)
			{
				system("cls");
				stk.displaystock();
				
				
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|              ADMIN'S PANEL                                    |"; 
	cout<<"\n|              -------------                                    |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|    PRESS :                                                    |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""0""- TO UPDATE AND CHECK BALANCE                         |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""1""- TO DEPOSIT AMOUNT TO SHOP                           |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""2""- TO WITHDRAW AMOUNT TO SHOP                          |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|       WHICH CATEGORY OF STOCK YOU WANT TO ORDER ?             |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""3""- ELECTRONIC                                          |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""4""- HARDWARE                                            |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""5""- SPORTS                                              |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""6""- MOBILES                                             |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""7""- TO GO INTO USER DATABASE                            |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""8""- TO DELETE SHOP DATA                                 |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""9""- TO GO BACK                                          |";
	cout<<"\n|_______________________________________________________________|\n";
	

				
				int ss;
				cin>>ss;
		        if(ss==0)
		        {
		        	updateprofit();
		        	system("cls");
		        	
		    			cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t|    YOUR CURRENT BALANCE IS = "<<left<<setw(19)<<adminprofit<<"|";
		    			cout<<"\n\t|_________________________________________________|\n";
		        	char hold;
		        	cout<<"\n\tPRESS ANY KEY TO CONTINUE....";
		        	hold=getch();
				}
				else if(ss==1)
				{
					deposit();
				}
				else if(ss==2)
				{
					withdraw();
				}
				else if(ss==3)
				{
					q=enterelectronicstock();
					
					for(int lmn=0;lmn<10;lmn++)
					{
						q[lmn]=0;
					}
				}
				else if(ss==4)
				{
					q=enterhardwarestock();
					
					
					for(int lmn=0;lmn<10;lmn++)
					{
						q[lmn]=0;
					}
				}
				else if(ss==5)
				{
					q=entersportstock();
					
					
					for(int lmn=0;lmn<10;lmn++)
					{
						q[lmn]=0;
					}
				}
				else if(ss==6)
				{
					q=entermobilestock();
					
					for(int lmn=0;lmn<10;lmn++)
					{
						q[lmn]=0;
					}
				}
				else if(ss==7)
				{
					userdatabaseread();
				}
				else if(ss==8)
				{
					remove("11101.txt");
					remove("C:\\Users\\Public\\Pictures\\11101.txt");
					remove("11102.dat");
					remove("11103.txt");
					remove("11104.dat");
					remove("11105.txt");
					remove("11106.txt");
					remove("C:\\Users\\Public\\Pictures\\11106.txt");
					remove("11107.txt");
					remove("11108.txt");
					remove("11109.txt");
					remove("11110.txt");
					remove("11111.txt");
					remove("11112.txt");
				}
				else if(ss==9)
				{
					return ;
				}
			}
			
		}
		void userdatabaseread()
		{
			
			string discnt;
			int check=0;
			system("cls");
			FILE *p;
			char end[5],item1[10],username1[30],date1[30],username[30];
			
			int quantity1,discount1=0;
			double totalprice1,grandtotal=0;
			p=fopen("11102.dat","r");
			if(p==NULL)
			{
				
				cout<<"\n\t ______________________________________________________________________";
				cout<<"\n\t|           ERROR !!!!                                                 |";
				cout<<"\n\t|                    NO SHOPPING HAS BEEN DONE BEFORE...               |";
				cout<<"\n\t|______________________________________________________________________|";
	
				goto hld;
			}
			fscanf(p,"\n%s",username1);
			
			
			cout<<"\n\n";
			cout<<"\n\t _______________________________________________________";
			cout<<"\n\t|_______________________________________________________|";
			cout<<"\n\t|                                                       |";
			cout<<"\n\t|                      THE USER DATA BASE               |";
			cout<<"\n\t|_______________________________________________________|";
			cout<<"\n\t|_______________________________________________________|\n\n\n";
			
			while(!feof(p))
			{
				
				fscanf(p,"\n%[^\n]s",date1);
	
				cout<<"\n\t _________________________________________________";
				cout<<"\n\t|                                                 |";
				cout<<"\n\t| USERNAME = "<<left<<setw(30)<<username1<<"       |";
				cout<<"\n\t|_________________________________________________|";
				cout<<"\n\t|                                                 |";
				cout<<"\n\t|     DATE = "<<setw(30)<<date1<<"       |";
				cout<<"\n\t|_________________________________________________|";
				cout<<"\n\t|                                   |             |";
				cout<<"\n\t|   NAME                            | QUANTITY    |";
				cout<<"\n\t|___________________________________|_____________|";
				
				fscanf(p,"\n%lf",&totalprice1);
				discount1=0;
				fscanf(p,"\n%d",&discount1);
				
				for(int i=0;i<10;i++)
			    {
		    		fscanf(p,"\n%[^\n]s",item1);
					fscanf(p,"\n%d",&quantity1);
					if(quantity1<=0 && (strcmp(item1,"0")==0) )
					{
						continue;
					}
				    else 
					{
								
						cout<<"\n\t|"<<left<<setw(35)<<item1<<"|"<<left<<setw(13)<<quantity1<<"|";
						cout<<"\n\t|___________________________________|_____________|";
						
					}
			    }
			    
				if(discount1==1)
			    {
			    	discnt=" WITH DISCOUNT";
				}
				else discnt=" WITHOUT DISCOUNT";
			    
				cout<<"\n\t|                                                 |";
				cout<<"\n\t|    TOTAL = "<<left<<setw(14)<<fixed<<setprecision(2)<<totalprice1<<left<<setw(20)<<discnt<<"   |";
				cout<<"\n\t|_________________________________________________|\n";
			    
			    //fscanf(p,"\n%s",end);
			    
			    jump:
			    	printf("\n");
			    
			    fscanf(p,"\n%[^\n]s",username1);
			}
			fclose(p);
			
			hld:
				
			char hold;
			cout<<"\n\n\tPRESS ANY KEY TO CONTINUE.....";
			hold=getch();
}
		int* enterelectronicstock()
		{
			int p[10]={0,0,0,0,0,0,0,0,0,0};
			
			int flag1=0,flag2=0;
			
			system("cls");
			for(int item=0;item<10;item++)
			{
				if(stk.getstockelectronics(item)==1000)
				{
					p[item]=0;
					continue;
				}
				cout<<endl<<setw(30)<<s.getelectronicsname(item)<<setw(20)<<right<<setw(20)<<stk.getstockelectronics(item)<<"    ORDER STOCK TO 1000 OR NOT (1/0) : ";
				cin>>p[item];
				if(p[item]==1)
				{
					p[item]=1000-stk.getstockelectronics(item);
					flag1=1;
				}
				else 
				{
					p[item]=0;
					flag2=1;
				}
			}
			
			v->getstock(p,"electronics");
			
					
					if(flag1==1)
					{
					cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t|           ITEM HAS BEEN ORDERED                 |";
		    			cout<<"\n\t|_________________________________________________|\n";
					
					delay(120);
				    }
				    else if(flag1==0 && flag2==0) 
				    {
				    	
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|              STOCK IS FULL, NO ITEM TO ORDER                  |"; 
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
				    	
				    	delay(120);
					}
					
					
			return p;
		}
		int* enterhardwarestock()
		{
			int flag1=0,flag2=0;
			int p[10]={0,0,0,0,0,0,0,0,0,0};
			system("cls");
			for(int item=0;item<10;item++)
			{
				if(stk.getstockhardware(item)==1000)
				{
					p[item]=0;
					continue;
				}
				cout<<endl<<setw(30)<<s.gethardwarename(item)<<setw(20)<<right<<setw(20)<<stk.getstockhardware(item)<<"    ORDER STOCK TO 1000 OR NOT (1/0) : ";
				cin>>p[item];
				if(p[item]==1)
				{
					p[item]=1000-stk.getstockhardware(item);
					flag1=1;
				}
				else 
				{
					p[item]=0;
					flag2=1;
				}
			}
			v->getstock(p,"hardware");
			
				
			if(flag1==1)
					{
					cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t|           ITEM HAS BEEN ORDERED                 |";
		    			cout<<"\n\t|_________________________________________________|\n";
					
					delay(120);
				    }
				    else if(flag1==0 && flag2==0) 
				    {
				    	
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|              STOCK IS FULL, NO ITEM TO ORDER                  |"; 
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
				    	
				    	delay(120);
					}
			
			return p;
		}
		int* entermobilestock()
		{
			int flag1=0,flag2=0;
			int p[10]={0,0,0,0,0,0,0,0,0,0};
			system("cls");
			for(int item=0;item<10;item++)
			{
				if(stk.getstockmobiles(item)==1000)
				{
					p[item]=0;
					continue;
				}
				cout<<endl<<setw(30)<<s.getmobilesname(item)<<setw(20)<<right<<setw(20)<<stk.getstockmobiles(item)<<"    ORDER STOCK TO 1000 OR NOT (1/0) : ";
				cin>>p[item];
				if(p[item]==1)
				{
					p[item]=1000-stk.getstockmobiles(item);
					flag1=1;
				}
				else 
				{
					p[item]=0;
					flag2=1;
				}
			}
			v->getstock(p,"mobiles");
			
			if(flag1==1)
					{
					cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t|           ITEM HAS BEEN ORDERED                 |";
		    			cout<<"\n\t|_________________________________________________|\n";
					
					delay(120);
				    }
				    else if(flag1==0 && flag2==0) 
				    {
				    	
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|              STOCK IS FULL, NO ITEM TO ORDER                  |"; 
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
				    	
				    	delay(120);
					}
			return p;
		}
		int* entersportstock()
		{
			int flag1=0,flag2=0;
			int p[10]={0,0,0,0,0,0,0,0,0,0};
			system("cls");
			for(int item=0;item<10;item++)
			{
				if(stk.getstocksports(item)==1000)
				{
					p[item]=0;
					continue;
				}
				cout<<endl<<setw(30)<<s.getsportsname(item)<<setw(20)<<right<<setw(20)<<stk.getstocksports(item)<<"    ORDER STOCK TO 1000 OR NOT (1/0) : ";
				cin>>p[item];
				if(p[item]==1)
				{
					p[item]=1000-stk.getstocksports(item);
					flag1=1;
				}
				else 
				{
					p[item]=0;
					flag2=1;
				}
			}
			v->getstock(p,"sports");
			
			
			if(flag1==1)
					{
					cout<<"\n";
		    			cout<<"\n\t _________________________________________________ ";
		    			cout<<"\n\t|                                                 |";
		    			cout<<"\n\t|           ITEM HAS BEEN ORDERED                 |";
		    			cout<<"\n\t|_________________________________________________|\n";
					
					delay(120);
				    }
				    else if(flag1==0 && flag2==0) 
				    {
				    	
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|              STOCK IS FULL, NO ITEM TO ORDER                  |"; 
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
				    	
				    	delay(120);
					}
			
			return p;
		}
	
		CalculateSalePerDay()
		{
			
		}
		MakeFile()
		{
			time_t times;
			int i=0;
			char *date,day[10],dateinfile[20],datainfile[30];
			times=time(NULL);
			date=ctime(&times);
			FILE *p;
			p=fopen("admin.dat","a");
			i=0;
			while(i!=1)
			{
				fprintf(p,"\n%s",date);
				fprintf(p,"%lf",profit);
				fprintf(p,"\n%d",saleperday);
				fprintf(p,"\n^Z");
				i++;
			}
			fclose(p);
		}
		TotalProfitAndSales()
		{
			FILE *p;
			char date1[50];
			double profit1=0,totalprofit=0;
			int saleperday1=0,totalsales=0;
			p=fopen("admin.dat","r");
			char end[10];
		
			while(!feof(p))
			{
				fscanf(p,"\n%[^\n]s",date1);	
				fscanf(p,"%lf",&profit1);
				fscanf(p,"\n%d",&saleperday1);
				fscanf(p,"\n%s",end);
				totalprofit=totalprofit+profit1;
				totalsales=totalsales+saleperday1;
			}
			fclose(p);
			printf("\nTOTAL SALES = %d",totalsales);
			printf("\nTOTAL PROFIT = %lf",totalprofit);
		}
};
main()
{
	char c;
	        user u;
         	admin a;
         	vendors v;
         	vendors *vp;
         	a.setvendor(v);
	admin *p;
	stk.GetStock();
	while(1)
	{
		h:
		system("cls");
		
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|                  WELCOME TO H3S SHOPING MALL                  |"; 
	cout<<"\n|                  --------------------------                   |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|    PRESS :                                                    |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""1""- TO GO INTO  ""USER PANEL""                              |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""2""- TO GO INTO  ""ADMIN PANEL""                             |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""3""- TO GO INTO  ""VENDORS PANEL""                           |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""4""- TO EXIT FROM SHOP                                   |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|\n";	
	
		c=getche();
		if(c=='1')
		{
			p=(admin*)(&u);
			p->interface();
			a.updateprofit();
		}
		else if(c=='2')
		{
			p=&a;
			p->interface();
			a.updateprofit();
		}
		else if(c=='3')
		{
			while(1)
			{
				agn:
					system("cls");
					
					int x;
	cout<<"\n _______________________________________________________________";
	cout<<"\n|                                                               |";
	cout<<"\n|                  VENDORS OPTION                               |"; 
	cout<<"\n|                  --------------                               |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|    PRESS :                                                    |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""1""- TO GO INTO  ELECTRONIC ITEM PANEL                   |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""2""- TO GO INTO  HARDWARE ITEM PANEL                     |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""3""- TO GO INTO  MOBILE ITEM PANEL                       |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""4""- TO GO INTO SPORTS ITEM PANEL                        |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|";
	cout<<"\n|                                                               |";
	cout<<"\n|                                                               |";
	cout<<"\n|        ""5""- TO GO BACK                                          |";
	cout<<"\n|                                                               |";
	cout<<"\n|_______________________________________________________________|\n";	
	
					
			cin>>x;
			
			switch(x)
			{
				case 1:
					vp=static_cast<vendors*>(new Vendors_Electronics);
					vp->interface();
					delete vp;
					break;
				case 2:
					vp=static_cast<vendors*>(new Vendors_Hardware);
					vp->interface();
					delete vp;
					break;
				case 3:
					vp=static_cast<vendors*>(new Vendors_Mobile);
					vp->interface();
					delete vp;
					break;
				case 4:
					vp=static_cast<vendors*>(new Vendors_sports);
					vp->interface();
					delete vp;
					break;
				case 5:
					goto h;
				default:
					goto agn;
			}
			a.updateprofit();
			}
		}
		else if(c=='4')
		{
			p=&a;
			p->updateprofit();
			
			system("cls");
			cout<<"\n\n";
			if(user::ifshop())
			{
			
			cout<<"\n\t _______________________________________________________________";
			cout<<"\n\t|                                                               |";
			cout<<"\n\t|               THANKS FOR SHOPPING....  :                      |";
			cout<<"\n\t|_______________________________________________________________|";
		    
			}
			
			cout<<"\n\t _______________________________________________________________";
			cout<<"\n\t|                                                               |";
			cout<<"\n\t|         ggggg                        bbbb                     |";
			cout<<"\n\t|        g     g             DDDD      B   B  y   y eeee        |";
			cout<<"\n\t|        g         oooo oooo D   D     B   B   y y  E           |";
			cout<<"\n\t|        g   ggg   0  0 0  0 D    D    bbbb     Y   Eeee        |";
			cout<<"\n\t|        g     g   0  0 0  0 D   D     B   B    Y   E           |";
			cout<<"\n\t|         gggggg   oooo oooo DDDD      Bbbbb    Y   Eeee        |";
			cout<<"\n\t|                                                               |";
			cout<<"\n\t|                                                               |";
			cout<<"\n\t|_______________________________________________________________|";
			delay(250);
			exit(0);
		}
	}
}
