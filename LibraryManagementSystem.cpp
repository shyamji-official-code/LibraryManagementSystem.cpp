#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isIssued = false;
    }
};

class Member {
public:
    int memberId;
    string name;

    Member(int id, string n) {
        memberId = id;
        name = n;
    }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book Added Successfully!\n";
    }

    void searchBook() {
        string query;
        cin.ignore();
        cout << "Enter Title or Author: ";
        getline(cin, query);

        for (auto &b : books) {
            if (b.title == query || b.author == query) {
                cout << "Found: " << b.title << " by " << b.author;
                cout << (b.isIssued ? " [Issued]\n" : " [Available]\n");
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id) {
                if (!b.isIssued) {
                    b.isIssued = true;
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book Already Issued!\n";
                }
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id) {
                if (b.isIssued) {
                    b.isIssued = false;
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "Book was not issued!\n";
                }
                return;
            }
        }
        cout << "Book Not Found!\n";
    }

    void addMember() {
        int id;
        string name;

        cout << "Enter Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));
        cout << "Member Added!\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Add Member\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.searchBook(); break;
            case 3: lib.issueBook(); break;
            case 4: lib.returnBook(); break;
            case 5: lib.addMember(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
