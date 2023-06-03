#include <boost/test/unit_test.hpp>
#include "model/Book.h"

class Book;

BOOST_AUTO_TEST_SUITE(TestSuiteBook)

    BOOST_AUTO_TEST_CASE(BookConstructorTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        Book book(1, "To Kill a Mockingbird", author);

        BOOST_CHECK(book.getId() == 1);
        BOOST_CHECK(book.getTitle() == "To Kill a Mockingbird");
        BOOST_CHECK(book.getAuthor() == author);
        BOOST_CHECK(book.isRented() == false);
        BOOST_CHECK(book.isArchive1() == false);

    }

    BOOST_AUTO_TEST_CASE(BookTitleSetterTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        Book book(1, "To Kill a Mockingbird", author);

        book.setTitle("TKaM");
        BOOST_CHECK(book.getTitle() == "TKaM");
        book.setTitle("");
        BOOST_CHECK(book.getTitle() == "TKaM");

    }

    BOOST_AUTO_TEST_CASE(BookRentedSetterTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        Book book(1, "To Kill a Mockingbird", author);

        book.setRented(true);
        BOOST_CHECK(book.isRented() == true);

    }

    BOOST_AUTO_TEST_CASE(BookIsArchiveSetterTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        Book book(1, "To Kill a Mockingbird", author);

        book.setIsArchive(true);
        BOOST_CHECK(book.isArchive1() == true);

    }
BOOST_AUTO_TEST_SUITE_END()