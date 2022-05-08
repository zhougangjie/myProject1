#include <iostream>
#include <vector>
#include "solution.h"

int main() {
    std::vector<int> nums = {1, 1, 2};
    std::vector<int> nums2 = {3, 2, 2, 3};
    Solution solution;
//    std::cout << solution.removeDuplicates(nums) << std::endl;
//    std::cout << solution.removeElement(nums2, 3) << std::endl;
//    std::cout << "best child string:"<< solution.maxLengthBetweenEqualCharacters("mgntdygtxrvxjnwksqhxuxtrv") << std::endl;

//    std::vector<int> nums3 = {1,3};
//    std::cout << "searchInsert:" << solution.searchInsert(nums3, 1);
//
//    std::vector<int> num4 = {-2};
//    std::cout << "maxSubArray " << solution.maxSubArray(num4);

//    std::vector<int> num5 = {4,9,5};
//    std::vector<int> num6 = {9,4,9,8,4};
//    solution.intersect(num5, num6);

//    std::vector<int> num7 = {7, 1, 5, 3, 6, 4};
//    std::cout << "maxProfit" << solution.maxProfit(num7);
    
//    std::vector<std::vector<char>> board = {{'.','.','5','.','.','.','.','.','6'},
//                                            {'.','.','.','.','1','4','.','.','.'},
//                                            {'.','.','.','.','.','.','.','.','.'},
//                                            {'.','.','.','.','.','9','2','.','.'},
//                                            {'5','.','.','.','.','2','.','.','.'},
//                                            {'.','.','.','.','.','.','.','3','.'},
//                                            {'.','.','.','5','4','.','.','.','.'},
//                                            {'3','.','.','.','.','.','4','2','.'},
//                                            {'.','.','.','2','7','.','6','.','.'}};
//    std::cout<< "isValidSudoku: " << solution.isValidSudoku(board);
//    std::cout << "lengthOfLastWord: " << solution.lengthOfLastWord(" kajsld kk kdajksd  kjda d");

    std::vector<int> test_plus_one {9,9,9};
    solution.plusOne(test_plus_one);
    return 0;
}
