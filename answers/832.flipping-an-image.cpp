#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        for (auto &iter : A)
        {
            int len = iter.size();
            for (int i = 0; i < len / 2; ++i)
            {
                std::swap(iter[i], iter[len - i - 1]);
            }
            for (int i = 0; i < len; ++i)
            {
                iter[i] = !iter[i];
            }
        }
        return A;
    }
};
