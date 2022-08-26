//
// Created by fsindustry on 6/27/22.
//

#ifndef LISZT_CXX_ARRAYUTILS_H
#define LISZT_CXX_ARRAYUTILS_H

#include <vector>
#include <sstream>


class ArrayUtils {

public:
    template<typename T>
    inline void swap(std::vector<T> &arr, int idx1, int idx2) {
        T tmp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = tmp;
    }

    template<typename T>
    inline std::string print(std::vector<T> &arr) {
        std::ostringstream res;
        if (arr.empty()) {
            return "[]";
        }

        res << "[" << arr[0];
        for (int i = 1; i < arr.size(); i++) {
            res << ", " << arr[i];
        }
        res << "]";
        return res.str();
    }
};


#endif //LISZT_CXX_ARRAYUTILS_H
