#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include "client.h"

void initList(LLIST *pl)
{
	pl->head=NULL;
}

NODE* createNode(char name[25],char date[20], int r1 ,int r2 , int r3 , int movie_number,int price_row1, int price_row2,int price_row3)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->movie_number=movie_number;
	strcpy(newNode->name,name);
    strcpy(newNode->date,date);
    newNode->r1=r1;
    newNode->r2=r2;
    newNode->r3=r3;
    newNode->price_row1=price_row1;
    newNode->price_row2=price_row2;
    newNode->price_row3=price_row3;


	newNode->next=NULL;
	
	return newNode;
}

void bookTicket(LLIST *pl)
{

    if(pl->head != NULL){
    long long int mobile;
    char name1[15],name2[15];
    char interest;
    char ch,choice,no_of_ticket,row,cost_per_ticket;
    char movie_name[45];
    long int total_amount;
    printf("Do you want to watch any of these movies (yes/no) \n");
    scanf("%c",&interest);
    
        printf("Enter movie number :");
        scanf("%d",&choice);
        NODE *temp=pl->head;
        while((temp->movie_number != choice) && (temp->next!=NULL) )
        {
            temp=temp->next;
        }
        strcpy(movie_name,temp->name);
        
        
        
        printf("\n***Fill Details***");
        name:
            printf("\nEnter your name (First Name<space>Last Name):");
            scanf("%s %s",name1,name2);
            for(int i=0;i<strlen(name1);i++)
            {
                int j=name1[i];
                if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92))
                {
                    continue;
                }
                else
                {
                    printf("\nFirst name is invalid! Enter alphabets only!!!");
                    goto name;
                   }
            }
            for(int i=0;i<strlen(name2);i++)
            {
                int k=name2[i];
                if((k>=97 &&k <=122) || (k>=65 && k<=90) || (k==32 && k==92))
                {
                    continue;
                }
                else
                {
                    printf("\nLast name invalid! Enter alphabets only!!!");
                    goto name;
                }
            }  
            next:
                mobile=0;
                printf("\nEnter mobile number :");
                scanf("%lld",&mobile);
                if(mobile<=6000000000)
                {
                    printf("\nInvalid mobile number!!!\n");
                    goto next;
                }
                else if(mobile>9999999999)
                {
                    printf("\nInvalid mobile number!!!\n");
                    goto next;
                }
                else if(mobile>=6000000000 && mobile<=9999999999)
                {
                    goto seats;
                }
                seats:
                    printf("price for row1 %d \nprice for row2 %d \nprice for row3 %d \n",temp->price_row1 , temp->price_row2 , temp->price_row3);
                    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
                    printf("seats in row1 %d \nseats in row2 %d \nseats in row3 %d \nEnter row number:",temp->r1,temp->r2,temp->r3);
                    scanf("%d",&row);
                    printf("\nEnter number of tickets\n");
                    scanf("%d",&no_of_ticket);
                    if(row==1)
                        if(no_of_ticket > temp->r1 )
                        {
                            printf("Tickets unavailable \n");
                            printf("please select another row\n");
                            goto seats;
                        }
                        else
                        {
                            printf("Seats booked\n");
                            temp->r1=(temp->r1)-(no_of_ticket);
                            cost_per_ticket=temp->price_row1;
                            total_amount=(no_of_ticket) * (cost_per_ticket) ;
                            goto booking;
                        }
                    else if(row==2)
                    {
                        if(no_of_ticket > temp->r2 )
                        {
                            printf("Tickets unavailable \n");
                            printf("please select another row\n");
                            goto seats;
                        }
                        else
                        {
                            printf("Seats booked\n");
                            temp->r2=(temp->r2)-(no_of_ticket);
                            cost_per_ticket=temp->price_row2;
                            total_amount=no_of_ticket * cost_per_ticket;
                            goto booking;
                        }
                    }
                    else if(row==3)
                    {
                        if(no_of_ticket > temp->r3 )
                        {
                            printf("Tickets unavailable \n");
                            printf("please select another row\n");
                            goto seats;
                        }
                        else
                        {
                            printf("Seats booked\n");
                            temp->r3=(temp->r3)-(no_of_ticket);
                            cost_per_ticket=temp->price_row3;
                            total_amount=no_of_ticket * cost_per_ticket;
                            goto booking;
                        }
                    }
                    else
                    {
                        printf("\nWrong Choice!!!\n");
                        goto seats;
                    } 

                booking:
                {
                    
                    printf("\nTickets Booked successfully!!!\n*** ENJOY MOVIE ***\nGenerating Bill");
                    Sleep(750);
                    printf(".");
                    Sleep(750);
                    printf(".");
                    Sleep(750);
                    printf(".");
                    Sleep(750);
                    printf("\n\t\t*** Bill ***");
                    printf("\n========================================================");
                    printf("\n\t\tName : %s %s",name1,name2);
                    printf("\n\t\tMobile Number : %lld",mobile);
                    printf("\n\t\tMovie name : %s",movie_name);
                    if(row==1)
                    printf("\n\t\tRow : 1 to 4");
                    else if(row==2)
                    printf("\n\t\tRow : 5 to 8");
                    else if(row==3)
                    printf("\n\t\tRow : 9 to 12");
                    
                    printf("\n\t\tTotal seats : %d",no_of_ticket);
                    printf("\n\t\tCost per ticket : %d Rs.",cost_per_ticket);
                    printf("\n\t\tTotal Amount : %d Rs.",total_amount);
                    printf("\n========================================================");
                    printf("\n\nThank You! Visit again!!!\n\n");
                    Sleep(2000);
                    FILE *ufp;
                    ufp=fopen("OldTransaction.txt","a");
                    if(ufp == NULL)
                    {
                        printf("File not Found!");
                    }
                    else
                    {
                        fprintf(ufp,"%s %s %lld %d %d %d %s  \n",name1,name2,mobile,no_of_ticket,row,total_amount,movie_name);
                    }
                    printf("\n");
                    fclose(ufp);
                    
                }
    }
    else{
        printf("No movies available to book\n");
        printf("Come again!!!\n");
        exit(0);
    }
}

