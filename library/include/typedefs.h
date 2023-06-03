#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include <memory>

class Author;
class Book;
class Client;
class ClientType;
class NonStudent;
class Rent;
class Student;

typedef std::shared_ptr<Author> AuthorPtr;
typedef std::shared_ptr<Book> BookPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<NonStudent> NonStudentPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Student> StudentPtr;

#endif //CARRENTAL_TYPEDEFS_H
