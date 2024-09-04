#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "../header/ListNode.hpp"


ListNode *sortList(ListNode *head) {
    auto ptr = head;
    std::vector<int> vv;
    while (ptr) {
        vv.emplace_back(ptr->val);
        ptr = ptr->next;
    }
    std::sort(vv.begin(), vv.end());
    ptr = head;
    int i = 0;
    while (ptr) {
        ptr->val = vv[i++];
        ptr = ptr->next;
    }
    return head;
}