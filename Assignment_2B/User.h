#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
#include "Book.h"      // Include the Book class
#include "PublicationRank.h" // Include the PublicationRank class
#include "Journals.h"  // Include the Journals class

class User {
private:
    std::string name;
    bool isTeacher;
    static const int MAX_BORROWED_BOOKS = 3; // Maximum number of books a user can borrow
    int borrowedCount;

public:
    Book *borrowedBooks[MAX_BORROWED_BOOKS];
    PublicationRank *borrowedbooks[MAX_BORROWED_BOOKS];
    Journals *borrowedJournals[MAX_BORROWED_BOOKS];
    std::time_t borrowedDates[MAX_BORROWED_BOOKS];

    User();
    User(const std::string &name, bool isTeacher);
    std::string getName() const;
    bool isTeacherUser() const;
    int getBorrowedCount() const;
    int getMaxBorrowedBooks() const;
    void incrementBorrowedCount();
    bool isBookBorrowed(Book *book) const;
    bool canBorrowMoreBooks() const;
    std::time_t getLastBorrowTime(const Book *book) const;
    void setLastBorrowTime(const Book *book, std::time_t borrowTime);
    std::time_t getLastBorrowPubTime(const PublicationRank *publicationRank) const;
    void setLastBorrowPubTime(const PublicationRank *publicationRank, std::time_t borrowTime);
};

#endif // USER_H
