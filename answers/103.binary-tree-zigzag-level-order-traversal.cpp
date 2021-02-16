#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool lr = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size, 0);
            while (size--)
            {
                root = q.front(); q.pop();
                level[lr ? level.size() - size - 1 : size] = root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back(move(level));
            lr = !lr;
        }
        return res;
    }
};
int main()
{
    Solution solution;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    auto res = solution.zigzagLevelOrder(root1);
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
