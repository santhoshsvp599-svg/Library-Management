#include "header.h"
#include <string.h>

static void displayBook(struct Book b)
{
    printf("%-8d %-25s %-25s %-8d\n", b.id, b.title, b.author, b.quantity);
}

void viewAllBooks(void)
{
    int i;
    if (bookCount == 0) { printf("No books available.\n"); return; }
    printf("\n%-8s %-25s %-25s %-8s\n", "ID", "Title", "Author", "Quantity");
    for (i = 0; i < bookCount; i++) displayBook(books[i]);
}

void addBook(void)
{
    struct Book b;
    if (bookCount >= MAX_BOOKS) { printf("Book storage full.\n"); return; }
    b.id = readInt("Enter Book ID: ");
    if (b.id <= 0 || findBookIndexById(b.id) != -1) {
        printf("Invalid or duplicate ID.\n"); return;
    }
    printf("Enter Book Title: "); readLine(b.title, sizeof(b.title));
    printf("Enter Author Name: "); readLine(b.author, sizeof(b.author));
    b.quantity = readInt("Enter Quantity: ");
    if (!b.title[0] || !b.author[0] || b.quantity < 0) {
        printf("Invalid details.\n"); return;
    }
    books[bookCount++] = b;
    printf("Book added successfully.\n");
}

void updateBook(void)
{
    int ch, id, i, index = -1, qty;
    char name[100];
    printf("1. By Book ID\n2. By Book Name\n3. Back\n");
    ch = readInt("Choice: ");
    if (ch == 1) {
        id = readInt("Book ID: ");
        index = findBookIndexById(id);
    } else if (ch == 2) {
        printf("Book name: "); readLine(name, sizeof(name));
        for (i = 0; i < bookCount; i++)
            if (containsText(books[i].title, name)) { index = i; break; }
    } else return;

    if (index == -1) { printf("Book not found.\n"); return; }
    printf("New title: "); readLine(books[index].title, sizeof(books[index].title));
    printf("New author: "); readLine(books[index].author, sizeof(books[index].author));
    qty = readInt("New quantity: ");
    if (qty < 0) { printf("Quantity cannot be negative.\n"); return; }
    books[index].quantity = qty;
    printf("Book updated.\n");
}

void removeBook(void)
{
    int ch, id, i, index = -1;
    char name[100];
    printf("1. By Book ID\n2. By Book Name\n3. Back\n");
    ch = readInt("Choice: ");
    if (ch == 1) {
        id = readInt("Book ID: ");
        index = findBookIndexById(id);
    } else if (ch == 2) {
        printf("Book name: "); readLine(name, sizeof(name));
        for (i = 0; i < bookCount; i++)
            if (containsText(books[i].title, name)) { index = i; break; }
    } else return;

    if (index == -1) { printf("Book not found.\n"); return; }
    for (i = 0; i < issueCount; i++)
        if (issues[i].bookId == books[index].id && !issues[i].returned) {
            printf("Book is currently issued; cannot remove it.\n"); return;
        }
    for (i = index; i < bookCount - 1; i++) books[i] = books[i + 1];
    bookCount--;
    printf("Book removed.\n");
}

void searchBook(void)
{
    int ch, id, i, index, found = 0;
    char key[100];
    printf("1. By ID\n2. By Book Name\n3. By Author\n4. Back\n");
    ch = readInt("Choice: ");
    if (ch == 1) {
        id = readInt("Book ID: ");
        index = findBookIndexById(id);
        if (index >= 0) displayBook(books[index]);
        else printf("Book not found.\n");
        return;
    }
    if (ch != 2 && ch != 3) return;
    printf("Search text: "); readLine(key, sizeof(key));
    for (i = 0; i < bookCount; i++) {
        if ((ch == 2 && containsText(books[i].title, key)) ||
            (ch == 3 && containsText(books[i].author, key))) {
            displayBook(books[i]); found = 1;
        }
    }
    if (!found) printf("No matching book found.\n");
}
