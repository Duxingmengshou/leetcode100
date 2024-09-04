#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

class MinStack {
private:
    std::vector<int> vv;
    int min = INT64_MIN;
public:
    MinStack() {}

    void push(int val) {
        vv.emplace_back(val);
    }

    void pop() {
        vv.pop_back();
    }

    int top() {
        return vv.back();
    }

    int getMin() {
        return *std::min_element(vv.begin(), vv.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

void check155() {
    //"getMin","pop","getMin","pop","getMin","pop","getMin"
    MinStack ms;
    ms.push(2);
    ms.push(0);
    ms.push(3);
    ms.push(0);

    std::cout << ms.getMin() << std::endl;
    ms.pop();
    std::cout << ms.getMin() << std::endl;
    ms.pop();
    std::cout << ms.getMin() << std::endl;
    ms.pop();
    std::cout << ms.getMin() << std::endl;

}