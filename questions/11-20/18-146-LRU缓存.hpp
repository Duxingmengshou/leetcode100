#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>

class LRUCache {
private:
    int Capacity;
    std::list<int> order;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;

public:
    LRUCache(int capacity) : Capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        order.erase(it->second.second);
        order.push_front(key);
        it->second.second = order.begin();
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            order.erase(it->second.second);
            order.push_front(key);
            cache[key] = {value, order.begin()};
        } else {
            if (cache.size() == Capacity) {
                int lru = order.back();
                order.pop_back();
                cache.erase(lru);
            }
            order.push_front(key);
            cache[key] = {value, order.begin()};
        }
    }
};

void check146() {

    //[[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
    LRUCache lruCache(2);
    lruCache.put(1, 1);
    std::cout << lruCache.get(2) << std::endl;
    lruCache.put(2, 6);
    std::cout << lruCache.get(1) << std::endl;
    lruCache.put(1, 5);
    lruCache.put(1, 2);
    std::cout << lruCache.get(1) << std::endl;
    std::cout << lruCache.get(2) << std::endl;
}