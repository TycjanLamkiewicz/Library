#include <boost/test/unit_test.hpp>
#include "model/ClientType.h"
#include "model/Student.h"
#include "model/NonStudent.h"

class ClientType;

BOOST_AUTO_TEST_SUITE(TestSuiteClientType)

    BOOST_AUTO_TEST_CASE(ClientTypeConstructorTest){

        Student student(10, 90);
        NonStudent nonStudent(5, 30, 100);

        BOOST_CHECK(student.getMaxBooks() == 10);
        BOOST_CHECK(student.getMaxRentalDays() == 90);
        BOOST_CHECK(nonStudent.getMaxBooks() == 5);
        BOOST_CHECK(nonStudent.getMaxRentalDays() == 30);
        BOOST_CHECK(nonStudent.getAdditionalFee() == 100);

    }

    BOOST_AUTO_TEST_CASE(ClientTypeMaxBooksSetterTest){

        NonStudent nonStudent(5, 30, 100);

        nonStudent.setMaxBooks(15);
        BOOST_CHECK(nonStudent.getMaxBooks() == 15);

        nonStudent.setMaxBooks(0);
        BOOST_CHECK(nonStudent.getMaxBooks() == 15);

    }

    BOOST_AUTO_TEST_CASE(ClientTypeMaxRentalDaysSetterTest){

        NonStudent nonStudent(5, 30, 100);

        nonStudent.setMaxRentalDays(20);
        BOOST_CHECK(nonStudent.getMaxRentalDays() == 20);
        nonStudent.setMaxRentalDays(0);
        BOOST_CHECK(nonStudent.getMaxRentalDays() == 20);

    }

    BOOST_AUTO_TEST_CASE(NonStudentAdditionalFeeSetterTest){

        NonStudent nonStudent(5, 30, 100);

        nonStudent.setAdditionalFee(25);
        BOOST_CHECK(nonStudent.getAdditionalFee() == 25);
        nonStudent.setAdditionalFee(0);
        BOOST_CHECK(nonStudent.getAdditionalFee() == 25);

    }

    BOOST_AUTO_TEST_CASE(ClientTypeFeeCostTest){

        Student student(10, 90);
        NonStudent nonStudent(5, 30, 100);

        BOOST_CHECK(student.feeCost(120) == 37.5);
        BOOST_CHECK(nonStudent.feeCost(120) == 212.5);
        BOOST_CHECK(student.feeCost(10) == 0);
        BOOST_CHECK(nonStudent.feeCost(10) == 0);

    }

BOOST_AUTO_TEST_SUITE_END()