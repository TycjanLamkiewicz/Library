#include "model/UserInterface.h"
#include "model/Client.h"
#include "model/Author.h"
#include "model/Rent.h"
#include "model/Book.h"
#include "managers/ClientManager.h"
#include "managers/RentManager.h"
#include "managers/BookManager.h"
#include "exceptions/ParametrException.h"
#include <iostream>
#include <string>

using namespace std;


UserInterface::UserInterface(const ClientManagerPtr &clientManager, const RentManagerPtr &rentManager,
                             const BookManagerPtr &bookManager) : clientManager(clientManager),
                                                                  rentManager(rentManager), bookManager(bookManager) {}

UserInterface::~UserInterface() {}


void UserInterface::menu() {
    bool end = false;

    while(!end) {
        cout << "-------------------MENU-------------------" << endl
             << "1. CUSTOMER MANAGEMENT" << endl
             << "2. RENT MANAGEMENT" << endl
             << "3. BOOK MANAGEMENT" << endl
             << "4. EXIT" << endl
             << "------------------------------------------" << endl << endl << endl
             << "YOUR DECISION: ";
        char decision;
        cin >> decision;

        switch(decision) {
            case '1':
                client();
                break;
            case '2':
                rent();
                break;
            case '3':
                book();
                break;
            case '4':
                end = true;
                break;
            default:
                cout << "INCORRECTLY ENTERED DATA" << endl << endl;
                break;
        }
    }
}

void UserInterface::rent() {
    bool end = false;

    while(!end) {
        cout << endl << endl << endl << endl
             << "-------------------MENU-------------------" << endl
             << "1. VIEW INFORMATION ABOUT ALL CURRENT RENTS" << endl
             << "2. VIEW INFORMATION ABOUT ALL ARCHIVE RENTS" << endl
             << "3. RENT BOOK" << endl
             << "4. RETURN BOOK" << endl
             << "5. EXIT" << endl
             << "------------------------------------------" << endl << endl << endl
             << "YOUR DECISION: ";
        char decision;
        cin >> decision;

        switch(decision) {
            case '1': {
                cout << rentManager->getAllCurrentRentsReports() << endl;
                break;
            }
            case '2': {
                cout << rentManager->getAllArchiveRentsReports() << endl;
                break;
            }
            case '3': {
                int customerId, rentalId;

                cout << "Type client ID: ";
                cin >> customerId;

                ClientPtr client = clientManager->getClient(customerId);
                if (client == nullptr) {
                    cout << "CLIENT DOES NOT EXIST" << endl;
                    return;
                }

                cout << "Type book ID: ";
                cin >> rentalId;

                try {
                    BookPtr book = bookManager->getBook(rentalId);
                    if (book == nullptr) {
                        cout << "BOOK DOES NOT EXIST" << endl;
                        return;
                    }
                    rentManager->rentBook(client, book);
                } catch (ParametrException &e) {
                    cerr << "INVALID DATA" << e.what() << endl;
                }

                cout << "BOOK BORROWED WITH SUCCESS" << endl;

                break;
            }
            case '4': {
                int rentalID;

                cout << "Type book ID:";
                cin >> rentalID;
                try {
                    rentManager->returnBook(bookManager->getBook(rentalID));
                } catch (ParametrException &e) {
                    cerr << "INVALID DATA" << e.what() << endl;
                }
                cout << "BOOK UNBORROWED WITH SUCCESS" << endl;

                break;
            }
            case '5': {
                end = true;
                break;
            }
            default: {
                cout << "INCORRECTLY ENTERED DATA" << endl << endl;
                break;
                }
            }
        }
    }

