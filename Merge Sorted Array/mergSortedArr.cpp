#include <vector>
#include <iostream>

using namespace std;

int getPartition(vector<int>& nums, int start, int end)
{
    int pivot, index;

    pivot = nums[end];
    index = start - 1;
    for (int i = start; i < end; i++)
    {
        if (nums[i] < pivot)
        {
            index++;
            int tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;
        }
    }
    int tmp = nums[index + 1];
    nums[index + 1] = nums[end];
    nums[end] = tmp;

    return (index + 1);
}

void sortArray(vector<int>& nums, int start, int end)
{
    if (start > end)
        return ;
    int p = getPartition(nums, start, end);
    sortArray(nums, p + 1, end);
    sortArray(nums, start, p - 1);
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
    sortArray(nums1, 0, nums1.size() - 1);
}
