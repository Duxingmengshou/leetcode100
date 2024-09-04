#pragma once

#include <vector>
#include <stack>
#include <string>


bool isValid(std::string s) {
    std::stack<char> st;
    for (auto &c: s) {
        st.push(c);
        if (st.top() == ')') {
            st.pop();
            if (st.empty())
                return false;
            if (st.top() == '(')
                st.pop();
            else
                return false;
            continue;
        }
        if (st.top() == ']') {
            st.pop();
            if (st.empty())
                return false;
            if (st.top() == '[')
                st.pop();
            else
                return false;
            continue;
        }
        if (st.top() == '}') {
            st.pop();
            if (st.empty())
                return false;
            if (st.top() == '{')
                st.pop();
            else
                return false;
            continue;
        }
    }
    return st.empty();
}