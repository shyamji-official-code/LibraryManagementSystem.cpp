# Library Management System

A simple **C++ console-based Library Management System** built using **Object-Oriented Programming (OOP)** concepts and the C++ Standard Library.

The application provides a menu-driven interface for managing books and library members. Users can add books, search for books by exact title or author, issue and return books, and add members.

## Features

- Add a new book
- Search for a book by exact title or author
- Issue a book using its Book ID
- Return an issued book
- Check whether a book is available or already issued
- Add library members
- Menu-driven console interface
- Uses C++ classes and objects
- Uses `vector` to store books and members in memory

## Technologies Used

- **Language:** C++
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Standard Library:** `iostream`, `vector`
- **Data Storage:** In-memory storage using `vector`
- **Interface:** Console / Command Line

## Project Structure

```text
LibraryManagementSystem/
│
├── LibraryManagementSystem.cpp
└── README.md
```

## Classes Used

### 1. `Book`

The `Book` class represents a book in the library.

It stores:

- `id` — unique book ID
- `title` — title of the book
- `author` — name of the author
- `isIssued` — indicates whether the book is currently issued

When a new `Book` object is created, `isIssued` is initialized to `false`, meaning the book is available.

### 2. `Member`

The `Member` class represents a library member.

It stores:

- `memberId` — member ID
- `name` — member's name

### 3. `Library`

The `Library` class manages the books and members using two vectors:

```cpp
vector<Book> books;
vector<Member> members;
```

It provides the following operations:

- `addBook()`
- `searchBook()`
- `issueBook()`
- `returnBook()`
- `addMember()`

## Menu Options

When the program runs, the following menu is displayed:

```text
--- Library Menu ---
1. Add Book
2. Search Book
3. Issue Book
4. Return Book
5. Add Member
6. Exit
```

## How the System Works

### Add Book

The user enters:

- Book ID
- Book title
- Author name

The book is added to the library collection and is initially marked as **available**.

### Search Book

The user can enter a title or author name. The program checks the stored books and displays the matching book along with its status:

```text
Found: Book Title by Author Name [Available]
```

or

```text
Found: Book Title by Author Name [Issued]
```

The current implementation performs an **exact match** against the complete title or author string.

### Issue Book

The user enters a Book ID.

- If the book exists and is available, it is marked as issued.
- If the book is already issued, the program displays an appropriate message.
- If the Book ID does not exist, the program displays `Book Not Found!`.

### Return Book

The user enters a Book ID.

- If the book is currently issued, its status is changed back to available.
- If the book was not issued, the program displays `Book was not issued!`.
- If the Book ID does not exist, the program displays `Book Not Found!`.

### Add Member

The user enters:

- Member ID
- Member name

The member is then stored in the library's member collection.

## How to Compile and Run

### Using g++

Compile the program:

```bash
g++ LibraryManagementSystem.cpp -o LibraryManagementSystem
```

Run on Windows:

```bash
LibraryManagementSystem.exe
```

Run on Linux/macOS:

```bash
./LibraryManagementSystem
```

### Using VS Code

1. Install a C++ compiler such as **MinGW** on Windows or **G++** on Linux.
2. Open the project folder in VS Code.
3. Open the integrated terminal.
4. Compile the program:

```bash
g++ LibraryManagementSystem.cpp -o LibraryManagementSystem
```

5. Run the generated executable.

## Example

```text
--- Library Menu ---
1. Add Book
2. Search Book
3. Issue Book
4. Return Book
5. Add Member
6. Exit

Enter choice: 1
Enter Book ID: 101
Enter Title: C++ Programming
Enter Author: Bjarne Stroustrup
Book Added Successfully!

Enter choice: 2
Enter Title or Author: C++ Programming
Found: C++ Programming by Bjarne Stroustrup [Available]

Enter choice: 3
Enter Book ID: 101
Book Issued Successfully!

Enter choice: 2
Enter Title or Author: C++ Programming
Found: C++ Programming by Bjarne Stroustrup [Issued]
```

## OOP Concepts Demonstrated

### Classes and Objects

The project defines three classes:

- `Book`
- `Member`
- `Library`

Objects of these classes are created and managed during program execution.

### Encapsulation

The `Library` class keeps its book and member collections private:

```cpp
private:
    vector<Book> books;
    vector<Member> members;
```

Operations are performed through public member functions.

### Constructors

The `Book` and `Member` classes use constructors to initialize their data members.

### Abstraction

Library operations such as adding, searching, issuing, and returning books are implemented as methods of the `Library` class, keeping the main program focused on menu handling.

## Data Storage

This version of the application stores all books and members **only in memory using `vector`**.

As a result:

- Data is available while the program is running.
- Data is lost when the program exits.
- No database or file-based persistence is currently implemented.

## Current Limitations

- No permanent file or database storage
- Member records are stored but are not connected to specific book issues
- No book deletion functionality
- No member deletion functionality
- No display-all-books option
- No display-all-members option
- Search uses exact title or author matching
- No due dates or fine calculation
- No authentication or login system

## Possible Future Improvements

- Add file handling or a database for persistent storage
- Link issued books with specific members
- Record issue and return dates
- Add due dates and late-fine calculation
- Add update and delete operations
- Display all books and members
- Support partial or case-insensitive searching
- Prevent duplicate Book IDs and Member IDs
- Add a graphical user interface (GUI)
- Add login and user authentication

## Author

**Devarshi Gautam**

## License

This project is intended for educational and learning purposes.
