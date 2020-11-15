#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int numTrees(int n)
    {
        unordered_map<int, int> set;
        return numTree(1, n, set);
    }
    int numTree(int left, int right, unordered_map<int, int>& set)
    {
        if (left > right)
        {
            return 1;
        }
        auto iter = set.find(right - left);
        if (set.end() != iter)
        {
            return iter->second;
        }
        int res = 0;
        for (int i = left; i <= right; ++i)
        {
            res += numTree(left, i - 1, set) * numTree(i + 1, right, set);
        }
        set.insert(make_pair(right - left, res));
        return res;
    }
};
int main()
{
    Solution solution;
    cout << solution.numTrees(3) << endl;
    return 0;
}
