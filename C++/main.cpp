#include <bits/stdc++.h>
#include <vector>
#include "lists/list.hpp"
#include "lists/doubly-linked-list.hpp"
#include "lists/static-linked-list.hpp"
#include "lists/head-tail-linked-list.hpp"
#include "lists/linked-list.hpp"
#include "lists/static-list.hpp"

using namespace ::std;

void test_lists() {

    StaticList sl(10);
    StaticLinkedList sll(10);
    LinkedList ll;
    HTLinkedList htll;
    DoublyLinkedList dll;

    List *lists[] = {
        &sl,
        &sll,
        &ll,
        &htll,
        &dll,
    };
    
    for (List *l: lists) {
        testingList(*l);
    };
}

int main() {

    test_lists();
    return 0;
}