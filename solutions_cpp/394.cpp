#include <cctype>
#include <stack>
#include <string>
#include <utility>

using std::string;

class Solution
{
  public:
    string decodeString(string s)
    {
        std::stack<std::pair<int, string>> Stack;

        string CurrentString = "";
        int CurrentNumber = 0;

        for (auto ch : s)
        {
            if (isdigit(ch))
            {
                CurrentNumber = CurrentNumber * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                Stack.push({ CurrentNumber, CurrentString });
                CurrentNumber = 0;
                CurrentString = "";
            }
            else if (ch == ']')
            {
                auto [RepeatTimes, PreviousString] = Stack.top();
                Stack.pop();

                string temp = "";

                for (int i = 0; i < RepeatTimes; i++)
                {
                    temp += CurrentString;
                }

                CurrentString = PreviousString + temp;
            }
            else
            {
                CurrentString += ch;
            }
        }

        return CurrentString;
    }

    string dfs(const string& s, int& index)
    {
        string res;

        while (index < s.size() && s[index] != ']')
        {
            // 以数字开头
            if (s[index] >= '0' && s[index] <= '9')
            {

                int current_num = 0;
                // 得到第一个数字
                while (index < s.size() && s[index] >= '0' && s[index] <= '9')
                {
                    current_num = current_num * 10 + (s[index] - '0');
                    ++index;
                }
                // 下一个字符必定是 [
                ++index;

                string inner = dfs(s, index);

                // 去除 ]
                ++index;

                string repeat;

                for (int i = 0; i < current_num; i++)
                {
                    repeat += inner;
                }

                res += repeat;
            }
            // 以字符开头
            else
            {
                res += s[index];
                ++index;
            }
        }

        return res;
    }
};