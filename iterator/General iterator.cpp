//21125141 - Tran Thuc Minh Tri
//Based on: https://github.com/codetechandtutorials/DesignPatterns/blob/master/DesignPatterns/Iterator/main.cpp
//Edited slightly so that we can understand
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename U>
class Iterator {
public:
    Iterator(U* container) : _data_ref(container) {
        _it = _data_ref->_data.begin();
    }

    void First() {
        _it = _data_ref->_data.begin();
    }

    void Next() {
        _it++;
    }

    bool AtEnd() {
        return (_it == _data_ref->_data.end());
    }

    typename vector<T>::iterator Current() {
        return _it;
    }

private:
    U* _data_ref;
    typename vector<T>::iterator _it;
};

template <typename T>
class Container {
    friend class Iterator<T, Container>;

public:
    void Add(T new_data) {
        _data.push_back(new_data);
    }

    Iterator<T, Container>* CreateIterator() {
        return new Iterator<T, Container>(this);
    }

private:
    vector<T> _data;
};


int main() {

    Container<int> our_data_bag; //container
    for (int i = 0; i < 10; i++) {
        our_data_bag.Add(i);
    }
    auto* our_iterator = our_data_bag.CreateIterator(); //iterator, no need to know what data type the container is
    for (our_iterator->First(); !our_iterator->AtEnd(); our_iterator->Next()) {
        cout << *our_iterator->Current() << endl;
    }
    return EXIT_SUCCESS;
}
