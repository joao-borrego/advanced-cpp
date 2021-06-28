#ifndef RING_H_
#define RING_H_

#include <iostream>

using namespace std;

template<class T>
class ring {

private:

    /// Array of values of type T
    T *_values;
    /// Maximum size of values array
    uint _size;
    /// Current size of values array
    uint _pos;

public:
    class iterator;

    ring(int size): _size(size), _pos(0), _values() {
        _values = new T[size];
    }

    ~ring() {
        delete [] _values;
    }

    int size() const {
        return _size;
    }

    void add(T value) {
        _values[_pos++] = value;
        if (_pos == _size)
            _pos = 0;
    }

    T &get(int idx) {
        if (idx >= _size)
            throw;
        return _values[idx];
    }

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(_size, *this);
    }
};

template<class T>
class ring<T>::iterator {

private:
    uint _pos;
    ring<T> &_ring;

public:
    iterator(int pos, ring &aRing) : _pos(pos), _ring(aRing) {

    }

    iterator &operator++(int) {
        _pos++;
        return *this;
    }

    iterator &operator++() {
        _pos++;
        return *this;
    }

    T operator*() {
        return _ring.get(_pos);
    }

    bool operator!=(const iterator &other) const {
        return _pos != other._pos;
    }
};

#endif
