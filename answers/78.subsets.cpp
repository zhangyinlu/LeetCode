#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;

        vector<int> tmp;
        subsets(nums, 0, tmp, res);

        return res;
    }

    void subsets(vector<int>& nums, size_t cur, vector<int>& tmp, vector<vector<int>>& res)
    {
        if (cur >= nums.size())
        {
            res.emplace_back(tmp);
            return;
        }
        tmp.emplace_back(nums[cur]);
        subsets(nums, cur + 1, tmp, res);
        tmp.pop_back();
        subsets(nums, cur + 1, tmp, res);
    }
};


int main()
{
    vector<int> tmp = { 0,1,2 };
    Solution so;
    auto res = so.subsets(tmp);
    for (auto iter : res)
    {
        for (auto n : iter)
        {
            cout << n << "\t";
        }
        cout << endl;
    }

    return 0;
}
