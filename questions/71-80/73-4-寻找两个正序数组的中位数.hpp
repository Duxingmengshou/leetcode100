#pragma once

#include <vector>
#include <iostream>


//暴力解了
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> tmp(nums1.size() + nums2.size());
    if ((nums1.size() + nums2.size()) % 2 == 0) {
        int l = (nums1.size() + nums2.size()) / 2 - 1;
        int r = l + 1;
        int i, j, k;
        for (i = 0, j = 0, k = 0;
             i <= r && j < nums1.size() && k < nums2.size();
             i++) {
            if (nums1[j] < nums2[k]) {
                tmp[i] = nums1[j++];
            } else {
                tmp[i] = nums2[k++];
            }
        }
        if (i - 1 == r) {
            return (tmp[l] + tmp[r]) / 2.;
        } else {
            while (j < nums1.size()) {
                tmp[i] = nums1[j++];
                if (i == r) {
                    return (tmp[l] + tmp[r]) / 2.;
                }
                i++;
            }
            while (k < nums2.size()) {
                tmp[i] = nums2[k++];
                if (i == r) {
                    return (tmp[l] + tmp[r]) / 2.;
                }
                i++;
            }
        }
    } else {
        int m = (nums1.size() + nums2.size()) / 2;
        int i, j, k;
        for (i = 0, j = 0, k = 0;
             i <= m && j < nums1.size() && k < nums2.size();
             i++) {
            if (nums1[j] < nums2[k]) {
                tmp[i] = nums1[j++];
            } else {
                tmp[i] = nums2[k++];
            }
        }
        if (i - 1 == m) {
            return tmp[m];
        } else {
            while (j < nums1.size()) {
                tmp[i] = nums1[j++];
                if (i == m) {
                    return tmp[m];
                }
                i++;
            }
            while (k < nums2.size()) {
                tmp[i] = nums2[k++];
                if (i == m) {
                    return tmp[m];
                }
                i++;
            }
        }
    }
}


void check4() {
    std::vector<int> v1{1, 2}, v2{3,4};
    std::cout << findMedianSortedArrays(v1, v2);
}
