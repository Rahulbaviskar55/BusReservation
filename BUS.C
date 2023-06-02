#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
//Developed By:-
//Alodaini Abdulrahman Roll No 1
//Rahul Baviskar Roll No 7
//Vedang Bhange Roll No 8
//Umesh Gaikwad Roll No 17
//Akash Hedau Roll No 23

void red()
{
	printf("\033[1;36m");
}
char ch[10][130]={"Vishwakarma Travels Bus1","Vishwakarma Travels Bus2","Vishwakarma Travels Bus3","Vishwakarma Travels Bus4","Vishwakarma Travels Bus5"};
char name[32][100]={'\0'};
char number[32][8]={'\0'};
int num1[32]={0};
int busno;
int flag1=0;
int temp=0;
void bus();//for getting list of buses
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
int read_number(int busno);//for reading the number from the file
void read_name(int busno);//for reading the name from the file
void status();//for printing the status of the buses
void status_1(int busno);//for printing the status while booking ticket
void cancel();//For Cancelling Ticket
void ticket();//For Printing Ticket
void login();//Login Form

int main()
{
	int num,i;
	red();
	login();
	//Main Menu Display..
	do
	{
	system("cls");
	printf("\n\n\n");
	printf("\n\n\t\t************************************************************");
	printf("\n\t\t*                                                          *");
	printf("\n\t\t*                                                          *");
	printf("\n\t\t*                VISHWAKARMA TRAVELS                       *");
	printf("\n\t\t*               E-Booking Service                          *");
	printf("\n\t\t*                                                          *");
	printf("\n\t\t************************************************************");
	printf("\n\n\t\t\t\t[1]=> To View Bus List..\n");
        printf("\n");
        printf("\t\t\t\t[2]=> To Book Tickets..\n");
        printf("\n");
        printf("\t\t\t\t[3]=> To Cancel Booking..\n");
        printf("\n");
        printf("\t\t\t\t[4]=> To Check Available Seats In Buses..\n");
        printf("\n");
	printf("\t\t\t\t[5]=> To View Booked Ticket..\n");
        printf("\n");
        printf("\t\t\t\t[6]=> Exit..!!\n\n");
        printf("\t======================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d",&num);
        switch(num)
    	{
    		case 1:
        		bus();//for list of bus
        		break;
   		case 2:
        		booking();//for booking the tickets
        		break;
    		case 3:
        		cancel();
        		break;
    		case 4:
        		status();
        		break;
		case 5:
			ticket();
			break;
		case 6:
			clrscr();
			printf("\n\n\n\n\n\n");
			printf("\n\n\t\t************************************************************");
			printf("\n\t\t*                                                          *");
			printf("\n\t\t*                                                          *");
			printf("\n\t\t*                THANK YOU..!!!                            *");
			printf("\n\t\t*                                                          *");		
			printf("\n\t\t*                Stay Safe..!!!                            *");
			printf("\n\t\t*                                                          *");
			printf("\n\t\t************************************************************");
			break;
		default:
			printf("\nInvalid Choice\n");
			break;
	}
	getch();
    	}while(num != 6);
    	
    	
    	return 0;
}


void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================== BUS RESERVATION SYSTEM ============================\n\n\n");
    printf("\n\t[1]  =>  %s  => From Nandurbar To Pune => Rs.700\n",ch[0]);
    printf("\n");
    printf("\t[2]  =>  %s  => From Dhule To Mumbai => Rs.600\n",ch[1]);
    printf("\n");
    printf("\t[3]  =>  %s  => From Pune To Nandurbar => Rs.700\n",ch[2]);
    printf("\n");
    printf("\t[4]  =>  %s  => From Mumbai To Dhule => Rs.600\n",ch[3]);
    printf("\n");
    printf("\t[5]  =>  %s  => From Dhule To Pune => Rs.500\n",ch[4]);
    printf("\n\n==============================================================================\n\n\n");
}

