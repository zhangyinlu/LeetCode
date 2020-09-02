#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode* root)
    {
        return process(root) != -1;
    }

    int process(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }
        int left = process(root->left);
        if (-1 == left)
        {
            return -1;
        }
        int right = process(root->right);
        if (-1 == right)
        {
            return -1;
        }
        return (abs(right - left) > 1) ? -1 : (max(right, left) + 1);
    }
};

int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    cout << (solution.isBalanced(root) ? "true" : "false") << endl;

    return 0;
}