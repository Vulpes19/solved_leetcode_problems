#include <vector>
#include <iostream>

using namespace std;

void sortArray(vector<int>& nums)
{
    int tmp;
    
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > nums[j])
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (m == 0 && n > 0)
    {
        nums2.erase(nums2.begin() + n,nums2.end());
        for (int i = 0; i < n; i++)
            nums1[i] = nums2[i];
        return ;
    }
    if (n == 0 && m > 0)
    {
        nums1.erase(nums1.begin() + m,nums1.end());
        return ;
    }
    for (int i = m, j = 0; i < m + n, j < n; i++, j++)
        nums1[i] = nums2[j];
    sortArray(nums1);
}

int main()
{
    vector<int> nums = {0};
    vector<int> nums2 = {1};

    merge(nums, 0, nums2, 1);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << endl;
}