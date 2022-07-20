typedef struct book
{
    int movie_number;
    char name[25];
    char date[20];
    int r1,r2,r3;
    int price_row1,price_row2,price_row3;
    struct book *next;
}NODE;

typedef struct llist
{
	NODE *head;
}LLIST;

void initList(LLIST *pl);//initialize linked list   
void bookTicket(LLIST *pl); //for booking tickets   
void displayMovie(LLIST *pl); // for view now playing movie  
void addMovie(LLIST *pl); //for inserting new movie  
void deleteMovie(LLIST *pl , int pos);//for deleting movies 
void oldTransactions(); //for viewing old records of booked tickets  
void deleteTransactions(); //for deleting all transactions