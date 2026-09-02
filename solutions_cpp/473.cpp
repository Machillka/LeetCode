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
#include <unordered_map>
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
    int ans = 0;
    void dfs(TreeNode* node, int targetSum)
    {
        if (node == nullptr)
            return;

        sumTree(node, targetSum);

        dfs(node->left, targetSum);
        dfs(node->right, targetSum);
    }
    void sumTree(TreeNode* node, int targetSum)
    {
        if (node == nullptr)
            return;

        const int remain = targetSum - node->val;

        if (remain == 0)
        {
            ans++;
        }

        sumTree(node->left, remain);
        sumTree(node->right, remain);
    }
    int pathSum(TreeNode* root, int targetSum)
    {
        dfs(root, targetSum);
        return ans;
    }
};

class Solution_Prefix
{
  public:
    int ans = 0;
    // prefix -> count
    std::unordered_map<long long, int> count;

    void dfs(TreeNode* node, long long currentsum, long long targetSum)
    {
        if (node == nullptr)
            return;

        const long long sum = currentsum + static_cast<long long>(node->val);

        // 以当前 node 为终点 有多少个合法起点
        ans += count[sum - targetSum];

        ++count[sum];
        dfs(node->left, sum, targetSum);
        dfs(node->right, sum, targetSum);
        --count[sum];
    }

    int pathSum(TreeNode* root, int targetSum)
    {
        // 对于 target = 1
        count[0] = 1;
        dfs(root, 0ll, targetSum);
        return ans;
    }
};