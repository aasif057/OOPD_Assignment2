#ifndef JOURNALS_H
#define JOURNALS_H

#include <string>
#include "LibraryItem.h" // Include the LibraryItem base class

class Journals : public LibraryItem {
private:
    int ID;
    std::string title;

public:
    Journals(int ID, const std::string &title);
    int getID() const;
    std::string getTitle() const;
    void printDetails() const override;
};

#endif // JOURNALS_H
