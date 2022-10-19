#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int ifMax(int left, int right)
    {
        return (left > right) ? left : right;
    }

    int divideConquer(vector<int> nums, int lowest, int highest)
    {
        int leftMax, rightMax, sum, max;

        if (highest <= lowest)
            return (nums[lowest]);
        int mid = (highest + lowest) / 2;

        //left subarray
        leftMax = INT_MIN;
        sum = 0;
        for (int i = mid; i >= lowest; i--)
        {
            sum += nums[i];
            if (sum > leftMax)
                leftMax = sum;
        }
        //right subarray
        rightMax = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= highest; i++)
        {
            sum += nums[i];
            if (sum > rightMax)
                rightMax = sum;
        }

        max = ifMax(divideConquer(nums, lowest, mid), divideConquer(nums, mid + 1, highest));


        return (ifMax(leftMax + rightMax, max));
    }
    int maxSubArray(vector<int>& nums)
    {
        int N = nums.size();
        return (divideConquer(nums, 0, N - 1));
    }