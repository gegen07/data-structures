#ifndef LIST_H
#define LIST_H

#include <exception>
#include <iostream>
#include <stdexcept>
#include <type_traits>

struct array_full : public std::exception {
    const char * what () const throw () {
        return "array is full";
    }
};

class List {
    public:
        virtual void insert(int item, int index) = 0;
        virtual int remove(int index) = 0;
        virtual int access(int index) = 0;
        virtual bool search(int item) = 0;
        virtual void sort() = 0;
        virtual std::string to_string() = 0;
        virtual int size() = 0;
        
        friend std::ostream& operator<<(std::ostream& os, List& list) {
            return os << list.to_string();
        }
};

void testingList(List &list);

#endif
