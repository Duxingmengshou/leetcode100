//
// Created by _thinkPad on 2024/8/25.
//

#ifndef LEETCODE100_BASESORT_HPP
#define LEETCODE100_BASESORT_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class baseSort {
public:

    template<class iterator, class comp>
    static void select_sort(const iterator &begin, const iterator &end, comp &com) {
        if (begin == end)
            return;
        auto select = [com](const iterator &begin, const iterator &end) {
            if (begin == end)
                return begin;
            auto tmp = begin;
            for (auto itr = begin + 1; itr != end; itr++) {
                if (com(*itr, *tmp))
                    tmp = itr;
            }
            return tmp;
        };

        for (auto itr = begin; itr != end; itr++) {
            auto tmp = std::move(*itr);
            auto ptr = select(itr, end);
            *itr = std::move(*ptr);
            *ptr = std::move(tmp);
        }
    }


    template<class iterator, class comp>
    static void insert_sort(const iterator &begin, const iterator &end, comp &com) {
        if (begin == end)
            return;
        for (auto itr = begin + 1; itr != end; itr++) {
            auto tmp = std::move(*itr);
            auto jtr = itr;
            for (; jtr > begin && com(tmp, *(jtr - 1)); jtr--)
                *jtr = std::move(*(jtr - 1));
            *jtr = std::move(tmp);
        }
    }

    template<class iterator, class comp>
    static void shell_sort(const iterator &begin, const iterator &end, comp &com) {
        if (begin == end)
            return;

        auto distance = std::distance(begin, end);
        for (auto gap = distance / 2; gap > 0; gap /= 2)
            for (auto itr = begin + gap; itr != end; itr++) {
                auto tmp = std::move(*itr);
                auto jtr = itr;
                for (; jtr >= begin + gap && com(tmp, *(jtr - gap)); jtr -= gap)
                    *jtr = std::move(*(jtr - gap));
                *jtr = std::move(tmp);
            }
    }


    template<class iterator, class comp>
    static void heap_sort(const iterator &begin, const iterator &end, comp &com) {
        auto lci = [](int i) {
            return 2 * i + 1;
        };
        auto rci = [lci](int i) {
            return 2 * i + 2;
        };
        auto lastNotLeaf = [](int size) {
            return size > 2 ? (size - 2) / 2 : 0;
        };
        int size = std::distance(begin, end);
        auto heapify =
                [&com, &lastNotLeaf, &rci, &lci]
                        (const iterator &begin, int size) {
                    for (int i = lastNotLeaf(size); i >= 0; i--) {
                        int maxi = i;
                        auto max = *(begin + i);
                        if (lci(i) < size && com(max, *(begin + lci(i)))) {
                            maxi = lci(i);
                            max = *(begin + lci(i));
                        }
                        if (rci(i) < size && com(max, *(begin + rci(i)))) {
                            maxi = rci(i);
                        }
                        if (maxi != i) {
                            std::swap(*(begin + i), *(begin + maxi));
                        }
                    }
                };
        for (int j = size; j >= 1; j--) {
            heapify(begin, j);
            std::swap(*(begin), *(begin + j - 1));
        }
    }


    template<class iterator, class comp>
    static void merge_sort(const iterator &begin, const iterator &end, comp &com) {
        auto merge = [](const iterator &begin, const iterator &middle, const iterator &end, comp &com) {
            std::vector<typename std::iterator_traits<iterator>::value_type> tmp(std::distance(begin, end));
            auto itr = begin, jtr = middle;
            int i = 0;
            while (itr != middle && jtr != end) {
                tmp[i++] = com(*itr, *jtr) ? *(itr++) : *(jtr++);
            }
            while (itr != middle) {
                tmp[i++] = *(itr++);
            }
            while (jtr != end) {
                tmp[i++] = *(jtr++);
            }
            std::move(tmp.begin(), tmp.end(), begin);
        };
        if (begin == end)
            return;
        if (std::distance(begin, end) <= 1)
            return;
        iterator mid = begin + std::distance(begin, end) / 2;
        merge_sort(begin, mid, com);
        merge_sort(mid, end, com);
        merge(begin, mid, end, com);
    }

    template<class iterator, class comp>
    static void quick_sort(const iterator &begin, const iterator &end, comp &com) {
        if (std::distance(begin, end) <= 1)
            return;
        auto middleItr = begin + std::distance(begin, end) / 2;
        std::vector<typename std::iterator_traits<iterator>::value_type> l, m, r;
        for (auto itr = begin; itr != end; itr++) {
            if (com(*itr, *middleItr)) {
                l.emplace_back(std::move(*itr));
            } else if (*itr == *middleItr) {
                m.emplace_back(std::move(*itr));
            } else {
                r.emplace_back(std::move(*itr));
            }
        }
        quick_sort(l.begin(), l.end(), com);
        quick_sort(r.begin(), r.end(), com);
        std::move(l.begin(), l.end(), begin);
        std::move(m.begin(), m.end(), begin + l.size());
        std::move(r.begin(), r.end(), end - r.size());
    }
};


#endif //LEETCODE100_BASESORT_HPP
