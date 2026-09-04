#include <algorithm>
#include <limits>
#include <utility>
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
    int getMaxInPair(const std::pair<int, int>& p)
    {
        return std::max(p.first, p.second);
    }
    // first  = 不偷当前 node 的最大收益
    // second = 偷当前 node 的最大收益
    std::pair<int, int> dfs(TreeNode* root)
    {
        if (root == nullptr)
            return { 0, 0 };

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int currentRob = root->val + left.first + right.first;

        int currentNoRob = getMaxInPair(left) + getMaxInPair(right);

        return { currentNoRob, currentRob };
    }

    int rob(TreeNode* root)
    {
        auto result = dfs(root);

        return getMaxInPair(result);
    }
};