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
    int minDepth(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (0 == left || 0 == right) ? (left + right + 1) : (min(left, right) + 1);
    }
};

int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    cout << solution.minDepth(root) << endl;

    return 0;
}
