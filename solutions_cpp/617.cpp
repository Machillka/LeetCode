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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;

        int root1_val = root1 == nullptr ? 0 : root1->val;
        int root2_val = root2 == nullptr ? 0 : root2->val;

        TreeNode* root = new TreeNode(root1_val + root2_val);

        static auto getNodeLeft = [](TreeNode* node) { return node == nullptr ? nullptr : node->left; };
        static auto getNodeRight = [](TreeNode* node) { return node == nullptr ? nullptr : node->right; };

        root->left = mergeTrees(getNodeLeft(root1), getNodeLeft(root2));
        root->right = mergeTrees(getNodeRight(root1), getNodeRight(root2));
        ;

        return root;
    }
};