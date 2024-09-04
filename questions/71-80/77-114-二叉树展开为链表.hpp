#pragma once

#include "../header/TreeNode.hpp"


void dfs114(TreeNode *ptr, TreeNode *&prev) {
    if (ptr) {
        dfs114(ptr->right, prev);
        dfs114(ptr->left, prev);
        ptr->right = prev;
        ptr->left = nullptr;
        prev = ptr;
    }
}

void flatten(TreeNode *root) {
    TreeNode *prev = nullptr; // 用于跟踪前一个节点
    dfs114(root, prev);
}


void check114() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    a->left = b, a->right = e;
    b->left = c, b->right = d;
    e->right = f;
    flatten(a);

}