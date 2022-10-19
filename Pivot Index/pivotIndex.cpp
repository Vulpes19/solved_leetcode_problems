 #include <iostream>
 #include <vector>
 
 using namespace std;

 int pivotIndex(vector<int> nums)
 {
    int i = 1;
    int j = nums.size() - 1;
    
    while (i < nums.size() && j >= 0)
    {
        int nbr = nums[i];
        nums[i] = nums[i] + nums[i-1];
        if (nbr != nums[j])
            nums[j] = nums[j] + nums[j+1];
        cout << "nums1: " << nums[i] << endl << "nums2: " << nums[j] << endl; 
        if (nums[i] == nums[j])
            return (i);
        i++;
        j--;
    }
    /*for (int i = 0, int j = nums.size(); i < nums.size() && j >= 0; i++, j--)
    {
        if (i == 0)
            continue ;
        nums[i] = nums[i] + nums[i-1];
        nums[j] = nums[j] + nums[j+1];
        if (nums[i] == nums[j])
            return (i + 1);
    }*/
    return (-1);
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout << pivotIndex(nums) << endl;
    return (0);
}