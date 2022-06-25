//
// Created by fsindustry on 2022/6/23.
//

#ifndef LISZT_CXX_ARRAYUTILS_H
#define LISZT_CXX_ARRAYUTILS_H

#include "vector"
#include "string"

class ArrayUtils {
public:
    template<typename T>
    std::string toString(std::vector<T> arr);
};

#endif //LISZT_CXX_ARRAYUTILS_H
