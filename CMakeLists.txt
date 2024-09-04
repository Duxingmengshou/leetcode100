cmake_minimum_required(VERSION 3.26)
project(LeetCode100)

set(CMAKE_CXX_STANDARD 17)

add_executable(LeetCode100
        main.cpp

        questions/prerequisites/check.hpp
        questions/prerequisites/matrix.hpp
        questions/prerequisites/baseSort/baseSort.hpp

        questions/header/TreeNode.hpp
        questions/header/ListNode.hpp

        questions/header/UniqueSkills.hpp


        questions/01-10/1-160-相交链表.hpp
        questions/01-10/2-236-最近公共祖先.hpp
        questions/01-10/3-234-回文链表.hpp
        questions/01-10/4-739-每日温度.hpp
        questions/01-10/5-226-翻转二叉树.hpp
        questions/01-10/6-221-最大正方形.hpp
        questions/01-10/7-215-数组中的第K个最大元素.hpp
        questions/01-10/8-208-实现Trie前缀树.hpp
        questions/01-10/9-207-课程表.hpp
        questions/01-10/10-206-反转链表.hpp

        questions/11-20/11-200-岛屿数量.hpp
        questions/11-20/12-198-打家劫舍.hpp
        questions/11-20/13-169-多数元素.hpp
        questions/11-20/14-238-除自身以外数组的乘积.hpp
        questions/11-20/15-155-最小栈.hpp
        questions/11-20/16-152-乘积最大子数组.hpp
        questions/11-20/17-148-排序链表.hpp
        questions/11-20/18-146-LRU缓存.hpp
        questions/11-20/19-142-环形链表II.hpp
        questions/11-20/20-141-环形链表.hpp

        questions/21-30/21-139-单词拆分.hpp
        questions/21-30/22-136-只出现一次的数字.hpp
        questions/21-30/23-647-回文子串.hpp
        questions/21-30/24-128-最长连续序列.hpp
        questions/21-30/25-124-二叉树中的最大路径和.hpp
        questions/21-30/26-322-零钱兑换.hpp
        questions/21-30/27-494-目标和.hpp
        questions/21-30/28-461-汉明距离.hpp
        questions/21-30/29-448-找到所有数组中消失的数字.hpp
        questions/21-30/30-438-找到字符串中所有字母异位词.hpp

        questions/31-40/31-437-路径总和III.hpp
        questions/31-40/32-416-分割等和子集.hpp
        questions/31-40/33-406-根据身高重建队列.hpp
        questions/31-40/34-399-除法求值.hpp
        questions/31-40/35-394-字符串解码.hpp
        questions/31-40/36-347-前K个高频元素.hpp
        questions/31-40/37-338-比特位计数.hpp
        questions/31-40/38-337-打家劫舍III.hpp
        questions/31-40/39-121-买卖股票的最佳时机.hpp
        questions/31-40/40-312-戳气球.hpp

        questions/41-50/41-309-买卖股票的最佳时机含冷冻期.hpp
        questions/41-50/42-301-删除无效的括号.hpp
        questions/41-50/43-300-最长递增子序列.hpp
        questions/41-50/44-297-二叉树的序列化与反序列化.hpp
        questions/41-50/45-287-寻找重复数.hpp
        questions/41-50/46-283-移动零.hpp
        questions/41-50/47-279-完全平方数.hpp
        questions/41-50/48-253-会议室II.hpp
        questions/41-50/49-240-搜索二维矩阵II.hpp
        questions/41-50/50-239-滑动窗口最大值.hpp

        questions/51-60/51-22-括号生成.hpp
        questions/51-60/52-49-字母异位词分组.hpp
        questions/51-60/53-48-旋转图像.hpp
        questions/51-60/54-46-全排列.hpp
        questions/51-60/55-42-接雨水.hpp
        questions/51-60/56-39-组合总和.hpp
        questions/51-60/57-543-二叉树的直径.hpp
        questions/51-60/58-34-在排序数组中查找元素的第一个和最后一个位置.hpp
        questions/51-60/59-33-搜索旋转排序数组.hpp
        questions/51-60/60-32-最长有效括号.hpp

        questions/61-70/61-31-下一个排列.hpp
        questions/61-70/62-538-把二叉搜索树转换为累加树.hpp
        questions/61-70/63-23-合并K个升序链表.hpp
        questions/61-70/64-560-和为K的子数组.hpp
        questions/61-70/65-21-合并两个有序链表.hpp
        questions/61-70/66-20-有效的括号.hpp
        questions/61-70/67-19-删除链表的倒数第N个结点.hpp
        questions/61-70/68-17-电话号码的字母组合.hpp
        questions/61-70/69-15-三数之和.hpp
        questions/61-70/70-11-盛最多水的容器.hpp

        questions/71-80/71-10-正则表达式匹配.hpp
        questions/71-80/72-5-最长回文子串.hpp
        questions/71-80/73-4-寻找两个正序数组的中位数.hpp
        questions/71-80/74-3-无重复字符的最长子串.hpp
        questions/71-80/75-2-两数相加.hpp
        questions/71-80/76-79-单词搜索.hpp
        questions/71-80/77-114-二叉树展开为链表.hpp
        questions/71-80/78-621-任务调度器.hpp
        questions/71-80/79-617-合并二叉树.hpp
        questions/71-80/80-105-从前序与中序遍历序列构造二叉树.hpp

        questions/81-90/81-104-二叉树的最大深度.hpp
        questions/81-90/82-102-二叉树的层序遍历.hpp
        questions/81-90/83-101-对称二叉树.hpp
        questions/81-90/84-98-验证二叉搜索树.hpp
        questions/81-90/85-96-不同的二叉搜索树.hpp
        questions/81-90/86-94-二叉树的中序遍历.hpp
        questions/81-90/87-85-最大矩形.hpp
        questions/81-90/88-84-柱状图中最大的矩形.hpp
        questions/81-90/89-1-两数之和.hpp
        questions/81-90/90-78-子集.hpp

        questions/91-100/91-76-最小覆盖子串.hpp
        questions/91-100/92-75-颜色分类.hpp
        questions/91-100/93-72-编辑距离.hpp
        questions/91-100/94-70-爬楼梯.hpp
        questions/91-100/95-581-最短无序连续子数组.hpp
        questions/91-100/96-64-最小路径和.hpp
        questions/91-100/97-62-不同路径.hpp
        questions/91-100/98-56-合并区间.hpp
        questions/91-100/99-55-跳跃游戏.hpp
        questions/91-100/100-53-最大子数组和.hpp
)
