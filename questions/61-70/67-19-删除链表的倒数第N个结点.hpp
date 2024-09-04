#pragma once

#include "../header/ListNode.hpp"

//递归栈
void foo19(ListNode *head, int &n) {
    if (!head)
        return;

    foo19(head->next, n);
    n--;
    if (n == -1) {
        if (head->next)
            head->next = head->next->next;
    }
    if (n < -1)
        return;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *root = new ListNode(-1);
    root->next = head;
    foo19(root, n);
    return root->next;
}

void check19() {
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

    d->next = e;
    removeNthFromEnd(a, 7);
}