#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while ( low <= high )
    {
        int middle = (high + low) / 2;
        if ( nums[middle] == target )
            return (middle);
        if ( nums[middle] > target )
            high = middle - 1;
        if ( nums[middle] < target )
            low = middle + 1;
    }
    return (-1);
}