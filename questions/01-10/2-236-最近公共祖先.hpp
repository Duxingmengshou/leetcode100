#pragma once

#include <queue>
#include <map>
#include <vector>
#include "../header/TreeNode.hpp"

bool isCA(TreeNode *root, TreeNode *p, TreeNode *q) {
    std::queue<TreeNode *> qq;
    qq.push(root);
    bool isq = false, isp = false;
    while (!qq.empty()) {
        auto temp = qq.front();
        qq.pop();
        if (temp->val == p->val) {
            isp = true;
        }
        if (temp->val == q->val) {
            isq = true;
        }
        if (isp && isq)
            return true;
        if (temp->left) {
            qq.push(temp->left);
        }
        if (temp->right) {
            qq.push(temp->right);
        }
    }
    return isp && isq;

}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
//    if (p->val == root->val || q->val == root->val) {
//        return root;
//    }
//    auto lastNode = root;
//    std::queue<TreeNode *> qq;
//    qq.push(root);
//    while (!qq.empty()) {
//        auto temp = qq.front();
//        qq.pop();
//        if (isCA(temp, p, q)) {
//            lastNode = temp;
//            if (temp->left) {
//                qq.push(temp->left);
//            }
//            if (temp->right) {
//                qq.push(temp->right);
//            }
//        }
//    }
//    return lastNode;
    if(root == nullptr || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left == nullptr) return right;
    if(right == nullptr) return left;
    return root;
}
