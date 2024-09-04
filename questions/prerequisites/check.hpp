#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include "matrix.hpp"
#include "base_sort/base_sort.hpp"

template<class iterator>
void fooPrint(const iterator &cbegin, const iterator &cend) {

    for (auto itr = cbegin; itr != cend; itr++) {
        std::cout << *itr << " ";
    }
    std::cout << "\n";
    return;
}


void fooCheck() {

    // fixed seed
    auto const seed = 123;
    // Mersenne Twister random engine:
    std::mt19937 urbg{seed};
    // generate random ints in [1,6]
    std::uniform_int_distribution<int> distribution{-10000, 10000};


    std::vector<int> v{};

    for (int i = 0; i < 10000; i++) {
        v.emplace_back(distribution(urbg));
    }


    std::vector<int> vv{v};

    std::chrono::system_clock::time_point start, end;

    start = std::chrono::system_clock::now();
    std::sort(vv.begin(), vv.end());
    end = std::chrono::system_clock::now();
    std::cout << "sort\t\t" << (end - start).count() << std::endl;

    base_sort bs;
    auto fff = [](auto c, auto b) { return c < b; };

//    start = std::chrono::system_clock::now();
//    bs.quick_sort(v.begin(), v.end(), fff);
//    end = std::chrono::system_clock::now();
//    std::cout << "quick_sort\t" << (end - start).count() << std::endl;//822892

    start = std::chrono::system_clock::now();
    bs.merge_sort(v.begin(), v.end(), fff);
    end = std::chrono::system_clock::now();
    std::cout << "quick_sort\t" << (end - start).count() << std::endl;//559290

//    start = std::chrono::system_clock::now();
//    bs.heap_sort(v.begin(), v.end(), fff);
//    end = std::chrono::system_clock::now();
//    std::cout << "quick_sort\t" << (end - start).count() << std::endl;//181710528

//    start = std::chrono::system_clock::now();
//    bs.shell_sort(v.begin(), v.end(), fff);
//    end = std::chrono::system_clock::now();
//    std::cout << "quick_sort\t" << (end - start).count() << std::endl;//1660099

//    start = std::chrono::system_clock::now();
//    bs.insert_sort(v.begin(), v.end(), fff);
//    end = std::chrono::system_clock::now();
//    std::cout << "quick_sort\t" << (end - start).count() << std::endl;//170396233

//    start = std::chrono::system_clock::now();
//    bs.select_sort(v.begin(), v.end(), fff);
//    end = std::chrono::system_clock::now();
//    std::cout << "quick_sort\t" << (end - start).count() << std::endl;//116589785
}