#include <boost/test/unit_test.hpp>
#include "model/Author.h"

class Author;

BOOST_AUTO_TEST_SUITE(TestSuiteAuthor)

    BOOST_AUTO_TEST_CASE(AuthorConstructorTest){

        Author author(1, "Jane", "Doe");

        BOOST_CHECK(author.getAuthorId() == 1);
        BOOST_CHECK(author.getName() == "Jane");
        BOOST_CHECK(author.getSurname() == "Doe");

    }

    BOOST_AUTO_TEST_CASE(AuthorNameSetterTest){

    Author author(1, "Jane", "Doe");

        author.setName("John");
        BOOST_CHECK(author.getName() == "John");
        author.setName("");
        BOOST_CHECK(author.getName() == "John");

    }

    BOOST_AUTO_TEST_CASE(AuthorSurnameSetterTest){

        Author author(1, "Jane", "Doe");

        author.setSurname("Smith");
        BOOST_CHECK(author.getSurname() == "Smith");
        author.setSurname("");
        BOOST_CHECK(author.getSurname() == "Smith");

    }
BOOST_AUTO_TEST_SUITE_END()