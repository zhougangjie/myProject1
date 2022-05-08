//
// Created by gangjie on 2021/10/25.
//
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <stack>
#include "solution.h"

int Solution::removeDuplicates(std::vector<int> &nums)
{
    int res = 0;
    if (nums.empty())
        return res;
    int i=1;
    while (i < nums.size())
    {
        if (nums[i] != nums[res])
            if (i-res>1)
                nums[++res] = nums[i++];
            else
            {
                i++;
                res++;
            }
        else
            i++;
    }
    return res+1;
}

int Solution::removeElement(std::vector<int> &nums, int val)
{
    int res = 0;
    if (nums.empty())
        return res;
    int i=0;
    while (i < nums.size())
    {
        if (nums[i] == val)
            i++;
        else
            nums[res++] = nums[i++];
    }
    return res++;
}

int Solution::maxLengthBetweenEqualCharacters(std::string s)
{
    std::map<char, int> char_location_map;
    std::array<int, 26> lengths;
    std::fill_n(lengths.begin(), 26, -1);

    for (int i = 0; i < s.size(); ++i)
    {
        if (char_location_map.find(s[i]) != char_location_map.end())
        {
            int new_len = i - char_location_map.at(s[i]) - 1;
            if (new_len > lengths[s[i] - 'a'])
            {
                lengths[s[i] - 'a'] = new_len;
            }
        }
        else
        {
            char_location_map.emplace(std::make_pair(s[i], i));
        }
    }
    return *std::max_element(lengths.begin(), lengths.end());
}

int Solution::searchInsert(std::vector<int>& nums, int target)
{
    int result=-1;
    int i=0,j=nums.size()-1;
    if (target > nums[j])
        return j+1;
    if(target <= nums[i])
        return i;
    while (i<j)
    {
        int next_pos = (i+j)/2;
        if (nums[next_pos] == target)
            return next_pos;
        if (next_pos == i)
            return i+1;
        else if (target > nums[next_pos])
            i = next_pos;
        else
            j = next_pos;
    }
    result = i+1;
    return result;
}

std::vector<int> Solution::getConcatenation(std::vector<int> &nums) {
    for (int num: nums) {
        nums.push_back(num);
    }
    return nums;
}

bool Solution::containsDuplicate(std::vector<int> &nums)
{
    std::set<int> unique_set;
    for (int i = 0; i < nums.size(); ++i) {
        if (unique_set.find(nums[i])!=unique_set.end()){
            return true;
        } else{
            unique_set.emplace(nums[i]);
        }
    }
    return false;
}

int Solution::maxSubArray(std::vector<int> &nums)
{
    int maxRes=INT32_MIN;
    int maxTemp=0;
    for (int i = 0; i < nums.size(); ++i) {
        maxTemp = nums[i];
        maxRes = std::max(maxTemp, maxRes);
        for (int j = i+1; j < nums.size() and maxTemp > 0; ++j) {
            maxTemp += nums[j];
            maxRes = std::max(maxTemp, maxRes);
            i=j-1;
        }
    }
    return maxRes;
}

std::vector<int> Solution::intersect(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::map<int, int> num1_index_map;
    std::map<int, int> num2_index_map;
    std::map<int, int> res_num_map;
    std::vector<int> res;
    for (int i = 0; i < nums1.size(); ++i) {
        if (num1_index_map.find(nums1[i])==num1_index_map.end())
            num1_index_map.emplace(std::make_pair(nums1[i], 1));
        else
            num1_index_map[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); ++i) {
        if (num2_index_map.find(nums2[i])==num2_index_map.end())
            num2_index_map.emplace(std::make_pair(nums2[i], 1));
        else
            num2_index_map[nums2[i]]++;
    }
    for (auto map1_itea = num1_index_map.begin(); map1_itea!=num1_index_map.end(); map1_itea++) {
        if (num2_index_map.find(map1_itea->first)!=num2_index_map.end())
            res_num_map.emplace(std::make_pair((map1_itea->first), std::max(map1_itea->second, num2_index_map.at(map1_itea->first))));
    }
    for (auto item: res_num_map) {
        for (int i = 0; i < item.second; ++i)
            res.push_back(item.first);
    }
    return res;
}

