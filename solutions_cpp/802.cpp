#include <iostream>
#include <queue>
#include <vector>

class Solution
{
  public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph)
    {
        std::vector<int> ans;
        int nodeCounts = graph.size();

        std::vector<std::vector<int>> revGraph(nodeCounts);
        std::vector<int> inDegrees(nodeCounts);

        for (int i = 0; i < nodeCounts; i++)
        {
            for (int target : graph[i])
            {
                revGraph[target].push_back(i);
            }

            inDegrees[i] = graph[i].size();
        }

        std::queue<int> q;

        for (int i = 0; i < nodeCounts; i++)
        {
            if (inDegrees[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto target : revGraph[frontNode])
            {
                inDegrees[target]--;
                if (inDegrees[target] == 0)
                {
                    q.push(target);
                }
            }
        }

        for (int i = 0; i < nodeCounts; i++)
        {
            if (inDegrees[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    Solution sol{};
    std::vector<std::vector<int>> test = { { 1, 2 }, { 2, 3 }, { 5 }, { 0 }, { 5 }, {}, {} };
    auto ans = sol.eventualSafeNodes(test);

    for (auto node : ans)
    {
        std::cout << node << " ";
    }

    return 0;
}