void UserInterface::book() {
    bool end = false;

    while(!end) {
        cout << endl << endl << endl << endl
             << "-------------------MENU-------------------" << endl
             << "1. VIEW INFORMATION ABOUT ALL BOOKS" << endl
             << "2. REGISTER BOOK" << endl
             << "3. UNREGISTER BOOK" << endl
             << "4. EXIT" << endl
             << "------------------------------------------" << endl << endl << endl
             << "YOUR DECISION: ";
        char decision;
        cin >> decision;

        switch(decision) {
            case '1': {
                cout << bookManager->getAllBooksReports() << endl;
                break;
            }
            case '2': {
                int newBookID, newAuthorID;
                string newBookTitle, newAuthorName, newAuthorSurname;
                cout << "Type book ID: ";
                cin >> newBookID;
                cout << "Type book title: ";
                cin.ignore();
                getline(cin,newBookTitle);
                cout << "Type author ID: ";
                cin >> newAuthorID;
                cout << "Type author name: ";
                cin.ignore();
                getline(cin,newAuthorName);
                cout << "Type author surname: ";
                getline(cin,newAuthorSurname);

                try {
                    bookManager->registerBook(newBookID, newBookTitle, make_shared<Author>(newAuthorID, newAuthorName, newAuthorSurname));
                } catch (ParametrException &e) {
                    cerr << "INVALID DATA " << e.what() << endl;
                }

                cout << "BOOK REGISTERED WITH SUCCESS" << endl;

                break;
            }
            case '3': {
                int oldBookID;
                cout << "Type book ID: ";
                cin >> oldBookID;

                try {
                    bookManager->unregisterBook(bookManager->getBook(oldBookID));
                } catch (ParametrException &e) {
                    cerr << "INVALID DATA" << e.what() << endl;
                }

                cout << "BOOK UNREGISTERED WITH SUCCESS" << endl;

                break;
            }
            case '4': {
                end = true;
                break;
            }
            default: {
                cout << "INCORRECTLY ENTERED DATA" << endl << endl;
                break;
            }
        }
    }
}

void UserInterface::client() {
    bool end = false;

    while(!end) {
        cout << endl << endl << endl << endl
             << "-------------------MENU-------------------" << endl
             << "1. VIEW INFORMATION ABOUT ALL CLIENTS" << endl
             << "2. REGISTER CLIENTS" << endl
             << "3. UNREGISTER CLIENTS" << endl
             << "4. EXIT" << endl
             << "------------------------------------------" << endl << endl << endl
             << "YOUR DECISION: ";
        char decision;
        cin >> decision;

        switch(decision) {
            case '1': {
                cout << clientManager->getAllClientsReports() << endl;
                break;
            }
            case '2': {
                string newClientFirstName, newClientLastName;
                int newClientID, newMaxBooks, newMaxDays;
                cout << "Type first name: ";
                cin.ignore();
                getline(cin,newClientFirstName);
                cout << "Type last name: ";
                getline(cin,newClientLastName);
                cout << "Type ID: ";
                cin >> newClientID;
                cout << "Type max quantity of books: ";
                cin >> newMaxBooks;
                cout << "Type max rental days: ";
                cin >> newMaxDays;

                try {
                    clientManager->registerClient(newClientFirstName, newClientLastName, newClientID, make_shared<ClientType>(newMaxBooks, newMaxDays));
                } catch (ParametrException &e) {
                    cerr << "INVALID DATA" << e.what() << endl;
                }

                cout << "CLIENT REGISTERED WITH SUCCESS" << endl;

                break;
            }
            case '3': {
                int oldClientID;
                cout << "Type client ID: ";
                cin >> oldClientID;

                try {
                    ClientPtr client = clientManager->getClient(oldClientID);
                    if (client == nullptr) {
                        cout << "THIS CLIENT DOES NOT EXIST" << endl;
                        return;
                    }
                    clientManager->unregisterClient(client);
                    cout << "CLIENT UNREGISTERED WITH SUCCESS" << endl;
                } catch (ParametrException &e) {
                    cerr << "INVALID DATA" << e.what() << endl;
                }

                break;
            }
            case '4': {
                end = true;
                break;
            }
            default: {
                cout << "INCORRECTLY ENTERED DATA" << endl << endl;
                break;
            }
        }
    }
}