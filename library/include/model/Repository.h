#ifndef LIBRARYPROJECT_REPOSITORY_H
#define LIBRARYPROJECT_REPOSITORY_H

#include <functional>
#include <vector>
#include <string>

template<class T>
class Repository {
private:
    std::vector<T> elements;
public:
    Repository() {}
    virtual ~Repository() {}
    T get(unsigned int id) const;
    void add(T element);
    void remove(T element);
    std::string report() const;
    int size() const;
    T find(const std::function<bool(T)> &predicate) const;
    std::vector<T> findAll(const std::function<bool(T)> &predicate) const;
};


#endif //LIBRARYPROJECT_REPOSITORY_H
