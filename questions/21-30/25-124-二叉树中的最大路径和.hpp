#pragma once

#include <iostream>
#include "../header/TreeNode.hpp"

void foo124(TreeNode *ptr, int &cuMax, int &res) {
    if (!ptr)
        return;

    int lmax{}, rmax{};
    foo124(ptr->left, lmax, res);
    foo124(ptr->right, rmax, res);
    lmax = lmax > 0 ? lmax : 0;
    rmax = rmax > 0 ? rmax : 0;

    cuMax = lmax + ptr->val + rmax;
    res = cuMax > res ? cuMax : res;

    cuMax = ptr->val + std::max(lmax, rmax);
}


int maxPathSum(TreeNode *root) {
    int res = INT_MIN, cuMax = INT_MIN;
    foo124(root, cuMax, res);
    std::cout << res << std::endl;
    return res;
}


void check124() {
    //[-10,9,20,null,null,15,7]
    TreeNode *a = new TreeNode(-10);
    TreeNode *b = new TreeNode(-9);
    TreeNode *c = new TreeNode(20);
    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);

    a->left = b;
//    a->right = c;
//    c->left = d;
//    c->right = e;

    maxPathSum(a);

}