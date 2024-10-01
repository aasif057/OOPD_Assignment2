#ifndef PUBLICATIONRANK_H
#define PUBLICATIONRANK_H

#include <string>
#include "LibraryItem.h" // Include the LibraryItem base class

class PublicationRank : public LibraryItem {
private:
    int ID;
    std::string publication;
    int rank;
    double totalPaid;
    bool borrowed;

public:
    PublicationRank(int ID, const std::string &publication, int rank, double totalPaid);
    int getID() const;
    std::string getPublication() const;
    int getrank() const;
    double gettotalPaid() const;
    bool isBorrowed() const;
    void setBorrowed(bool status);
    void printDetails() const override;
};

#endif // PUBLICATIONRANK_H
