#include "header.h"
#include <string.h>

void issueBook(void)
{
    int id, userId, index;
    struct Issue item;
    time_t now;

    if (issueCount >= MAX_ISSUES) { printf("Issue storage full.\n"); return; }
    id = readInt("Enter Book ID: ");
    index = findBookIndexById(id);
    if (index == -1) { printf("Book not found.\n"); return; }
    if (books[index].quantity <= 0) { printf("Book unavailable.\n"); return; }

    userId = readInt("Enter User ID: ");
    printf("Enter User Name: ");
    readLine(item.userName, sizeof(item.userName));
    if (userId <= 0 || !item.userName[0]) {
        printf("Invalid user details.\n"); return;
    }

    now = time(NULL);
    item.issueId = nextIssueId++;
    item.bookId = id;
    item.userId = userId;
    item.issueDate = now;
    item.dueDate = now + 7 * 24 * 60 * 60;
    item.returnDate = 0;
    item.fineAmount = 0;
    item.returned = 0;

    issues[issueCount++] = item;
    books[index].quantity--;
    printf("Book issued. Issue date: ");
    printDate(item.issueDate);
    printf("\nDue date: ");
    printDate(item.dueDate);
    printf("\n");
}

void returnBook(void)
{
    int id, userId, i, index, days;
    time_t now;
    double lateSeconds;

    id = readInt("Enter Book ID: ");
    userId = readInt("Enter User ID: ");

    for (i = 0; i < issueCount; i++) {
        if (issues[i].bookId == id && issues[i].userId == userId &&
            !issues[i].returned) {
            now = time(NULL);
            issues[i].returnDate = now;
            issues[i].returned = 1;
            lateSeconds = difftime(now, issues[i].dueDate);
            if (lateSeconds > 0) {
                days = (int)(lateSeconds / 86400);
                if (lateSeconds > days * 86400) days++;
                issues[i].fineAmount = days * FINE_PER_DAY;
            }
            index = findBookIndexById(id);
            if (index != -1) books[index].quantity++;
            printf("Book returned. Fine: Rs. %d\n", issues[i].fineAmount);
            return;
        }
    }
    printf("Active issue record not found.\n");
}

void listIssuedBooks(void)
{
    int i, index;
    if (issueCount == 0) { printf("No issue records.\n"); return; }
    for (i = 0; i < issueCount; i++) {
        index = findBookIndexById(issues[i].bookId);
        printf("\nIssue ID: %d | Book ID: %d | Title: %s\n",
               issues[i].issueId, issues[i].bookId,
               index == -1 ? "Deleted book" : books[index].title);
        printf("User ID: %d | User: %s\n", issues[i].userId, issues[i].userName);
        printf("Issue: "); printDate(issues[i].issueDate);
        printf(" | Due: "); printDate(issues[i].dueDate);
        printf(" | Return: "); printDate(issues[i].returnDate);
        printf("\nFine: Rs. %d | Status: %s\n", issues[i].fineAmount,
               issues[i].returned ? "Returned" : "Issued");
    }
}
