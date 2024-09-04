#pragma once

#include <vector>
#include "../header/ListNode.hpp"

/*
 *
    ListNode* frontPointer;

    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {//递归
                return false;
            }
            if (currentNode->val != frontPointer->val) {//使用递归栈
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
 *
 * */


bool isPalindrome(ListNode *head) {
    std::vector<int> vv;
    while (head) {
        vv.emplace_back(head->val);
        head = head->next;
    }
    for (int i = 0; i < vv.size() / 2; i++) {
        if (vv[i] != vv[vv.size() - i - 1]) {
            return false;
        }
    }
    return true;
}