void booking()
{
	int i=0,seat1;
	char numstr[100];
	FILE *f1, *fopen();//for reading the seats from the user.
	char str1[80]="32",str2[4],str3[4];
	int seat2,booking=0;
	label:
	system("cls");
	printf("=============================== BUS RESERVATION SYSTEM ======================\n\n\n");//for entering Bus number
	bus();//for seeing Bus least
	printf("Enter the Bus number:--->");
	scanf("%d",&busno);
	if(busno == 1 || busno == 2 || busno == 3 || busno == 4 || busno == 5)
	{
	even:
		printf("================================ BUS RESERVATION SYSTEM ===================\n\n\n");//for selecting coach
		printf("Your Bus Number is %d ********** %s",busno,ch[busno-1]);
		status_1(busno);
		if(busno == 1)
		{
			f1 = fopen("tr1.txt","r+");
			fgets(str1,80,f1);
 			fclose(f1);
		}
		else if(busno == 2)
		{
			f1 = fopen("tr2.txt","r+");
			fgets(str1,80,f1);
			fclose(f1);
		}
		else if(busno == 3)
		{
			f1 = fopen("tr3.txt","r+");
			fgets(str1,80,f1);
			fclose(f1);
		}
		else if(busno == 4)
		{
			f1 = fopen("tr4.txt","r+");
			fgets(str1,80,f1);
			fclose(f1);
		}
		else if(busno == 5)
		{
			f1 = fopen("tr5.txt","r+");
 			fgets(str1,80,f1);
			fclose(f1);
		}
		seat1=atoi(str1);//covert the string into number

		if(temp == 1)		
			seat1 = seat1 + 1;
		if(seat1 == 0)
		{
			printf("\n\n\tThere is no blank seat in this bus ");
		}
		else
		{
			printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
			printf("\n\n\t\t\t\tEnter Number of Tickets:-----> ");
			scanf("%d",&booking);
			if(booking == 0)
			{
				flag1=0;
			}
			printf("\n");
			if(booking>32 || booking>seat1)
			{
				printf("\n%d Seats Are Not Available In The Bus\n",booking);
				printf("Enter Again..!!\n");
				goto even;
			}
			seat1=seat1-booking;
			itoa(busno,numstr,10);
			name_number(booking,numstr);
			if(flag1==1)
			{
				if(busno==1 || busno==3)
				{
					printf("\n\t\t\t\tThe Total booking amount is %d",700*booking);
				}
				else if(busno==2 || busno==4)
				{
					printf("\n\t\t\t\tThe Total booking amount is %d",600*booking);
				}
				else if(busno==5)
				{
					printf("\n\t\t\t\tThe Total booking amount is %d",500*booking);
				}
			}
			itoa(seat1, str1, 10);
			//for reading the seats from the user.
			if(busno == 1)
			{
				f1 = fopen("tr1.txt","w");
 				fputs(str1,f1);
 				fclose(f1);
			}
			else if(busno == 2)
			{
				f1 = fopen("tr2.txt","w");
				fputs(str1,f1);
				fclose(f1);
			}
			else if(busno == 3)
			{
				f1 = fopen("tr3.txt","w");
				fputs(str1,f1);
				fclose(f1);
			}
			else if(busno == 4)
			{
				f1 = fopen("tr4.txt","w");
				fputs(str1,f1);
				fclose(f1);
			}
			else if(busno == 5)
			{
				f1 = fopen("tr5.txt","w");
				fputs(str1,f1);
				fclose(f1);
			}
		}
	}
	else
	{
		printf("\nWe Are Having 5 Buses Only..\n");
		printf("\nEnter Valid Bus Number Again..!!\n");
		goto label;
	}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
 char tempname[33][100]={"Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available "};
int index=0,j;
int temp[33]={0};
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//for open the file to write the name in the file
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file
  j=read_number(busno);
    read_name(busno);
    
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }

for(i=0; i<booking; i++)//for entering the person name and seat number in the file
{
    temp[0+number]=number;	
    printf("======================Enter the details for ticket no %d======================\n\n\n",i+1);    
      label1:
      printf("\t\t\t\tEnter the seat number:--->");
      scanf("%d",&number);
      if(temp[0+number]==number)
      	goto odd;
      if(number<=32)
      {
	if(strcmp(tempname[number],"Available ")==0)
	{
        flag1=1;
        printf("\t\t\t\tEnter the name of person:--->");
        scanf("%s",name[number-1]);
        printf("\n==============================================================================\n\n");
        printf("\n");
        itoa(number, tempstr, 10);
        fprintf(a,"%s ",name[number-1]);
        fprintf(b,"%s ",tempstr);
	}
	else
	{
  	  odd:
	  printf("\nThe Seat is Already Booked..\n");
	  printf("Enter Seat Number Again..!!\n");
	  goto label1;
	}
      }
      else
      {
        printf("\nBus is Having Only 32 Seats..\n");
        printf("Enter Seat Number Again..!!\n");
	goto label1;
      }
}
fclose(a);
fclose(b);
}



