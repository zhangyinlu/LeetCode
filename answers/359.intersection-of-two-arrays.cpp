#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> hash;
        for (auto n : nums1)
        {
            hash.insert(n);
        }

        vector<int> res;
        for (auto n : nums2)
        {
            if (hash.count(n) != 0)
            {
                res.emplace_back(n);
                hash.erase(n);
            }
        }
        return res;
    }
};

int main()
{
    Solution su;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2};

    auto res = su.intersection(nums1, nums2);

    for (auto n : res)
    {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}