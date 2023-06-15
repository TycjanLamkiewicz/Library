#ifndef LIBRARYPROJECT_BOOKMANAGER_H
#define LIBRARYPROJECT_BOOKMANAGER_H

#include "typedefs.h"

class BookManager {
private:
    BookRepositoryPtr bookRepository;
public:
    explicit BookManager(const BookRepositoryPtr &bookRepository);
    virtual ~BookManager();

    const BookPtr registerBook(int id, std::string title, const AuthorPtr& author);
    void unregisterBook(const BookPtr& book);
    const BookPtr getBook(int id) const;
    std::string getAllBooksReports() const;
};


#endif //LIBRARYPROJECT_BOOKMANAGER_H