int read_number(int busno)//for putting the numeric value in the array
{
char tempstr[100],tempstr2[12]="number";
FILE *a;
char numstr[100];
int i=0,j=0,k;
itoa(busno,numstr,10);//For Converting int to string..
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the number in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int busno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(busno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
  int i,busno,index=0,j;
  char tempname[33][100]={"Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available "};
  system("cls");
printf("====================== BUS RESERVATION SYSTEM =========================\n\n\n");
  
    printf("Enter the number of bus:---->");
    scanf("%d",&busno);
    system("cls");
    if(busno<=5 && busno!=0)
    {
    j=read_number(busno);
    read_name(busno);
    system("cls");
    printf("________________________________________________________________________________\n");
    printf("                     Bus.no-->%d---->%s                                                            \n",busno,ch[busno-1]);
    printf("________________________________________________________________________________\n");
  
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
    }
    else
    {
      printf("\nEnter Valid Bus Number");
    }  
}


void status_1(int busno)
{
	char tempname[33][100]={"Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available "};
	int i,index=0,j;
	printf("Your Bus Number is %d ********** %s",busno,ch[busno-1]);
	system("cls");
	printf("=================== BUS RESERVATION SYSTEM ====================\n\n\n");
   
	j=read_number(busno);
	read_name(busno);
    
	for(i=0; i<j; i++)
	{
        	strcpy(tempname[num1[i]],name[i]);
   	}
    	for(i=0; i<8; i++)
    	{
        	printf("\t");
        	for(j=0; j<4; j++)
            	{
        	printf("%d.%s\t",index+1,tempname[index+1]);
        	index++;
            	}
            	printf("\n");
	}
}


void cancel()
{
	int seat_no,i,j;
	char tempname[33][100]={"Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available "};
	char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
	int t=1;
	FILE *a,*b;
	label2:
	printf("\nEnter the bus number:---->");
	scanf("%d",&busno);
	if(busno == 1 || busno == 2 || busno == 3 || busno == 4 || busno == 5)
	{
		itoa(busno,numstr,10);
		strcat(numstr,".txt");
		strcat(tempstr1,numstr);
		strcat(tempstr2,numstr);
		read_number(busno);
		read_name(busno);
		status_1(busno);
		label1:
		printf("\nEnter the seat number:--->");
		scanf("%d",&seat_no);
		if(seat_no>32 || seat_no==0)
		{
			goto label1;
		}
		temp=t;
		j=read_number(busno);
		read_name(busno);
    
		for(i=0; i<j; i++)
		{
        		strcpy(tempname[num1[i]],name[i]);
   		}
		if(strcmp(tempname[seat_no],"Available ")==0)
		{
			printf("\nNo Such Ticket is Booked\n");
			goto label1;
		}
		a = fopen(tempstr1,"w+");
		b = fopen(tempstr2,"w+");
		for(i=0; i<32; i++)
		{
			flag1=1;
     			if(num1[i] == seat_no)
			{
				for(j=0; j<32; j++)
         			{
					if(num1[j] != seat_no && num1[j] != 0)
             				{
                 				fprintf(b,"%d ",num1[j]);
                 				fprintf(a,"%s",name[j]);
             				}
             				else if(num1[j] == seat_no && num1[j] != 0)
             				{
                 				strcpy(name[j],"Available ");
             				}
         			}
     			}
 		}
	}
	else
	{
		printf("\nWe Are Having 5 Buses Only\n");
		goto label2;
	}
 	fclose(a);
	fclose(b);
	printf("\n\n");
	printf("======================================================================\n");
	printf("\t\t\tYour Ticket Has Been Cancelled..\t\t\t\n");
	printf("======================================================================\n");
	printf("\n\n\t\tThank You..!!!");
}

void ticket()
{
	int i,j,seat_no; 
	char tempname[33][100]={"Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available ","Available "};
	char name1[15];
	label1:
	printf("\n\tEnter Booked Bus Number->>> ");
	scanf("%d",&busno);
	if(busno>5 || busno==0)
	{
		printf("\nWe Are Having 5 Buses Only");
		goto label1;
	}
	j=read_number(busno);
	read_name(busno);
    
	for(i=0; i<j; i++)
	{
        	strcpy(tempname[num1[i]],name[i]);
   	}
	label2:
	printf("\n\tEnter Your Seat Number->>> ");
	scanf("%d",&seat_no);
	if(seat_no>32 || seat_no==0)
	{
		printf("\n\Enter Valid Seat Number");
		goto label2;
	}
	if(strcmp(tempname[seat_no],"Available ")==0)
	{
		printf("\nNo Such Ticket is Booked\n");
		goto label1;
	}
	if(busno==1)
	{
			clrscr();
			printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			printf("\n\t\t 	  		E-Ticket      					    ");
			printf("\n\t\t           Vishwakarma Travels Bus No. 1                      ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t  Name-> %s 		 Seat Number-> %d",tempname[seat_no],seat_no);
			printf("\n\t\t                                                            ");
			printf("\n\t\t From-> Nandurbar          	To-> Pune                  ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t Driver Name: Suresh		Contact:9775635442          ");
			printf("\n\t\t 		             		         ");		
			printf("\n\t\t          Bus No: MH 39 BC 7691       		        ");
			printf("\n\t\t 		             		         ");
			printf("\n\t\t Total Fare->> Rs.700 Only..				  ");
			printf("\n\t\t                 	Happy Journey                            ");
			printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	if(busno==2)
	{
			clrscr();
			printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			printf("\n\t\t 	  		E-Ticket      					    ");
			printf("\n\t\t           Vishwakarma Travels Bus No. 2                      ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t  Name-> %s 		 Seat Number-> %d",tempname[seat_no],seat_no);
			printf("\n\t\t                                                            ");
			printf("\n\t\t From-> Dhule          	To-> Mumbai                  ");	
			printf("\n\t\t               		                                 ");
			printf("\n\t\t Driver Name: Ramesh		Contact: 9866574588       ");	
			printf("\n\t\t                  		       ");
			printf("\n\t\t    		 Bus No: MH 39 AV 8884              ");
			printf("\n\t\t                		                          ");
			printf("\n\t\t Total Fare->> Rs.600 Only..				  ");
			printf("\n\t\t                		                        ");
			printf("\n\t\t                 	Happy Journey                  ");
			printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	if(busno==3)
	{
		
			clrscr();
			printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			printf("\n\t\t 	  		E-Ticket      					    ");
			printf("\n\t\t           Vishwakarma Travels Bus No. 3                       ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t  Name-> %s 		 Seat Number-> %d",tempname[seat_no],seat_no);
			printf("\n\t\t                                                            ");
			printf("\n\t\t From-> Pune          	To-> Nandurbar                ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t Driver Name: Dinesh		Contact: 9881654399           ");		
			printf("\n\t\t                		                                 ");
			printf("\n\t\t            	Bus No: MH 39 AV 9881	                     ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t Total Fare->> Rs.700 Only..				  ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t                 	Happy Journey                            ");
			printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	if(busno==4)
	{
			clrscr();
			printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			printf("\n\t\t 	  		E-Ticket      					    ");
			printf("\n\t\t           Vishwakarma Travels Bus No. 4                      ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t  Name-> %s 		 Seat Number-> %d",tempname[seat_no],seat_no);
			printf("\n\t\t                                                            ");
			printf("\n\t\t From-> Mumbai          	To-> Dhule	             ");	
			printf("\n\t\t                		                                 ");
			printf("\n\t\t Driver Name: Mukesh		Contact: 7685762278              ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t     		Bus No: MH 39 BC 9042           		  ");	
			printf("\n\t\t                		                                 ");
			printf("\n\t\t Total Fare->> Rs.600 Only..				  ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t                 	Happy Journey                            ");
			printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	if(busno==5)
	{
		clrscr();
			printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			printf("\n\t\t 	  		E-Ticket      					    ");
			printf("\n\t\t           Vishwakarma Travels Bus No. 5                     ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t  Name-> %s 		 Seat Number-> %d",tempname[seat_no],seat_no);
			printf("\n\t\t                                                            ");
			printf("\n\t\t From-> Dhule          	To-> Pune                   ");	
			printf("\n\t\t                		                                 ");
			printf("\n\t\t Driver Name: Durwesh		Contact: 7786645495            ");
			printf("\n\t\t       		         		                           ");
			printf("\n\t\t                Bus No: MH 39 AV 7795		               ");
			printf("\n\t\t                		                           ");
			printf("\n\t\t Total Fare->> Rs.500 Only..				  ");
			printf("\n\t\t                		                                 ");
			printf("\n\t\t                 	Happy Journey                            ");
			printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}	
}

	
void login()
{
	char uname[50],pwd[20];
	int i;
	clrscr();
	printf("\n\t==================LOGIN FORM VISHWAKARMA TRAVELS========================");
	printf("\n\n\n\t\t\t Enter User Name->>>>>>>>> ");
	scanf("%s",&uname);
	printf("\n\n\t\t\t Enter Password->>>>>>> ");
	scanf("%s",&pwd);
	if(strcmp(uname,"vishwakarma")==0 && strcmp(pwd,"12345")==0)
	{
	clrscr();
	printf("\n\n\n\n\n");
	printf("\n\n\t\t************************************************************");

	printf("\n\n\n\t\t        Welcome To Vishwakarma Travels E-Booking Service...             ");

	printf("\n\n\n\t\t************************************************************");
	printf("\n\n\n\n\n\tPress Any Key To Continue...");
	}
	else
	{
	printf("\n\n\t\t\t SORRY..!!! You Have Entered Wrong Credentials");
	getch();
	exit(0);
	}
	getch();
}
	