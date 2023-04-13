#ifndef __HEAD_TAIL_LINKED_LIST_H__
#define __HEAD_TAIL_LINKED_LIST_H__
#include "list.hpp"
#include <cstddef>

class HTLLNode {
    public:
        int item;
        HTLLNode *next;
        HTLLNode(int item) {
            this->item = item;
            this->next = NULL;
        }

        ~HTLLNode() {
            if (this->next!=NULL) {
                delete next;
            }
        }
};

class HTLinkedList : public List {
    private:
        HTLLNode *head;
        HTLLNode *tail;
        int totElem;
    public:
        HTLinkedList() {
            this->head = NULL;
            this->tail = NULL;
            this->totElem = 0;
        }

        ~HTLinkedList() {
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

            HTLLNode* nn = new HTLLNode(item);

            if (index==0) {
                nn->next = this->head;
                this->head = nn;
                this->tail = nn;
            } else if (this->totElem-index==0) {
                this->tail->next = nn;
                this->tail = nn;
            } else {
                HTLLNode* p = this->head;
                
                index-=1;
                while (p->next!=NULL && index--) {
                    p = p->next;
                }
                nn->next = p->next;
                p->next = nn;
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
                HTLLNode* removed = NULL;

                removed = this->head;
                this->head = this->head->next;
                this->tail = this->head;

                item = removed->item;
                removed->next = NULL;
                delete removed;

            } else if (index<=totElem-1) {
                HTLLNode* p = this->head;
                HTLLNode* previous = this->head;
                HTLLNode* removed = NULL;
                
                while (p->next!=NULL && index--) {
                    previous = p;
                    p = p->next;
                }

                removed = p;
                previous->next = p->next;
                
                if (p->next == NULL) this->tail = previous;

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
            if (this->totElem >= index) {
                HTLLNode* p = this->head;

                while (p->next!=NULL && index--) {
                    p = p->next;
                }

                item = p->item;

            } else {
                throw std::out_of_range("index is greater than total elements contained in list");
            }

            return item;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        bool search(int item) override {
            HTLLNode* p = this->head;

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
            std::string out = "HTLinkedList\n[ ";
            if (size() != 0) {
                for (HTLLNode *p=this->head; p != NULL; p=p->next) {
                    out += std::to_string(p->item) + " ";
                }
            }

            return out + "]\n";
        }
};
#endif