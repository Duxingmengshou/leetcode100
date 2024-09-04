#pragma once

#include <vector>
#include <string>

void dfs22(std::vector<std::string> &v, int ln, int rn, std::string str) {
    if (ln < 0 || rn < 0)
        return;
    if (ln == 0 && rn == 0) {
        v.push_back(str);
        return;
    }
    if (ln == rn) {
        dfs22(v, ln - 1, rn, str + '(');
    } else if (ln < rn) {
        dfs22(v, ln - 1, rn, str + '(');
        dfs22(v, ln, rn - 1, str + ')');
    } else {
        return;
    }

}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    std::string str;
    dfs22(res, n, n, str);

    return res;
}

void check22() {
    generateParenthesis(3);
}