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
    int maxDepth(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    cout << solution.maxDepth(root) << endl;
    return 0;
}
