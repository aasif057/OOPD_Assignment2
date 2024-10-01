#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "LibraryItem.h"  // Assuming LibraryItem is defined here
#include "Book.h"         // Include the header for Book
#include "User.h"         // Include the header for User
#include "PublicationRank.h" // Include the header for PublicationRank
#include "Journals.h"     // Include the header for Journals

const int MAX_ITEMS = 100; // Maximum number of items in the library

class Library {
private:
    LibraryItem *libraryItems[MAX_ITEMS];
    int itemCount;
    int nextBookId;
    int totalCopies;

    User students[100]; // Assuming a maximum of 100 students
    int studentCount;

    User teachers[50]; // Assuming a maximum of 50 teachers
    int teacherCount;

public:
    Library(); // Constructor

    // Getters
    int getStudentCount() const;
    int getTeacherCount() const;
    int getTotalUsers() const;
    int getTotalItems() const;

    // Item management
    void addItem(LibraryItem *item);
    void printAllItems() const;
    Book *getBookByID(int bookID) const;
    Book *getBookByIsbn(int bookIsbn) const;

    // Search functions
    void searchBooksByAuthor(const std::string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchBooksByTitle(const std::string &bookTitle, Book *matchingBooks[], int &matchingCount);
    void searchPublication(const std::string &publicationTitle, PublicationRank *matchingBooks[], int &matchingCount);
    void searchJournal(const std::string &journalTitle, Journals *matchingBooks[], int &matchingCount);

    // User management
    void registerUser(const std::string &name, bool isTeacher);
    void showAllRegisteredUsers();

    // String comparison functions
    bool isEqualIgnoreCase(const std::string &str1, const std::string &str2);
    bool isEqualIgnore(const std::string &str1, const std::string &str2);

    // Book management
    void addBook(int isbn, const std::string &author, const std::string &title, int originalPublicationYear);
    bool borrowBook(const std::string &userName, int bookIdToBorrow);
    bool returnBook(Book *book);
    bool borrowPublication(const std::string &userName, int publication);
    bool returnPub(PublicationRank *publicationRank);
    bool borrowJournal(const std::string &userName, int title);

    virtual ~Library(); // Virtual destructor
};

#endif // LIBRARY_H
 