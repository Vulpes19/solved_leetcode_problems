#include <iostream>
#include <vector>

using namespace std;

 void    mergeSort( vector<int> &nums, int low, int mid, int high )
    {
        int size1 = mid - low + 1;
        int size2 = high - mid;

        vector<int> nums1(size1), nums2(size2);
        for ( int i = 0; i < size1; i++ )
        {
            nums1[i] = nums[low + i];
        }
        for ( int i = 0; i < size2; i++ )
        {
            nums2[i] = nums[mid + i + 1];
        }

        int i, j, k;
        i = 0;
        j = 0;
        k = low;
        while ( i < size1 && j < size2 )
        {
            if ( nums1[i] <= nums2[j] )
                nums[k] = nums1[i++];
            else
                nums[k] = nums2[j++];
            k++;
        }
        while ( i < size1 )
            nums[k++] = nums1[i++];
        while ( j < size2 )
            nums[k++] = nums2[j++];
    }

    void    sort( vector<int> &nums, int low, int high )
    {
        if ( low == high )
            return ;
        int mid = (high + low) / 2;
        sort(nums, low, mid);
        sort(nums, mid + 1, high);
        mergeSort(nums, low, mid, high);
    }

    int majorityElement(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        int check = nums.size() / 2;
        int nbr = nums[0];
        int k = 0;
        for ( size_t i = 0; i < nums.size(); i++ )
        {
            if ( k > check )
                return (nbr);
            if ( nums[i] == nbr )
                k++;
            else
            {
                k = 1;
                nbr = nums[i];
            }
        }
        return (nbr);
    }

int main( void )
{
    std::vector<int> vec1 = {3, 2, 3};
    std::vector<int> vec2 = {2,2,1,1,1,2,2};
    std::vector<int> vec3 = {-1,1,1,1,2,1};
    int ret = majorityElement(vec3);
    cout << "result: " << ret << endl;
    return 0;
}