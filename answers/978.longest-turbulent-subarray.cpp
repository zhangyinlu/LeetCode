#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int len = arr.size();
        int up = 1, down = 1;
        int ans = 1;
        for (int i = 1; i < len; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                up = down + 1;
                down = 1;
            }
            else if (arr[i] < arr[i - 1])
            {
                down = up + 1;
                up = 1;
            }
            else
            {
                up = down = 1;
            }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector a = {9, 4, 2, 10, 7, 8, 8, 1, 9};
    cout << s.maxTurbulenceSize(a) << endl;
    return 0;
}
