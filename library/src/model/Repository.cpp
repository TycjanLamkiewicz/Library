#include "model/Repository.h"
#include "model/Client.h"
#include "model/Rent.h"
#include "model/Book.h"
#include "exceptions/LogicException.h"


template
class Repository<ClientPtr>;

template
class Repository<BookPtr>;

template
class Repository<RentPtr>;


template<class T>
T Repository<T>::get(unsigned int id) const {
    if (id < size()) {
        return elements[id];
    }
    throw LogicException("Wrong index");
}

template<class T>
void Repository<T>::add(T element) {
    if (element == nullptr) {
        throw LogicException("Wrong value");
    }
    elements.push_back(element);
}

template<class T>
void Repository<T>::remove(T element) {
    for (int i = 0; i < size(); ++i) {
        if (element == get(i)) {
            elements.erase(elements.begin() + i);
        }
    }
}

template<class T>
std::string Repository<T>::report() const {
    std::string text;
    for (int i = 0; i < size(); i++) {
        text = text + (get(i)->getInfo() + " \n");
    }
    return text;
}

template<class T>
int Repository<T>::size() const {
    return elements.size();
}

template<class T>
T Repository<T>::find(const std::function<bool(T)> &predicate) const {
    for (int i = 0; i < size(); i++) {
        T element = get(i);
        if (predicate(element)) {
            return element;
        }
    }
    return nullptr;
}

template<class T>
std::vector<T> Repository<T>::findAll(const std::function<bool(T)> &predicate) const {
    std::vector<T> result;
    for (int i = 0; i < size(); ++i) {
        T element = get(i);
        if (predicate(element)) {
            result.push_back(element);
        }
    }
    return result;
}
