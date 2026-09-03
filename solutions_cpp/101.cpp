/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
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
    // 判断左右子树是否对称
    bool dfs(TreeNode* left, TreeNode* right)
    {
        // 两边都没有节点
        if (left == nullptr && right == nullptr)
            return true;

        // 只有一边有节点
        if (left == nullptr || right == nullptr)
            return false;

        // 都存在但值不同
        if (left->val != right->val)
            return false;

        // 外侧互相比较 内侧互相比较
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        return dfs(root->left, root->right);
    }
};