//
// Created by gangjie on 2021/10/25.
//

#include <vector>
#include <string>

#ifndef MYPROJECT1_SOLUTION_H
#define MYPROJECT1_SOLUTION_H
class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums);
    int removeElement(std::vector<int>& nums, int val);
    int maxLengthBetweenEqualCharacters(std::string s);
    int searchInsert(std::vector<int>& nums, int target);
    std::vector<int> getConcatenation(std::vector<int>& nums);
    bool containsDuplicate(std::vector<int>& nums);
    int maxSubArray(std::vector<int>& nums);
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
    int maxProfit(std::vector<int>& prices);
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c);
    std::vector<std::vector<int>> generate(int numRows);
    bool isValidSudoku(std::vector<std::vector<char>>& board);
    int lengthOfLastWord(std::string s);
    std::vector<int> plusOne(std::vector<int>& digits);
};


#endif //MYPROJECT1_SOLUTION_H
