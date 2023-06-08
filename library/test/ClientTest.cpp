#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Student.h"
#include "model/NonStudent.h"


BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(ClientConstructorTest){

        ClientTypePtr student = std::make_shared<Student>(5,90);
        Client client(1, "Jane", "Doe", student);

        BOOST_CHECK(client.getClientId() == 1);
        BOOST_CHECK(client.getFirstName() == "Jane");
        BOOST_CHECK(client.getLastName() == "Doe");
        BOOST_CHECK(client.getBookCount() == 0);
        BOOST_CHECK(client.getClientType() == student);

    }

    BOOST_AUTO_TEST_CASE(ClientConstructorExceptionsTest){

        ClientTypePtr student = std::make_shared<Student>(5,90);

        BOOST_CHECK_THROW(Client client(1, "", "Doe", student), std::logic_error);
        BOOST_CHECK_THROW(Client client(1, "Jane", "", student), std::logic_error);
        BOOST_CHECK_THROW(Client client(1, "Jane", "Doe", nullptr), std::logic_error);

    }

    BOOST_AUTO_TEST_CASE(ClientFirstNameSetterTest){

        ClientTypePtr student = std::make_shared<Student>(5,90);
        Client client(1, "Jane", "Doe", student);

        client.setFirstName("John");
        BOOST_CHECK(client.getFirstName() == "John");
        BOOST_CHECK_THROW(client.setFirstName(""), std::logic_error);
        BOOST_CHECK(client.getFirstName() == "John");

    }

    BOOST_AUTO_TEST_CASE(ClientLastNameSetterTest){

        ClientTypePtr student = std::make_shared<Student>(5,90);
        Client client(1, "Jane", "Doe", student);

        client.setLastName("Smith");
        BOOST_CHECK(client.getLastName() == "Smith");
        BOOST_CHECK_THROW(client.setLastName(""), std::logic_error);
        BOOST_CHECK(client.getLastName() == "Smith");

    }

    BOOST_AUTO_TEST_CASE(ClientClientTypeSetterTest){

        ClientTypePtr student = std::make_shared<Student>(5,90);
        ClientTypePtr nonStudent = std::make_shared<NonStudent>(5,90,100);
        Client client(1, "Jane", "Doe", student);

        client.setClientType(nonStudent);
        BOOST_CHECK(client.getClientType() == nonStudent);
        BOOST_CHECK_THROW(client.setClientType(nullptr), std::logic_error);
        BOOST_CHECK(client.getClientType() == nonStudent);

    }

BOOST_AUTO_TEST_SUITE_END()