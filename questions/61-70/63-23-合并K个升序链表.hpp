#pragma once

#include <vector>
#include <set>
#include "../header/ListNode.hpp"

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    std::multiset<int> ress;
    for (auto &c: lists) {
        auto ptr = c;
        while (ptr) {
            ress.insert(ptr->val);
            ptr = ptr->next;
        }
    }

    if (ress.empty())
        return nullptr;
    // 创建一个虚拟头节点，方便构建结果链表
    ListNode *root = new ListNode(0);
    ListNode *current = root;

    // 遍历multiset，构建结果链表
    for (int val: ress) {
        current->next = new ListNode(val);
        current = current->next;
    }

    // 返回合并后的链表，去掉虚拟头节点
    return root->next;

}