#pragma once

#include <iostream>
#include "../header/ListNode.hpp"

void foo21(ListNode *list1, ListNode *list2, ListNode *ptr) {
    if (!list1 && !list2) {
        return;
    }
    if (!list1) {
        ptr->next = list2;
        ptr = ptr->next;
        foo21(list1, list2->next, ptr);
        return;
    }
    if (!list2) {
        ptr->next = list1;
        ptr = ptr->next;
        foo21(list1->next, list2, ptr);
        return;
    }
    if (list1->val < list2->val) {
        ptr->next = list1;
        ptr = ptr->next;
        foo21(list1->next, list2, ptr);
        return;
    } else {
        ptr->next = list2;
        ptr = ptr->next;
        foo21(list1, list2->next, ptr);
        return;
    }

}


ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *root = new ListNode(-1);
    auto ptr = root;
    foo21(list1, list2, ptr);
    return root->next;
}

void check21() {
    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(6);

    a->next = b;
    b->next = c;
    c->next = d;


    ListNode *e = new ListNode(2);
    ListNode *f = new ListNode(5);
    ListNode *g = new ListNode(8);

    e->next = f;
    f->next = g;

    mergeTwoLists(a, e);
}