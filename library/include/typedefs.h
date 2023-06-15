#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include <memory>
#include <functional>

class Author;
class Book;
class Client;
class ClientType;
class NonStudent;
class Rent;
class Student;
template<class T>
class Repository;
class ClientManager;
class RentManager;
class BookManager;

typedef std::shared_ptr<Author> AuthorPtr;
typedef std::shared_ptr<Book> BookPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<NonStudent> NonStudentPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Student> StudentPtr;
typedef std::shared_ptr<Repository<ClientPtr>> ClientRepositoryPtr;
typedef std::shared_ptr<Repository<RentPtr>> RentRepositoryPtr;
typedef std::shared_ptr<Repository<BookPtr>> BookRepositoryPtr;
typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;
typedef std::function<bool(BookPtr)> BookPredicate;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;
typedef std::shared_ptr<BookManager> BookManagerPtr;

#endif //CARRENTAL_TYPEDEFS_H