int Solution::maxProfit(std::vector<int> &prices)
{
    auto min_index = std::make_pair(INT32_MAX, 0);
    auto max_index = std::make_pair(INT32_MIN, 0);
    int res = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < min_index.first){
            min_index.first = prices[i];
            min_index.second = i;
            max_index.first=prices[i];
            max_index.second=i;
        }
        if (prices[i] > max_index.first){
            max_index.first=prices[i];
            max_index.second=i;
            res = std::max(res, max_index.first - min_index.first);
        }
    }
    return res;
}

std::vector<std::vector<int>> Solution::matrixReshape(std::vector<std::vector<int>> &mat, int r, int c)
{
    int origin_r = mat.size();
    int origin_c = mat[0].size();
    if (origin_c * origin_r != r * c)
        return mat;
    else
    {
        std::vector<std::vector<int>> target(r);
        int row_index = 0;
        for (int i = 0; i < origin_r; ++i) {
            for (int j = 0; j < origin_c; ++j) {
                target[row_index].push_back(mat[i][j]);
                if (target[row_index].size() == c)
                    row_index++;
            }
        }
        return target;
    }
}

std::vector<std::vector<int>> Solution::generate(int numRows)
{
    std::vector<std::vector<int>> res(numRows);
    for (int i = 0; i < numRows; ++i) {
        if (i==0)
            res[i].push_back(1);
        else {
            res[i].push_back(1);
            for (int j = 1; j < i; ++j)
                res[i].push_back(res[i-1][j]+res[i-1][j-1]);
            res[i].push_back(1);
        }
    }
    return res;
}

bool help_check_valid(std::vector<std::vector<char>> &board, int i, int j, std::set<char> &wait_valid)
{
    char& up_left = board[i-1][j-1];
    char& up_medium = board[i-1][j];
    char& up_right = board[i-1][j+1];
    char& medium_left = board[i][j-1];
    char& medium_medium = board[i][j];
    char& medium_right = board[i][j+1];
    char& down_left = board[i+1][j-1];
    char& down_medium = board[i+1][j];
    char& down_right = board[i+1][j+1];

    std::vector<char> candidate = {up_left, up_medium, up_right, medium_left, medium_medium, medium_right, down_left, down_medium, down_right};
    for (char c: candidate) {
        if (c > '0' and c <='9'){
            if(wait_valid.find(c)!=wait_valid.end())
                return false;
            else
                wait_valid.emplace(c);
        }
    }
    return true;
}

bool Solution::isValidSudoku(std::vector<std::vector<char>> &board)
{
    std::set<char> wait_valid;
    //1.校验行
    for (int i = 0; i < 9; ++i) {
        char* row = &board[i][0];
        for (int j = 0; j < 9; ++j) {
            if (row[j] > '0' and row[j] <= '9'){
                if (wait_valid.find(row[j])!=wait_valid.end())
                    return false;
                else
                    wait_valid.emplace(row[j]);
            }
        }
        wait_valid.clear();
    }
    //2.校验列
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[j][i] > '0' and board[j][i] <= '9'){
                if (wait_valid.find(board[j][i])!=wait_valid.end())
                    return false;
                else
                    wait_valid.emplace(board[j][i]);
            }
        }
        wait_valid.clear();
    }
    //3.校验对角线
    for (int i = 1; i < 8; i+=3) {
        for (int j = 1; j < 8; j+=3) {
            if (not help_check_valid(board, i, j, wait_valid))
                return false;
            wait_valid.clear();
        }
    }
    return true;
}

int Solution::lengthOfLastWord(std::string s)
{
    int result=0;
    for(auto i=s.rbegin(); i != s.rend(); i++)
    {
        if(*i != ' ')
            ++result;
        if (*i == ' ' and result != 0) break;
    }
    return result;
}

std::vector<int> Solution::plusOne(std::vector<int>& digits)
{
    int flag = 0;
    digits[digits.size()-1] += 1;
    for(auto i=digits.rbegin(); i!=digits.rend(); i++)
    {
        *i += flag;
        if(*i == 10)
        {
            *i = 0;
            flag = 1;
        } else flag=0;
    }
    if(flag==1) digits.insert(digits.begin(), 1);
    return digits;
}













