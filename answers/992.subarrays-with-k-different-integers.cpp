#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &A, int K)
    {
        return subarraysWithKDistinctK(A, K) - subarraysWithKDistinctK(A, K - 1);
    }
    int subarraysWithKDistinctK(vector<int> &A, int K)
    {
        if (A.empty())
        {
            return 0;
        }
        int res = 0;

        unordered_map<int, int> map;

        int lens = A.size();
        int right = 0, left = 0;
        while (right < lens)
        {
            ++map[A[right]];
            right++;
            while (map.size() > K)
            {
                --map[A[left]];
                if (map[A[left]] == 0)
                {
                    map.erase(A[left]);
                }
                ++left;
            }
            res += right - left + 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 1, 3, 4};
    cout << s.subarraysWithKDistinct(v, 3) << endl;
    return 0;
}
