#include <iostream>
#include <vector>
using namespace std;
//Definition for a binary tree node.
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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> res;
        if (nullptr != root)
        {
            vector<int> path;
            pathSum(root, sum, path, res);
        }
        return res;
    }
    void pathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &res)
    {
        path.emplace_back(root->val);
        if (nullptr == root->left && nullptr == root->right && sum == root->val)
        {
            res.emplace_back(path);
        }
        else
        {
            if (nullptr != root->left)
            {
                pathSum(root->left, sum - root->val, path, res);
            }
            if (nullptr != root->right)
            {
                pathSum(root->right, sum - root->val, path, res);
            }
        }
        path.pop_back();
        return;
    }
};
int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    auto res = solution.pathSum(root, 3);
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
