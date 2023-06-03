#ifndef LIBRARYPROJECT_CLIENTTYPE_H
#define LIBRARYPROJECT_CLIENTTYPE_H


class ClientType {
private:
    int maxBooks;
    int maxRentalDays;
public:
    ClientType(int maxBooks, int maxRentalDays);

    virtual ~ClientType();

    /*********** getters ***********/

    int getMaxBooks() const;

    int getMaxRentalDays() const;

    /*********** setters ***********/

    void setMaxBooks(int maxBooks);

    void setMaxRentalDays(int maxRentalDays);

    /************ other ************/

    virtual float feeCost(int days);
};


#endif //LIBRARYPROJECT_CLIENTTYPE_H
