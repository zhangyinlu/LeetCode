#include <iostream>
#include <queue>
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
    TreeNode* invertTree(TreeNode* root)
    {
        TreeNode* res = root;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty())
        {
            size_t size = q.size();
            while (size--)
            {
                root = q.front(); q.pop();
                swap(root->left, root->right);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return res;
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    printTree(solution.invertTree(root));
    return 0;
}
