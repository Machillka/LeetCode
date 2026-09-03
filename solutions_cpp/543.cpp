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

// class Solution
// {
//   public:
//     // 返回一棵树的最大深度
//     int count_depth(TreeNode* node, int depth)
//     {
//         if (node == nullptr)
//             return 0;

//         if (node->left == nullptr && node->right == nullptr)
//             return depth;

//         return std::max(count_depth(node->left, depth + 1), count_depth(node->right, depth + 1));
//     }
//     int diameterOfBinaryTree(TreeNode* root)
//     {
//         if (root == nullptr)
//             return 0;
//         // 左子树 + 右子树
//         int ans_root = count_depth(root->left, 1) + count_depth(root->right, 1);

//         int ans_left = diameterOfBinaryTree(root->left);
//         int ans_right = diameterOfBinaryTree(root->right);

//         return std::max({ ans_right, ans_left, ans_root });
//     }
// };

class Solution
{
  public:
    int ans = 0;
    // 返回相对当前节点的最大深度
    int count_depth(TreeNode* node)
    {
        if (node == nullptr)
            return 0;

        auto leftDepth = count_depth(node->left);
        auto rightDepth = count_depth(node->right);

        ans = std::max(ans, leftDepth + rightDepth);

        return std::max(leftDepth, rightDepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        count_depth(root);
        return ans;
    }
};