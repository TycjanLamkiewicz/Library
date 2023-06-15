#include <iostream>
#include "managers/RentManager.h"
#include "managers/BookManager.h"
#include "managers/ClientManager.h"
#include "model/Repository.h"
#include "model/UserInterface.h"
#include "typedefs.h"

int main() {

    RentRepositoryPtr currentRents = std::make_shared<Repository<RentPtr>>();
    RentRepositoryPtr archiveRents = std::make_shared<Repository<RentPtr>>();
    RentManagerPtr rentManager = std::make_shared<RentManager>(currentRents, archiveRents);
    BookRepositoryPtr newBookRepository = std::make_shared<Repository<BookPtr>>();
    BookManagerPtr bookManager = std::make_shared<BookManager>(newBookRepository);
    ClientRepositoryPtr newClientRepository = std::make_shared<Repository<ClientPtr>>();
    ClientManagerPtr clientManager = std::make_shared<ClientManager>(newClientRepository);
    UserInterface ui(clientManager, rentManager, bookManager);
    ui.menu();


	return 0;
}
