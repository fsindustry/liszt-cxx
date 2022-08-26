#include <iostream>
#include "util/ArrayUtils.h"

int main() {
    ArrayUtils utils;
    std::vector<int> arr = {1, 2};
    std::cout << "Input: arr = " << utils.print(arr) << std::endl;
    utils.swap(arr, 0, 1);
    std::cout << "Output: arr = " << utils.print(arr) << std::endl;
    return 0;
}
