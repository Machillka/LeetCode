#include <array>
#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

class Trie
{
  private:
    static constexpr int INVALID = -1;
    struct Node
    {
        std::array<int, 26> children;
        bool is_end = false;

        Node()
        {
            children.fill(INVALID);
        }
    };

  private:
    std::vector<Node> _nodes;

    // 顺序查找到最后一个字符在当前树对应的节点位置
    int findNode(std::string_view text) const
    {
        // 初始的时候在 root 处
        int current = 0;
        for (char c : text)
        {
            // 得到文本在当前层的idx
            const int index = c - 'a';

            // current 在第一次是 0, 不越界,又由于在 insert 的时候保证了 children[index] 一定存在 / 或者非法 所以在之后的迭代也不会越界
            const int next = _nodes[current].children[index];

            if (next == INVALID)
            {
                return INVALID;
            }
            current = next;
        }

        return current;
    }

  public:
    Trie()
    {
        // nodes_[0] 固定作为 root
        _nodes.emplace_back();
    }

    void insert(std::string word)
    {
        int current = 0;
        for (char c : word)
        {
            const int index = c - 'a';
            int next = _nodes[current].children[index];

            if (next == INVALID)
            {
                next = static_cast<int>(_nodes.size());

                // 自加保证下标唯一
                _nodes.emplace_back();

                _nodes[current].children[index] = next;
            }

            current = next;
        }

        _nodes[current].is_end = true;
    }

    bool search(std::string word)
    {
        int index = findNode(word);
        return index != INVALID && _nodes[index].is_end;
    }

    bool startsWith(std::string prefix)
    {
        return findNode(prefix) != INVALID;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */