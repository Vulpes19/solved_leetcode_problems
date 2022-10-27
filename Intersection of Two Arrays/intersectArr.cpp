#include <iostream>
#include <vector>
#include <set>

using namespace std;

void    printVec(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    multiset<int> set(nums1.begin(), nums1.end());
    vector<int> res;
    int key;
    
    for (int i = 0; i < nums2.size(); i++)
    {
        auto it = set.find(nums2[i]);
        if (it != set.end())
        {
            set.erase(it);
            res.push_back(nums2[i]);
        }
    }
    return (res);
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {1, 1};
    vector <int> res;

    res = intersect(nums1, nums2);
    printVec(res);
}