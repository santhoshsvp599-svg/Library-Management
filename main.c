#include "header.h"

struct Book books[MAX_BOOKS];
struct Issue issues[MAX_ISSUES];
int bookCount = 0, issueCount = 0, nextIssueId = 1;

int main(void)
{
    int choice;
    loadData();

    while (1) {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add New Book\n2. Update Book Details\n3. Remove Book\n");
        printf("4. Search Book\n5. View All Books\n6. Issue Book\n");
        printf("7. Return Book\n8. List Issued Books\n9. Save\n10. Exit\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addBook(); break;
            case 2: updateBook(); break;
            case 3: removeBook(); break;
            case 4: searchBook(); break;
            case 5: viewAllBooks(); break;
            case 6: issueBook(); break;
            case 7: returnBook(); break;
            case 8: listIssuedBooks(); break;
            case 9: saveData(); break;
            case 10:
                saveData();
                printf("Thank you!\n");
                return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
