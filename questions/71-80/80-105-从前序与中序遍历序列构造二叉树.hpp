#pragma once

#include <vector>
#include <stack>
#include "../header/TreeNode.hpp"

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (!preorder.size()) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    std::stack<TreeNode *> stk;
    stk.push(root);
    int inorderIndex = 0;
    for (int i = 1; i < preorder.size(); ++i) {
        int preorderVal = preorder[i];
        TreeNode *node = stk.top();
        if (node->val != inorder[inorderIndex]) {
            node->left = new TreeNode(preorderVal);
            stk.push(node->left);
        } else {
            while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                node = stk.top();
                stk.pop();
                ++inorderIndex;
            }
            node->right = new TreeNode(preorderVal);
            stk.push(node->right);
        }
    }
    return root;
}