#ifndef LIBRARYPROJECT_IDGENERATOR_H
#define LIBRARYPROJECT_IDGENERATOR_H

#include <unordered_set>
#include <random>

class IdGenerator {
private:
    std::unordered_set<int> usedIDs;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> distribution;

public:
    IdGenerator();
    virtual ~IdGenerator();

    int generateRandomID();
};


#endif //LIBRARYPROJECT_IDGENERATOR_H
