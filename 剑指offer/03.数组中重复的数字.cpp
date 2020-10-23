//剑指 Offer 03. 数组中重复的数字
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int findRepeatNumber1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                return nums[i];
            }
        }
        return -1;
    }
    int findRepeatNumber2(vector<int> &nums)
    {
        unordered_set<int> set;
        for (auto i : nums)
        {
            if (set.count(i) == 0)
            {
                set.insert(i);
            }
            else
            {
                return i;
            }
        }
        return -1;
    }
    int findRepeatNumber(vector<int> &nums)
    {
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            if (nums[i] != i)
            {
                if (nums[nums[i]] == nums[i])
                {
                    return nums[i];
                }
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};

    cout << solution.findRepeatNumber(nums) << endl;
    return 0;
}