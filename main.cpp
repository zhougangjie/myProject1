#include <iostream>
#include <vector>
#include "solution.h"

int main() {
    std::vector<int> nums = {1, 1, 2};
    std::vector<int> nums2 = {3, 2, 2, 3};
    Solution solution;
    std::cout << solution.removeDuplicates(nums) << std::endl;
    std::cout << solution.removeElement(nums2, 3) << std::endl;
    std::cout << "best child string:"<< solution.maxLengthBetweenEqualCharacters("mgntdygtxrvxjnwksqhxuxtrv") << std::endl;
    return 0;
}
