#include <stdio.h>
#include <time.h>
#define MAX_BOOKS 500
#define MAX_ISSUES 1000
#define BOOK_FILE "books.dat"
#define ISSUE_FILE "issued_books.dat"
#define FINE_PER_DAY 5

struct Book { int id; char title[100]; char author[100]; int quantity; };
struct Issue {
    int issueId, bookId, userId;
    char userName[100];
    time_t issueDate, dueDate, returnDate;
    int fineAmount, returned;
};

extern struct Book books[MAX_BOOKS];
extern struct Issue issues[MAX_ISSUES];
extern int bookCount, issueCount, nextIssueId;

void readLine(char text[], int size);
int readInt(char message[]);
int findBookIndexById(int id);
int containsText(char text[], char search[]);
void printDate(time_t date);

void addBook(void);
void updateBook(void);
void removeBook(void);
void searchBook(void);
void viewAllBooks(void);
void issueBook(void);
void returnBook(void);
void listIssuedBooks(void);
void saveData(void);
void loadData(void);
