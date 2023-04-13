#ifndef __STATIC_LINKED_LIST_H__
#define __STATIC_LINKED_LIST_H__

#include "list.hpp"
#include <iostream>
#include <ostream>
#include <stack>
#include <vector>

class StaticLinkedList : public List {
    private:
        int *arr;
        int maxSize;
        int totElem;
        int first;
        int last;
        int *next;
        int freeCell;
    public:
        StaticLinkedList(int n) {
            this->arr = new int[n];
            this->next = new int[n];

            for (int i=0; i<n-1; i++) this->next[i] = i+1;
            this->next[n-1] = -1;

            this->maxSize = n;
            this->totElem = 0;
            this->first = -1;
            this->freeCell = 0;
            
            this->last = -1;
        }

        ~StaticLinkedList() {
            delete arr;
        }

        bool empty() {
            return this->totElem == 0;
        }

        bool full() {
            return this->maxSize == this->totElem;
        }

        int getLastFreeCell() {
            int last = this->freeCell;

            while (this->next[last] != -1) last = this->next[last];

            return last;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        void insert(int item, int index) override {
            if (this->full()) {
                throw array_full();
            }

            if (index < 0) {
                throw std::invalid_argument("index is less than zero");
            }

            if (empty()) {
                this->arr[this->freeCell] = item;
                this->first = 0;
                this->last = 0;
                
                this->freeCell = this->next[this->freeCell];
                this->next[this->last] = -1;

            } else if (index == 0) {
                this->arr[this->freeCell] = item;

                int nextFreeCell = this->next[this->freeCell];

                this->next[this->freeCell] = this->first;

                this->first = this->freeCell;
                this->freeCell = nextFreeCell;
            } else if (this->totElem-index==0) {
                this->next[this->last] = this->freeCell;

                this->arr[this->freeCell] = item;
                this->last = this->freeCell;

                this->freeCell = this->next[this->freeCell];
                this->next[this->last]=-1;
            } else {
                index--;
                int nToMove = this->totElem-index;

                int iToMove = this->first;
                int previous = this->first;

                int count = 0;
                while (count != index) {
                    previous = iToMove;
                    iToMove = this->next[iToMove];
                    count++;
                }

                this->arr[this->freeCell] = this->arr[iToMove];
                this->next[previous] = this->freeCell;
                this->arr[iToMove] = item;

                int nextFreeCell = this->next[this->freeCell];

                this->next[this->freeCell] = iToMove;

                this->freeCell = nextFreeCell;

            }

            this->totElem++;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        int remove(int index) override {
            if (index < 0) {
                throw std::invalid_argument("index is less than zero");
            }

            int item = 0;
            if (index == this->first) {
                item = this->arr[this->first];
                
                this->next[getLastFreeCell()] = this->first;
                this->next[this->first] = -1;

                this->first = this->next[this->first];
                this->totElem--;
            } else if (index <= this->totElem-1) {
                int i = this->first;
                int count = 0;
                int previous=0;

                while (count != index) {
                    previous=i;
                    i = this->next[i];
                    count++;
                }

                item = this->arr[i];
                
                this->next[previous] = this->next[i];

                if (index-this->totElem-1 == 0) this->last = previous;

                this->next[getLastFreeCell()] = i;
                this->next[i] = -1;

                this->totElem--;

            } else {
                throw std::out_of_range("index is greater than total elements contained in list");
            }
            return item;
        }

        // Complexity: O(1)
        int access(int index) override {

            if (index < 0) {
                throw std::invalid_argument("index is less than zero");
            }

            int item = 0;
            if (this->totElem >= index) {
                int i = this->first;
                int count = 0;
                while (count != index) {
                    i = this->next[i];
                    count++;
                }

                item = this->arr[i];

            } else {
                throw std::out_of_range("index is greater than total elements contained in list");
            }

            return item;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        bool search(int item) override {
            int i = this->first;
            while (i != -1) {
                if (this->arr[i] == item) {
                    return true;
                }
                i = this->next[i];
            }

            return false;
        }

        void sort() override {

        }

        int size() override {
            return this->totElem;
        }

        std::string to_string() override {
            std::string out = "STATIC_LINKED_LIST\n[ ";

            int i = this->first;
            while (i != -1) {
                out += std::to_string(this->arr[i]) + " ";
                i = this->next[i];
            }

            return out + "]\n";
        }


};

#endif
