#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int cnt = 0, left = 0, right = 0, len = A.size();
        while (right < len)
        {
            if (!A[right])
                ++cnt;
            ++right;
            if (cnt > K)
            {
                if (!A[left])
                    --cnt;
                ++left;
            }
        }
        return right - left;
    }
};

int main()
{
    Solution s;
    vector<int> A = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << s.longestOnes(A, 3) << endl;

    return 0;
}
