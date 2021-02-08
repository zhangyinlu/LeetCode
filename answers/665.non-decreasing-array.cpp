#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &&nums)
    {
        if (nums.size() <= 2)
        {
            return true;
        }
        int cnt = 0;
        for (size_t i = 1; i < nums.size() && cnt < 2; ++i)
        {
            if (nums[i - 1] <= nums[i])
            {
                continue;
            }
            cnt++;
            if (i - 2 >= 0 && nums[i - 2] > nums[i])
            {
                nums[i] = nums[i - 1];
            }
            else
            {
                nums[i - 1] = nums[i];
            }
        }

        return cnt <= 1;
    }
};

int main()
{
    Solution s;

    cout << (s.checkPossibility({1, 2, 3}) ? "true" : "false") << endl;

    cout << (s.checkPossibility({4, 2, 3}) ? "true" : "false") << endl;

    cout << (s.checkPossibility({4, 3, 2}) ? "true" : "false") << endl;
}
