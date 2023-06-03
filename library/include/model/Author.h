#ifndef LIBRARYPROJECT_AUTHOR_H
#define LIBRARYPROJECT_AUTHOR_H


#include <string>

class Author {
private:
    const int authorID;
    std::string name;
    std::string surname;
public:
    Author(int authorId, const std::string &name, const std::string &surname);

    virtual ~Author();

    /*********** getters ***********/

    int getAuthorId() const;

    const std::string &getName() const;

    const std::string &getSurname() const;

    /*********** setters ***********/

    void setName(const std::string &name);

    void setSurname(const std::string &surname);

    /************ other ************/

    std::string getAuthorInfo();
};


#endif //LIBRARYPROJECT_AUTHOR_H
