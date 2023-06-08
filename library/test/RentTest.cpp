#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Student.h"


BOOST_AUTO_TEST_SUITE(TestSuiteRent)

    BOOST_AUTO_TEST_CASE(RentConstructorTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        BookPtr book = std::make_shared<Book>(1, "To Kill a Mockingbird", author);
        ClientTypePtr student = std::make_shared<Student>(5,90);
        ClientPtr client = std::make_shared<Client>(1, "Jane", "Doe", student);

        Rent rent(1, client, book);

        gr::date today = gr::day_clock::local_day();

        BOOST_CHECK(rent.getRentId() == 1);
        BOOST_CHECK(rent.getClient() == client);
        BOOST_CHECK(rent.getBook() == book);
        BOOST_CHECK(rent.getBeginDate() == today);
        BOOST_CHECK(rent.getEndDate().is_not_a_date());
        BOOST_CHECK(rent.getFee() == 0);
        BOOST_CHECK(client->getBookCount() == 1);
        BOOST_CHECK(book->isRented() == true);

    }

    BOOST_AUTO_TEST_CASE(RentConstructorExceptionsTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        BookPtr book1 = std::make_shared<Book>(1, "To Kill a Mockingbird 1", author);
        BookPtr book2 = std::make_shared<Book>(2, "To Kill a Mockingbird 2", author);
        BookPtr book3 = std::make_shared<Book>(3, "To Kill a Mockingbird 3", author);
        BookPtr bookArchived = std::make_shared<Book>(4, "To Kill a Mockingbird 4", author);
        BookPtr bookRented = std::make_shared<Book>(5, "To Kill a Mockingbird 5", author);
        bookArchived->setIsArchive(true);
        bookRented->setRented(true);

        ClientTypePtr student = std::make_shared<Student>(2,90);
        ClientPtr client1 = std::make_shared<Client>(1, "Jane", "Doe", student);
        ClientPtr client2 = std::make_shared<Client>(2, "Jane", "Doe", student);
        client2->setIsArchive(true);

        BOOST_CHECK_THROW(Rent rent1(1, nullptr, book1), std::logic_error);
        BOOST_CHECK_THROW(Rent rent1(1, client1, nullptr), std::logic_error);

        Rent rent1(1, client1, book1);

        BOOST_CHECK_THROW(Rent rent3(3, client1, bookArchived), std::logic_error);
        BOOST_CHECK_THROW(Rent rent3(3, client1, bookRented), std::logic_error);
        BOOST_CHECK_THROW(Rent rent3(3, client2, book2), std::logic_error);

        Rent rent2(2, client1, book2);

        BOOST_CHECK_THROW(Rent rent3(3, client1, book3), std::logic_error);

    }

    BOOST_AUTO_TEST_CASE(RentEndDateSetterTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        BookPtr book = std::make_shared<Book>(1, "To Kill a Mockingbird", author);
        ClientTypePtr student = std::make_shared<Student>(5,90);
        ClientPtr client = std::make_shared<Client>(1, "Jane", "Doe", student);

        Rent rent(1, client, book);

        gr::date date = gr::day_clock::local_day() + gr::months(1);
        gr::date before = gr::day_clock::local_day() - gr::months(2);

        rent.setEndDate(date);
        BOOST_CHECK(rent.getEndDate() == date);
        BOOST_CHECK_THROW(rent.setEndDate(before), std::logic_error);
        BOOST_CHECK(rent.getEndDate() == date);

    }

    BOOST_AUTO_TEST_CASE(RentFeeSetterTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        BookPtr book = std::make_shared<Book>(1, "To Kill a Mockingbird", author);
        ClientTypePtr student = std::make_shared<Student>(5,90);
        ClientPtr client = std::make_shared<Client>(1, "Jane", "Doe", student);

        Rent rent(1, client, book);

        rent.setFee(10.75);
        BOOST_CHECK(rent.getFee() == 10.75);
        BOOST_CHECK_THROW(rent.setFee(-10), std::logic_error);
        BOOST_CHECK(rent.getFee() == 10.75);

    }

    BOOST_AUTO_TEST_CASE(RentGetRentDaysTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        BookPtr book = std::make_shared<Book>(1, "To Kill a Mockingbird", author);
        ClientTypePtr student = std::make_shared<Student>(5,90);
        ClientPtr client = std::make_shared<Client>(1, "Jane", "Doe", student);

        Rent rent(1, client, book);

        BOOST_CHECK(rent.getRentDays() == 0);

        gr::date date = gr::day_clock::local_day() + gr::days(15);
        rent.setEndDate(date);

        BOOST_CHECK(rent.getRentDays() == 15);

    }

    BOOST_AUTO_TEST_CASE(RentEndRentTest){

        AuthorPtr author = std::make_shared<Author>(1, "Harper", "Lee");
        BookPtr book = std::make_shared<Book>(1, "To Kill a Mockingbird", author);
        ClientTypePtr student = std::make_shared<Student>(5,90);
        ClientPtr client = std::make_shared<Client>(1, "Jane", "Doe", student);

        Rent rent(1, client, book);

        gr::date date = gr::day_clock::local_day() + gr::days(120);

        rent.setEndDate(date);
        rent.endRent();

        BOOST_CHECK(book->isRented() == false);
        BOOST_CHECK(rent.getFee() == 37.5);

    }

BOOST_AUTO_TEST_SUITE_END()