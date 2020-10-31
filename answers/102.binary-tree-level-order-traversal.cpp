#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (nullptr == root)
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        queue<TreeNode*> qu;
        qu.emplace(root);

        while (!qu.empty())
        {
            size_t count = qu.size();
            vector<int> list;
            while (count > 0)
            {
                auto node = qu.front();
                qu.pop();
                list.emplace_back(node->val);
                if (nullptr != node->left)
                {
                    qu.emplace(node->left);
                }
                if (nullptr != node->right)
                {
                    qu.emplace(node->right);
                }
                --count;
            }
            res.emplace_back(move(list));
        }

        return move(res);
    }
};

int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    auto res = solution.levelOrder(root);
    for (auto iter : res)
    {
        for (auto i : iter)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}