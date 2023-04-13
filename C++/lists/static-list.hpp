#include "list.hpp"
#include <string>

class StaticList : public List {
    private:
        int *arr;
        int maxSize;
        int totElem;
    public:
        StaticList(int n) {
            this->arr = new int[n];
            this->maxSize = n;
            this->totElem = 0;
        }

        ~StaticList() {
            delete arr;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        void insert(int item, int index) override {
            if (this->maxSize == this->totElem) {
                throw array_full();
            }

            if (index < 0) {
                throw std::invalid_argument("index is less than zero");
            }

            if (index > this->totElem) {
                this->arr[this->totElem++] = item;
            } else {
                for (int i=this->totElem-1; i>=index; i--) {
                    this->arr[i+1] = this->arr[i];
                }

                this->arr[index] = item;

                this->totElem++;
            }
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        int remove(int index) override {
            if (index < 0) {
                throw std::invalid_argument("index is less than zero");
            }

            int item = 0;
            if (totElem >= index+1) {
                item = this->arr[index];
                
                this->totElem--;
                
                for (int i=index+1; i<=this->totElem; i++) arr[i-1] = arr[i];
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
                item = this->arr[index];
            } else {
                throw std::out_of_range("index is greater than total elements contained in list");
            }

            return item;
        }

        // Worst-case: O(n) 
        // Best-case: O(1)
        bool search(int item) override {
            for (int i=0; i<this->totElem; i++) {
                if (this->arr[i] == item) {
                    return true;
                }
            }

            return false;
        }

        void sort() override {

        }

        int size() override {
            return this->totElem;
        }

        std::string to_string() override {
            std::string out = "STATIC-LIST\n[ ";
            for (int i=0; i<this->totElem; i++) {
                out += std::to_string(this->arr[i]) + " ";
            }

            return out + "]\n";
        }


};
