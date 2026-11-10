# Library Management System

A command-line library management program written in C. It lets you maintain a book catalog and track books issued to users.

## Features

- Add, update, remove, search, and list books
- Issue books to users and record issue and due dates
- Return books and calculate late fines
- View active and returned issue records
- Save and load book and issue data between runs

## Requirements

- GCC (or another C compiler that supports C11)

## Build and run

From the project directory, compile the source files:

```sh
gcc -Wall -Wextra -std=c11 main.c book.c issues.c storage.c library.c -o library_management
```

Run the program:

```sh
./library_management
```

On Windows, you can name the output with an `.exe` extension and run it from PowerShell:

```powershell
gcc -Wall -Wextra -std=c11 main.c book.c issues.c storage.c library.c -o library_management.exe
.\library_management.exe
```

## Using the program

Choose an option from the menu to manage books or issue records. Select **Save** to save manually; the program also saves data when you choose **Exit**.

Issued books are due after 7 days. Late returns are charged Rs. 5 per day.

## Data files

The program creates these files in its current working directory:

- `books.dat` - saved book catalog
- `issued_books.dat` - saved issue and return records
