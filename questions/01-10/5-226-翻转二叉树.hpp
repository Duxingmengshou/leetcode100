

#pragma once


#include "../header/TreeNode.hpp"


TreeNode *invertTree(TreeNode *root) {
    if (root) {
        auto temp = root->right;
        root->right = root->left;
        root->left = temp;
    } else {
        return nullptr;
    }

    invertTree(root->left);
    invertTree(root->right);
    return root;
}