#pragma once

#include <iostream>
#include "../header/ListNode.hpp"

//经典的合并
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    int x = 0;
    ListNode *root = new ListNode(-1);
    auto ptr = root;
    while (l1 && l2) {
        auto tmp = l1->val + l2->val + x;
        if (tmp >= 10) {
            x = tmp / 10;
            ptr->next = new ListNode(tmp % 10);
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        } else {
            x = 0;
            ptr->next = new ListNode(tmp);
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    while (l1) {
        auto tmp = l1->val + x;
        if (tmp >= 10) {
            x = tmp / 10;
            ptr->next = new ListNode(tmp % 10);
            ptr = ptr->next;
            l1 = l1->next;
        } else {
            x = 0;
            ptr->next = new ListNode(tmp);
            ptr = ptr->next;
            l1 = l1->next;
        }
    }
    while (l2) {
        auto tmp = l2->val + x;
        if (tmp >= 10) {
            x = tmp / 10;
            ptr->next = new ListNode(tmp % 10);
            ptr = ptr->next;
            l2 = l2->next;
        } else {
            x = 0;
            ptr->next = new ListNode(tmp);
            ptr = ptr->next;
            l2 = l2->next;
        }
    }
    while (x) {
        if (x >= 10) {
            x = x / 10;
            ptr->next = new ListNode(x % 10);
            ptr = ptr->next;
        } else {
            ptr->next = new ListNode(x);
            x = 0;
            ptr = ptr->next;
        }
    }
    return root->next;
}