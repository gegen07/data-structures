#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include "list.hpp"
#include <iostream>
#include <ostream>

class LLNode {
    public:
        int item;
        LLNode *next;
        LLNode(int item) {
            this->item = item;
            this->next = NULL;
        }

        ~LLNode() {
            if (this->next!=NULL) {
                delete next;
            }
        }
};

class LinkedList : public List {
    private:
        LLNode *head;
        int totElem;
    public:
        LinkedList() {
            this->head = NULL;
            this->totElem = 0;
        }

        ~LinkedList() {
            if (head != NULL) {
                delete head; //iterate
            }
        }

        bool empty() {
            return this->totElem == 0;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        void insert(int item, int index) override {
            if (index < 0) {
                throw std::invalid_argument("index is less than zero");
            }

            LLNode* nn = new LLNode(item);
            
            if (index == 0) {
                nn->next = this->head;
                this->head = nn;
            } else if(this->totElem-index==0) {
                LLNode* p = this->head;
                
                while (p->next!=NULL && index--) {
                    p = p->next;
                }

                p->next = nn;
            } else {
                LLNode* previous = this->head;
                LLNode* p = this->head;
                
                while (p->next!=NULL && index--) {
                    previous = p;
                    p = p->next;
                }

                previous->next = nn;
                nn->next = p;
            }

            this->totElem++;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        int remove(int index) override {
            if (index < 0) {
                throw std::invalid_argument("index is less than zero");
            }


            if (empty()) {
                throw std::out_of_range("list is empty");
            }

            int item = 0;

            if (index == 1) {
                LLNode* removed = NULL;

                removed = this->head;
                this->head = this->head->next;

                item = removed->item;
                removed->next = NULL;
                delete removed;

            } else if (index <= totElem-1) {
                LLNode* p = this->head;
                LLNode* previous = p;
                LLNode* removed = NULL;

                while (p->next!=NULL && index--) {
                    previous = p;
                    p = p->next;
                }

                removed = p;
                previous->next = removed->next;

                item = removed->item;

                removed->next = NULL;
                delete removed;

            } else {
                throw std::out_of_range("index is greater than total elements contained in list");
            }
            
            this->totElem--;
            return item;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        int access(int index) override {

            if (index < 0) {
                throw std::invalid_argument("index is less than zero");
            }

            int item = 0;
            
            LLNode* p = this->head;

            while (p->next!=NULL && index--) {
                p = p->next;
            }

            item = p->item;


            return item;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        bool search(int item) override {
            LLNode* p = this->head;

            while (p->next!=NULL) {
                if (p->item == item) return true;

                p = p->next;

            }

            item = p->item;


            return false;
        }

        void sort() override {

        }

        int size() override {
            return this->totElem;
        }

        std::string to_string() override {
            std::string out = "LINKED LIST\n[ ";
            if (size()) {
                for (LLNode *p=this->head; p != NULL; p=p->next) {
                    out += std::to_string(p->item) + " ";
                }
            }

            return out + "]\n";
        }


};

#endif
