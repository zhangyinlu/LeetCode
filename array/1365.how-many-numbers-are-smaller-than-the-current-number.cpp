#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int cnt[102] = {0};
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            cnt[nums[i] + 1]++;
        }
        for (int i = 1; i <= 100; i++)
        {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = cnt[nums[i]];
        }
        return nums;
    }
};

int main()
{
    vector<int> nums = {8, 1, 2, 2, 3};

    Solution s;
    auto res = s.smallerNumbersThanCurrent(nums);
    for (auto num : res)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}