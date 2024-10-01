#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

class LibraryItem {
public:
    virtual void printDetails() const = 0;
    virtual ~LibraryItem() {}
};

#endif // LIBRARYITEM_H