void addMovie(LLIST *pl)
{
    
    char temp2,ch;char password[]="vaish";
    char p[50];
    int want_to_add;
    
    login:
    {
        int l=0;
        printf("\nEnter Password:");
        while(1)
        {
            temp2=getch();
            if(temp2=='\r')
            {
                p[l]='\0';
                break;
            }
            else if(temp2=='\b')
            {
                if(l>0)
                {
                    l--;
                    printf("\b \b");
                }
            }
            else if(temp2=='\t'||temp2==' ')
            {
                continue;
            }
            else
            {
                p[l]=temp2;
                l++;
                printf("*");
            }
        }

        if(strcmp(p,password)==0)
        {
                system("cls");
                printf("\nPassword matched...\n");

                int movie_number;
                char name[25];
                char date[20];
                int r1,r2,r3; //number of seats
                int price_row1,price_row2,price_row3;

                do{
                    printf("Enter movie number\n");
                    scanf("%d",&movie_number);
                    fflush(stdin);

                    printf("Enter movie name (kindly use '_' for spaces) \n");
                    gets(name);
                    
                    printf("Enter date of release in dd/mm/yyyy format \n");
                    gets(date);
                    
                    printf("Enter number of seats in each row (row1,row2,row3 respectively) \n");
                    scanf("%d %d %d",&r1,&r2,&r3);
                    fflush(stdin);

                    printf("Enter price for seats in each row (row1,row2,row3 respectively) \n");
                    scanf("%d %d %d",&price_row1,&price_row2,&price_row3);
                    fflush(stdin);
                    //printf("here1\n");
                    NODE *newNode=createNode(name,date,r1,r2,r3,movie_number,price_row1,price_row2,price_row3);
                    //printf("here\n");
                
                    NODE *p=pl->head;
                    
                    //Empty List case
                    if(pl->head==NULL)
                    {
                        //printf("inside if\n");
                        pl->head=newNode; //Make head point to new Node
                        
                    }
                    else //One or more nodes
                    {
                        while(p->next!=NULL)
                            p=p->next;
                        //printf("inside else\n");
                        p->next=newNode;
                    }
                    printf("Do you want add one more movie Enter '1' to add or '0' to stop \n");
                    scanf("%d",&want_to_add);
                }while(want_to_add);
        }
        else 
        {
            printf("\nInvalid Password!!!\n");
            goto login;
        }
    }
}

