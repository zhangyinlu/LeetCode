#include <iostream>
#include <vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() != inorder.size() || preorder.empty())
        {
            return nullptr;
        }
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inoLeft, int inoRight)
    {
        if (preLeft > preRight || inoLeft > inoRight)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preLeft]);
        for (int i = inoLeft; i <= inoRight; ++i)
        {
            if (preorder[preLeft] == inorder[i])
            {
                int inoRoot = i - inoLeft;
                root->left = buildTree(preorder, inorder, preLeft + 1, preLeft + inoRoot, inoLeft, i - 1);
                root->right = buildTree(preorder, inorder, preLeft + inoRoot + 1, preRight, i + 1, inoRight);
                break;
            }
        }

        return root;
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
    vector<int> pre = { 3,9,20,15,7 };
    vector<int> ino = { 9,3,15,20,7 };

    Solution solution;
    TreeNode* root = solution.buildTree(pre, ino);

    printTree(root);
}