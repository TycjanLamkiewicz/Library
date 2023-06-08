#ifndef LIBRARYPROJECT_RENT_H
#define LIBRARYPROJECT_RENT_H

#include <boost/date_time.hpp>
#include "typedefs.h"
#include "model/Client.h"
#include "model/Book.h"

namespace gr = boost::gregorian;

class Rent : public std::enable_shared_from_this<Rent> {
private:
    const int rentID;
    gr::date beginDate;    // default: not_a_date_time
    gr::date endDate;      // default: not_a_date_time
    float fee = 0;
    const ClientPtr client;
    const BookPtr book;
public:
    Rent(int rentId, const ClientPtr &client, const BookPtr &book);

    virtual ~Rent();

    /*********** getters ***********/

    int getRentId() const;

    const gr::date &getBeginDate() const;

    const gr::date &getEndDate() const;

    float getFee() const;

    const ClientPtr &getClient() const;

    const BookPtr &getBook() const;

    /*********** setters ***********/

    void setEndDate(const gr::date &endDate);

    void setFee(float fee);

    /************ other ************/

    std::string getInfo();

    int getRentDays();

    void endRent();
};


#endif //LIBRARYPROJECT_RENT_H
