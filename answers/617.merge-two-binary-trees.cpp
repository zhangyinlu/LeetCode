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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (nullptr == t1)
        {
            return t2;
        }
        if (nullptr == t2)
        {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
void printTree(TreeNode* node)
{
    if (nullptr == node)
    {
        cout << "(null)\t";
        return;
    }
    cout << node->val << "\t";
    if (nullptr == node->left && nullptr == node->right)
    {
        return;
    }
    printTree(node->left);
    printTree(node->right);
}
int main()
{
    Solution solution;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    printTree(solution.mergeTrees(root1, root2));
    return 0;
}
