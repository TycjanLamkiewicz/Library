#include "model/IdGenerator.h"

IdGenerator::IdGenerator() : gen(rd()), distribution(1000, 9999) {}

IdGenerator::~IdGenerator() {}

int IdGenerator::generateRandomID() {
    int randomID = distribution(gen);

    while (usedIDs.find(randomID) != usedIDs.end()) {
        randomID = distribution(gen);
    }

    usedIDs.insert(randomID);
    return randomID;
}
