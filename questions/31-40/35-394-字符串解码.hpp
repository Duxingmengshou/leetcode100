#pragma once


#include <string>
#include <stack>
#include <iostream>
#include <deque>


//std::string decodeString(std::string s) {
//    std::stack<char> st;
//    for (auto c: s) {
//        st.push(c);
//        if (st.top() == ']') {
//            st.pop();
//            std::stack<char> tmpst;
//            while (st.top() != '[') {
//                tmpst.push(st.top());
//                st.pop();
//            }
//            st.pop();
//            int size = st.top() - '0';
//            st.pop();
//            for (int i = 0; i < size; i++) {
//                auto tmp = tmpst;
//                while (!tmp.empty()) {
//                    st.push(tmp.top());
//                    tmp.pop();
//                }
//            }
//        }
//    }
//
//    std::string str;
//    while (!st.empty()) {
//        str += st.top();
//        st.pop();
//    }
//    return str;
//
//}

std::string decodeString(std::string s) {
    auto isNums = [](char c) {
        return c >= '0' && c <= '9';
    };
    auto power10 = [](int i) {
        if (i == 0)
            return 1;
        else {
            int res = 10;
            for (; i > 1; i--)
                res *= 10;
            return res;
        }
    };
    std::deque<char> qt;
    for (auto c: s) {
        qt.push_back(c);
        if (qt.back() == ']') {
            qt.pop_back();
            std::deque<char> tmpqt;
            while (qt.back() != '[') {
                tmpqt.push_back(qt.back());
                qt.pop_back();
            }
            qt.pop_back();
            int size = 0, i = 0;
            while (!qt.empty() && isNums(qt.back())) {
                size += (qt.back() - '0') * power10(i++);
                qt.pop_back();
            }

            std::cout << size << std::endl;

            for (int i = 0; i < size; i++) {
                for (int j = tmpqt.size() - 1; j >= 0; j--) {
                    qt.push_back(tmpqt.at(j));
                }
            }
        }
    }

    std::string str;
    while (!qt.empty()) {
        str += qt.front();
        qt.pop_front();
    }
    return str;

}


void check394() {
    std::string str = "3[a10[bc]]";
    std::cout << decodeString(str) << std::endl;
}