#include "managers/BookManager.h"
#include "model/Repository.h"
#include "model/Book.h"
#include "exceptions/ParametrException.h"

BookManager::BookManager(const BookRepositoryPtr &bookRepository) : bookRepository(bookRepository) {}

BookManager::~BookManager() {}


const BookPtr BookManager::registerBook(int id, std::string title, const AuthorPtr &author) {
    BookPtr bookCheck = getBook(id);
    if (bookCheck == nullptr) {
        BookPtr newBook = std::make_shared<Book>(id, title, author);
        bookRepository->add(newBook);
        return newBook;
    } else {
        if (bookCheck->isArchive1()) {
            bookCheck->setIsArchive(false);
        }
        return bookCheck;
    }
}

void BookManager::unregisterBook(const BookPtr &book) {
    if (book == nullptr) {
        throw ParametrException("Wrong input");
    }
    book->setIsArchive(true);
}

const BookPtr BookManager::getBook(int id) const {
    BookPredicate predicate = [id](const BookPtr ptr) {
        return ptr->getId() == id;
    };
    return bookRepository->find(predicate);
}

std::string BookManager::getAllBooksReports() const {
    return bookRepository->report();
}

