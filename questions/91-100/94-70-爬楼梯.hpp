#pragma once

#include <iostream>

//直接搜索，超时
//void dfs70(int n, int &res) {
//    if (n == 0) {
//        res++;
//        return;
//    }
//    for (int i = 1; i <= 2; i++) {
//        if (n - i >= 0)
//            dfs70(n - i, res);
//    }
//}
//
//int climbStairs(int n) {
//    int res = 0;
//    dfs70(n, res);
//    return res;
//}
int climbStairs(int n) {
    //类似于斐波那契
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int l1 = 1, l2 = 2;
    int q = 0;
    for (int i = 3; i <= n; ++i) {
        q = l1 + l2;
        l1 = l2;
        l2 = q;
    }
    return q;
}

void check70() {
    climbStairs(3);
}