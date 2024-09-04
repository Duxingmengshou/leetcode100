#pragma once

#include "../header/ListNode.hpp"

ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    auto r = reverseList(head->next); // 后续的进行翻转
    head->next->next = head;          // 后续的后续应该是之前的
    head->next = nullptr;             // 后续是空
    return r;
}


void check206() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    auto tmp = reverseList(a);

}