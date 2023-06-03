#include "model/Student.h"

Student::Student(int maxBooks, int maxRentalDays) : ClientType(maxBooks, maxRentalDays) {}

Student::~Student() {

}

float Student::feeCost(int days) {
    return ClientType::feeCost(days);
}
