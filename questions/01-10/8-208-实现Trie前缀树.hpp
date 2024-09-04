#pragma once

#include <iostream>
#include <vector>
#include <string>

class Trie {
private:
    std::vector<Trie *> cl;
    bool isEnd = false;

public:
    Trie() : cl(26, nullptr) {}

    void insert(std::string word) {
        auto ptr = this;
        for (auto c: word) {
            if (ptr->cl[c - 'a']) {
                ptr = ptr->cl[c - 'a'];
            } else {
                auto temp = new Trie;
                ptr->cl[c - 'a'] = temp;
                ptr = ptr->cl[c - 'a'];
            }
        }
        ptr->isEnd = true;
    }

    bool search(std::string word) {
        auto ptr = this;
        for (auto c: word) {
            if (ptr->cl[c - 'a']) {
                ptr = ptr->cl[c - 'a'];
            } else {
                return false;
            }
        }
        return ptr->isEnd;
    }

    bool startsWith(std::string prefix) {
        auto ptr = this;
        for (auto c: prefix) {
            if (ptr->cl[c - 'a']) {
                ptr = ptr->cl[c - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void check208() {
    Trie tt;
    tt.insert("abcd");
    tt.insert("abd");

}