void displayMovie(LLIST *pl)
{
    char cpymovie[50];
    printf("Displaying movies \n");
    NODE *temp=pl->head;
    if(pl->head==NULL)
    {
        //printf("No movies available today.Come again tomorrow");
        printf("list empty\n");
        
    }
    else
    {
        while(temp!=NULL)
        {
            strcpy(cpymovie,temp->name);
            printf("\n==========================================\n");
            printf("\n Movie Number : %d",temp->movie_number);
            printf("\n Movie name : %s",&cpymovie);
            printf("\n==========================================\n");
            temp=temp->next;
        }
        
    }
}

void deleteMovie(LLIST *pl,int pos)
{
    char temp2,ch;char password[]="vaish";
    char p[50];
    int want_to_delete=0;
    
    if(pl->head!=NULL){
    
    login:
    {   
        int l=0;
        printf("\nEnter Password:");
        while(1)
        {
            temp2=getch();
            if(temp2=='\r')
            {
                p[l]='\0';
                break;
            }
            else if(temp2=='\b')
            {
                if(l>0)
                {
                    l--;
                    printf("\b \b");
                }
            }
            else if(temp2=='\t'||temp2==' ')
            {
                continue;
            }
            else
            {
                p[l]=temp2;
                l++;
                printf("*");
            }
        }
        if(strcmp(p,password)==0)
            {
                do
                {
                    system("cls");
                    printf("\nPassword matched...\n");
                    NODE *q = NULL;
                    NODE *temp=pl->head;
                       
                    if(pos==0)
                    {
                        pl->head=pl->head->next;
                        free(temp);
                        //printf("here");
                    }
                    else
                    {
                        NODE *q=NULL,*p=pl->head;
                        for(int i=0;i<pos;i++)
                        {
                            q=p;
                            p=p->next;
                        }
                        q->next=p->next;
                        //printf("freeing in else\n");
                        free(p);
                        printf("deleted movie number %d\n",pos+1);
                        printf("\n=======================================================\n");

                    }
                    }while(want_to_delete);  
                } 
        else
            {
            printf("\nInvalid Password!!!\n");
            goto login;
            }
    }
    }
    else
    {
        printf("No movies available to delete\n");
    }
    
}

void oldTransactions()
{
    char temp2,ch,password[]="vaish",p[100];
    int l;
    FILE *fp;
    fp = fopen("OldTransaction.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    {
        system("cls");
        login:
        {
            l=0;
            printf("\nEnter Password:");
            while(1)
            {
                temp2=getch();
                if(temp2=='\r')
                {
                    p[l]='\0';
                break;
                }
                else if(temp2=='\b')
                {
                    if(l>0)
                    {
                        l--;
                        printf("\b \b");
                    }
                }
                else if(temp2=='\t'||temp2==' ')
                {
                 continue;
                }
                else
                {
                    p[l]=temp2;
                    l++;
                    printf("*");
                }
            }
            if(strcmp(p,password)==0)
            {
                system("cls");
                printf("\nPassword matched...\nFetching old transactions");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf("\n\n\t***Old Ticket Booking Records***");
                printf("\n=======================================================================");
                printf("\nName         Mobile Seats  Row   Bill    Movie          Price");
                printf("\n=======================================================================\n");
                while( ( ch = fgetc(fp))!=EOF)
                    printf("%c",ch);
                printf("=========================================================================\n\n");
                main();
            }
            else
            {
                printf("\nInvalid Password!!!");
                goto login;
            }
        }
    }
    fclose(fp);
}

void deleteTransactions()
{
    int l;
    FILE *fp;
    char temp2,password[]="vaish",p[100];
    login:
        {
            l=0;
            printf("\nEnter Password:");
            while(1)
            {
                temp2=getch();
                if(temp2=='\r')
                {
                    p[l]='\0';
                    break;
                }
                else if(temp2=='\b')
                {
                    if(l>0)
                    {
                        l--;
                        printf("\b \b");
                    }
                }
                else if(temp2=='\t'||temp2==' ')
                {
                    continue;
                }
                else
                {
                    p[l]=temp2;
                    l++;
                    printf("*");
                }
            }
        
            if(strcmp(p,password)==0)

            {
                printf("\nPassword matched...");
                fp = fopen("OldTransaction.txt","w");
                if(fp == NULL)
                {
                    printf("file not found!");
                    exit(1);
                }
                else
                {
                    printf("\nDeleting old transactions");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    fp=freopen(NULL,"w",fp);
                    printf("\nOld transactions Deleted Successfully!!!\n");
                    Sleep(2000);
                    main();
                }
            }
            else
            {
                printf("\nWrong password\n");
            goto login;
            }
        }
    fclose(fp);
}
