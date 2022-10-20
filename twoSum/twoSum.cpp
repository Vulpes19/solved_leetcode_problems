//simple brute force method
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ret;
    
        ret = {0, 0};
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret = {i, j};
                    return (ret);
                }
            }
        }
        return (ret);
    }
};

#include <map>
//hashmap method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> hashmap;
        vector<int> ret;
        
        ret = {0, 0};
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap.count(nums[i]))
            {
                ret = {hashmap[nums[i]], i};
                return (ret);
            }
            hashmap[target - nums[i]] = i;
        }
        return (ret);
    }
};