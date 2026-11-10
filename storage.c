#include "header.h"

void saveData(void)
{
    FILE *fp;
    fp = fopen(BOOK_FILE, "wb");
    if (fp == NULL) { printf("Cannot save books file.\n"); return; }
    fwrite(&bookCount, sizeof(int), 1, fp);
    fwrite(books, sizeof(struct Book), bookCount, fp);
    fclose(fp);

    fp = fopen(ISSUE_FILE, "wb");
    if (fp == NULL) { printf("Cannot save issue file.\n"); return; }
    fwrite(&issueCount, sizeof(int), 1, fp);
    fwrite(&nextIssueId, sizeof(int), 1, fp);
    fwrite(issues, sizeof(struct Issue), issueCount, fp);
    fclose(fp);
    printf("Data saved successfully.\n");
}

void loadData(void)
{
    FILE *fp;
    size_t count;

    fp = fopen(BOOK_FILE, "rb");
    if (fp != NULL) {
        if (fread(&bookCount, sizeof(int), 1, fp) != 1 ||
            bookCount < 0 || bookCount > MAX_BOOKS) bookCount = 0;
        else {
            count = fread(books, sizeof(struct Book), bookCount, fp);
            if (count != (size_t)bookCount) bookCount = 0;
        }
        fclose(fp);
    }

    fp = fopen(ISSUE_FILE, "rb");
    if (fp != NULL) {
        if (fread(&issueCount, sizeof(int), 1, fp) != 1 ||
            issueCount < 0 || issueCount > MAX_ISSUES) issueCount = 0;
        else {
            if (fread(&nextIssueId, sizeof(int), 1, fp) != 1)
                nextIssueId = 1;
            count = fread(issues, sizeof(struct Issue), issueCount, fp);
            if (count != (size_t)issueCount) {
                issueCount = 0;
                nextIssueId = 1;
            }
        }
        fclose(fp);
    }
}
