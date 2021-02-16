#include <iostream>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (0 == n)
        {
            return vector<TreeNode*>();
        }
        return generate(1, n);
    }
    vector<TreeNode*> generate(int left, int right)
    {
        vector<TreeNode*> res;
        if (left > right)
        {
            res.emplace_back(nullptr);
        }
        for (int i = left; i <= right; ++i)
        {
            vector<TreeNode*> leftTrees = generate(left, i - 1);
            vector<TreeNode*> rightTrees = generate(i + 1, right);
            for (TreeNode* leftTree : leftTrees)
            {
                for (TreeNode* rightTree : rightTrees)
                {
                    res.emplace_back(new TreeNode(i, leftTree, rightTree));
                }
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
    vector<TreeNode*> res = solution.generateTrees(3);
    for (auto tree : res)
    {
        printTree(tree);
        cout << endl;
    }
    return 0;
}
