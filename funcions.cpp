//
// Created by gangjie on 2021/10/25.
//
#include "solution.h"
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

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














