#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> nums) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.insert(nums[i]).second == false)
                return true;
        }
        return false;
    }
};