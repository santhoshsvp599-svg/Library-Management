#include "header.h"
#include <string.h>
#include <ctype.h>

void readLine(char text[], int size)
{
    if (fgets(text, size, stdin) != NULL)
        text[strcspn(text, "\n")] = '\0';
}

int readInt(char message[])
{
    char line[100];
    int value;
    while (1) {
        printf("%s", message);
        readLine(line, sizeof(line));
        if (sscanf(line, "%d", &value) == 1) return value;
        printf("Enter a valid number.\n");
    }
}

int findBookIndexById(int id)
{
    int i;
    for (i = 0; i < bookCount; i++)
        if (books[i].id == id) return i;
    return -1;
}

int containsText(char text[], char search[])
{
    char a[200], b[200];
    int i;
    strcpy(a, text);
    strcpy(b, search);
    for (i = 0; a[i]; i++) a[i] = (char)tolower((unsigned char)a[i]);
    for (i = 0; b[i]; i++) b[i] = (char)tolower((unsigned char)b[i]);
    return strstr(a, b) != NULL;
}

void printDate(time_t date)
{
    struct tm *info;
    char buffer[30];
    if (date == 0) { printf("Not returned"); return; }
    info = localtime(&date);
    if (info == NULL) { printf("Invalid date"); return; }
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", info);
    printf("%s", buffer);
}
