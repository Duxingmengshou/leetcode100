#pragma once

#include <cstdio>
#include "../header/ListNode.hpp"


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    ListNode *res = nullptr;
    ListNode *tempA = headA, *tempB = headB;
    while (tempA != tempB) {
        tempA = tempA == nullptr ? headB : tempA->next;
        tempB = tempB == nullptr ? headA : tempB->next;
    }
    return tempA;
}


void check160() {
    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode(2);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(4);

    a->next = b;
    b->next = d;
    d->next = e;
//    c->next = d;
    e->next = nullptr;
    c->next = nullptr;
    if (getIntersectionNode(a, c) == nullptr)
        printf("nullptr\n");
    else
        printf("%d\n", getIntersectionNode(a, c)->val);
}
