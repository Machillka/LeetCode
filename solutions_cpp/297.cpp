/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <sstream>
#include <stack>
#include <string>
#include <string_view>

using std::string;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
    // 哨兵, 如果是这个数值则返回 nullptr
    static constexpr int EMPTY_NODE_DIGIT = 114514;
    const std::string EMPTY_NODE_STRING = "114514";

  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        // 深度优先序列化
        if (root == nullptr)
        {
            return EMPTY_NODE_STRING + " ";
        }

        string res = std::to_string(root->val);

        string left = serialize(root->left);
        string right = serialize(root->right);

        return res + " " + left + " " + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        std::stringstream input(data);
        return build(input);
    }

    TreeNode* build(std::stringstream& input)
    {
        int val;
        input >> val;

        if (val == EMPTY_NODE_DIGIT)
            return nullptr;

        TreeNode* root = new TreeNode(val);
        root->left = build(input);
        root->right = build(input);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));