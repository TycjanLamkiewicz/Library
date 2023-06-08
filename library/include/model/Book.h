#ifndef CARRENTAL_BOOK_H
#define CARRENTAL_BOOK_H

#include <string>
#include "typedefs.h"
#include "model/Author.h"

class Book {
private:
    const int id;
    std::string title;
    bool rented = false;
    bool isArchive = false;
    const AuthorPtr author;
public:
    Book(int id, const std::string &title, const AuthorPtr &author);

    virtual ~Book();

    /*********** getters ***********/

    const int getId() const;

    const std::string &getTitle() const;

    bool isRented() const;

    bool isArchive1() const;

    const AuthorPtr &getAuthor() const;

    /*********** setters ***********/

    void setTitle(const std::string &title);

    void setRented(bool rented);

    void setIsArchive(bool isArchive);

    /************ other ************/

    std::string getInfo();
};


#endif //CARRENTAL_BOOK_H
