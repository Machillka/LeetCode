#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string s = "abcdeeeeeeeee";


int main()
{
    unordered_map<char, bool> isInSubstring;
    int size = s.length();

    int count = 0;
    int res = 0;

    for(int i = 0; i < size; i++)
    {
        if (s[i] == '"')
            continue;
        // 不包含
        if (isInSubstring[s[i]] == false)
        {
            count += 1;
        }
        // 不连续
        else
        {
            res = max(res, count);

            count = 1;
            isInSubstring.clear();
        }
        isInSubstring[s[i]] = true;
    }

    cout << max(res, count);

    return 0;
}