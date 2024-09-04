#pragma once

#include "../header/ListNode.hpp"


bool foo141(ListNode *head, int &i) {
    if (head == nullptr) {
        return false;
    }
    i++;
    if (i > 10000)
        return true;
    return foo141(head->next, i);
}


bool hasCycle(ListNode *head) {
    int i = 0;
    return foo141(head, i);
}