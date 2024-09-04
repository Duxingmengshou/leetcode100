#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "../header/ListNode.hpp"


ListNode *detectCycle(ListNode *head) {
    auto ptr = head;
    std::unordered_set<ListNode *> mm;

    while (ptr) {
        auto itr = mm.find(ptr);
        if (itr == mm.end()) {
            mm.insert(ptr);
        } else {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;

}


void check142() {
    //[3,2,0,-4]
    ListNode *a = new ListNode(3);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(-4);
    ListNode *d = new ListNode(-4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    std::cout << detectCycle(a)->val << std::endl;
}