#ifndef LIBRARYPROJECT_USERINTERFACE_H
#define LIBRARYPROJECT_USERINTERFACE_H

#include "typedefs.h"

class UserInterface {
private:
    ClientManagerPtr clientManager;
    RentManagerPtr rentManager;
    BookManagerPtr bookManager;
public:
    UserInterface(const ClientManagerPtr &clientManager, const RentManagerPtr &rentManager, const BookManagerPtr &bookManager);
    virtual ~UserInterface();

    void menu();
    void rent();
    void book();
    void client();
};


#endif //LIBRARYPROJECT_USERINTERFACE_H
