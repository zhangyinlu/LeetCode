#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> position;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (position.count(nums[i]) == 0)
            {
                position.insert(make_pair(nums[i], vector<int>{1, i, i}));
            }
            else
            {
                ++position[nums[i]][0];
                position[nums[i]][2] = i;
            }
        }

        int maxCnt = 0, minLen = 0;
        for (auto &iter : position)
        {
            if (maxCnt < iter.second[0])
            {
                maxCnt = iter.second[0];
                minLen = iter.second[2] - iter.second[1];
            }
            else if (maxCnt == iter.second[0])
            {
                minLen = std::min(minLen, iter.second[2] - iter.second[1]);
            }
        }
        return minLen + 1;
    }
};

int main()
{
    Solution s;
    vector<int> A = {1, 2, 2, 3, 1};
    cout << s.findShortestSubArray(A) << endl;
    return 0;
}
