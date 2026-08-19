#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
class Solution
{
  private:
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

      public:
        Trie()
        {
            _nodes.emplace_back();
        }

        void insert(std::string_view text)
        {
            int current = 0;
            for (char c : text)
            {
                const int index = c - 'a';
                int next = _nodes[current].children[index];

                if (next == INVALID)
                {
                    next = static_cast<int>(_nodes.size());

                    _nodes.emplace_back();

                    _nodes[current].children[index] = next;
                }

                current = next;
            }
            _nodes[current].is_end = true;
        }

        std::string find_with_prefix(std::string_view text) const
        {
            int current = 0;
            for (size_t i = 0; i < text.size(); i++)
            {
                const int index = text[i] - 'a';
                const int next = _nodes[current].children[index];
                if (next == INVALID)
                    return {};
                if (_nodes[next].is_end)
                {
                    return std::string{ text.substr(0, i + 1) };
                }
                current = next;
            }
            return {};
        }
    };

  public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence)
    {
        Trie database;

        for (const std::string_view word : dictionary)
        {
            database.insert(word);
        }

        std::istringstream input(sentence);

        std::string result;
        std::string word;

        bool first = true;

        while (input >> word)
        {
            const std::string prefix = database.find_with_prefix(word);

            if (!first)
            {
                result += ' ';
            }

            if (!prefix.empty())
            {
                result += prefix;
            }

            else
            {
                result += word;
            }

            first = false;
        }

        return result;
    }
};