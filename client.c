#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include "client.h"
void main()
{
    LLIST lobj;
    int choice ,n ,pos;
    initList(&lobj);
    do
    {
        printf("\n||=======================================================================||");
        printf("\n||                                                                       ||");
        printf("\n||                Welcome to Moive Ticket Booking System                 ||");
        printf("\n||                                                                       ||");
        printf("\n||=======================================================================||");
        printf("\n||          Press [1] To Book Tickets                                    ||");
        printf("\n||-----------------------------------------------------------------------||");
        printf("\n||          Press [2] Displaying Movie list                              ||");
        printf("\n||-----------------------------------------------------------------------||");
        printf("\n||          Press [3] To Add New Movie (Admin Only)                      ||");
        printf("\n||-----------------------------------------------------------------------||");
        printf("\n||          Press [4] To Delete Movie (Admin Only)                       ||");
        printf("\n||-----------------------------------------------------------------------||");
        printf("\n||          Press [5] To View All Transactions (Admin Only)              ||");
        printf("\n||-----------------------------------------------------------------------||");
        printf("\n||          Press [6] To Delete All Transactions (Admin Only)            ||");
        printf("\n||-----------------------------------------------------------------------||");
        printf("\n||          Press [7] To Exit                                            ||");
        printf("\n||=======================================================================||");
        printf("\n||          Please Enter Your Choice::                                   ||");
        printf("\n||=======================================================================||\n\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1 :
                //displayMovie(&lobj);
                bookTicket(&lobj);
                break;
            case 2:
                displayMovie(&lobj);
                break;
            case 3:
                addMovie(&lobj);
                break;
            case 4:
                //delete movie
                
                printf("Enter movie Number to be deleted \n");
                scanf("%d",&n);
                pos=n-1;
                deleteMovie(&lobj,pos);
                
                
                break;
            case 5:
                oldTransactions();
                break;
            case 6:
                deleteTransactions();
                break;
            case 7:
                printf("\n*** Thank You! Visit Again!!! ***\n\n");
                exit(0);
            default:
                printf("\nWrong choice!!!\nTry Again!!!");
                break;
        }
    }
    while(choice!=7);
}