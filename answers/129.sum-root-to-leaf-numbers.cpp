#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    const char pathc[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    // 使用了回溯法完成
    int sumNumbers(TreeNode *root)
    {
        if (nullptr == root)
        {
            return 0;
        }
        string path;
        vector<int> nums;
        getNums(root, path, nums);
        int res = 0;
        for (auto num : nums)
        {
            res += num;
        }
        return res;
    }
    void getNums(TreeNode *root, string &path, vector<int> &nums)
    {
        path += pathc[root->val];
        if (nullptr == root->left && nullptr == root->right)
        {
            nums.emplace_back(atol(path.c_str()));
        }
        else
        {
            if (nullptr != root->left)
            {
                getNums(root->left, path, nums);
            }
            if (nullptr != root->right)
            {
                getNums(root->right, path, nums);
            }
        }
        path.pop_back();
    }
};
int main()
{
    Solution so;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << so.sumNumbers(root) << endl;
    return 0;
}
