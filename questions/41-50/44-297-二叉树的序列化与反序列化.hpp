#pragma once

#include <string>
#include <queue>
#include <iostream>
#include <sstream>
#include "../header/TreeNode.hpp"

// Encodes a tree to a single string.
std::string serialize(TreeNode *root) {
    if (!root)
        return "[]";
    auto isNum = [](char c) {
        return c >= '0' && c <= '9';
    };

    std::queue<TreeNode *> qq;
    qq.push(root);
    std::string res = "[";
    while (!qq.empty()) {
        auto tmp = qq.front();
        qq.pop();
        if (!tmp) {
            res += "null,";
            continue;
        } else {
            res += std::to_string(tmp->val);
            res += ',';
            qq.push(tmp->left);
            qq.push(tmp->right);
        }
    }
    int i = res.size() - 1;
    for (; i >= 0; i--) {
        if (isNum(res[i]))
            break;

    }
    if (i == res.size() - 1) {
        res += ']';
    } else {
        res = res.substr(0, i + 1);
        res += ']';
    }
    return res;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(std::string data) {
    if (data == "[]")
        return nullptr;

    data = data.substr(1, data.size() - 2); // 去掉开头和结尾的方括号
    std::queue<std::string> qq;
    std::stringstream ss(data);
    std::string token;

    // 将每个分割出的字符串存入队列
    while (std::getline(ss, token, ',')) {
        qq.push(token);
    }

    if (qq.front() == "null") {
        return nullptr;
    }

    // 创建根节点
    TreeNode *root = new TreeNode(std::stoi(qq.front()));
    qq.pop();

    std::queue<TreeNode *> nodeQueue; // 用于层序遍历构建树
    nodeQueue.push(root);

    while (!qq.empty()) {
        TreeNode *current = nodeQueue.front();
        nodeQueue.pop();

        // 左子节点
        if (!qq.empty()) {
            token = qq.front();
            qq.pop();
            if (token != "null") {
                current->left = new TreeNode(std::stoi(token));
                nodeQueue.push(current->left);
            }
        }

        // 右子节点
        if (!qq.empty()) {
            token = qq.front();
            qq.pop();
            if (token != "null") {
                current->right = new TreeNode(std::stoi(token));
                nodeQueue.push(current->right);
            }
        }
    }

    return root;
}


void check297() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);

//    a->left = b;
//    a->right = c;
//    c->left = d;
//    c->right = e;

    std::cout << serialize(deserialize(serialize(a))) << std::endl;
//    serialize(deserialize(serialize(a)));
}