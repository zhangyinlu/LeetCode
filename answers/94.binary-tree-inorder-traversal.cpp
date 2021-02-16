#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        recursionTraversal(root, res);
        return res;
    }
    void recursionTraversal(TreeNode *root, vector<int> &res)
    {
        if (nullptr != root)
        {
            recursionTraversal(root->left, res);
            res.emplace_back(root->val);
            recursionTraversal(root->right, res);
        }
    }
    vector<int> iterationTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        auto cur = root;
        while ((nullptr != cur) || (!st.empty()))
        {
            if (nullptr != cur)
            {
                st.emplace(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                res.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    vector<int> res1 = solution.inorderTraversal(root);
    for (auto i : res1)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> res2 = solution.iterationTraversal(root);
    for (auto i : res2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
