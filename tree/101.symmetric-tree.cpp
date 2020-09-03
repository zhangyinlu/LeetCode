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
    bool isSymmetric(TreeNode* root)
    {
        if (nullptr == root)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* p, TreeNode* q)
    {
        if (nullptr != p && nullptr != q)
        {
            if (p->val != q->val)
            {
                return false;
            }
            return isMirror(p->left, q->right) && isMirror(p->right, q->left);
        }
        else if (nullptr == p && nullptr == q)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    cout << (solution.isSymmetric(root) ? "true" : "false") << endl;

    return 0;
}