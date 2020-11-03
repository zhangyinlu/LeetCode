#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        int len = A.size() - 1;

        int left = 0, right = len;
        while (left < len && A[left] < A[left + 1])
        {
            ++left;
        }
        while (right > 0 && A[right - 1] > A[right])
        {
            --right;
        }
        return left > 0 && right < len && left == right;
    }
};

int main()
{
    Solution su;
    vector<int> A = {0, 3, 2, 1};
    cout << (su.validMountainArray(A) ? "true" : "false") << endl;
    return 0;
}