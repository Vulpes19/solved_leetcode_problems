#include <iostream>
#include <vector>

using namespace std;

void    mergeSort( vector<int> &nums, int low, int high, int mid )
{
    int size1, size2;
    size1 = mid - low + 1;
    size2 = high - mid;
    vector<int> nums1(size1), nums2(size2);

    for ( size_t i = 0; i < size1; i++ )
        nums1[i] = nums[low + i];
    for ( size_t i = 0; i < size2; i++ )
        nums2[i] = nums[mid + 1 + i];
    size_t i, j, k;
    i = 0;
    j = 0;
    k = low;

    while ( i < size1 && j < size2 )
    {
        if ( nums1[i] <= nums2[j] )
            nums[k++] = nums1[i++];
        else
            nums[k++] = nums2[j++];
    }
    while ( i < size1 )
        nums[k++] = nums1[i++];
    while ( j < size2 )
        nums[k++] = nums2[j++];
}

void divide( vector<int> &nums, int low, int high )
{
    if ( high == low )
        return ;
    int mid = (high + low) / 2;
    divide( nums, low, mid );
    divide( nums, mid + 1, high );
    mergeSort( nums, low, high, mid );
}

int main( void )
{
    vector<int> nums = {1, 5, 2, 9, 0, 9, 10, 34, 2, 13};
    divide(nums, 0, nums.size() - 1);
    for ( size_t i = 0; i < nums.size(); i++ )
        cout << nums[i] << endl;
}