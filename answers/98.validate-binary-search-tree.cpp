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
    int* last = nullptr;
    bool isValidBST(TreeNode* root)
    {
        if (nullptr != root)
        {
            if (!isValidBST(root->left)) return false;
            if (last && *last >= root->val) return false;
            last = &root->val;
            if (!isValidBST(root->right)) return false;
            return true;
        }
        return true;
    }
};
int main()
{
    Solution solution;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    cout << (solution.isValidBST(root1) ? "true" : "false") << endl;
    return 0;
}
