#pragma once

#include <vector>
#include <iostream>


template<class T>
class matrix {
private:
    std::vector<std::vector<T>> mx;

public:
    matrix(int r, int c) {
        mx.resize(r);
        for (auto &mxx: mx)
            mxx.resize(c);
    }

    matrix(const std::vector<std::vector<T>> &vv) : mx(vv) {}

    matrix(const std::vector<std::vector<T>> &&vv) : mx(std::move(vv)) {}


    const std::vector<T> &operator[](const int &r) const {
        return mx[r];
    }

    std::vector<T> &operator[](const int &r) {
        return mx[r];
    }

    int numrows() const {
        return mx.size();
    }

    int numcols() const {
        return numrows() ? mx[0].size() : 0;
    }

    void print() {
        for (auto c: mx) {
            for (auto cc: c) {
                std::cout << cc << " ";
            }
            std::cout << "\n";
        }
    }
};