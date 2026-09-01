#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using std::vector;

class Solution
{
  public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        // v, w
        using Edge = std::pair<int, int>;
        // u -> [v, w]
        vector<vector<Edge>> graph(n + 1);

        // 建图
        for (const auto& data : times)
        {
            const int u = data[0];
            const int v = data[1];
            const int w = data[2];

            graph[u].emplace_back(Edge{ v, w });
        }

        const int INF = std::numeric_limits<int>::max();

        // source -> index 的最短距离
        vector<int> dist(n + 1, INF);

        // 距离; source -> node;
        using State = std::pair<int, int>;
        std::priority_queue<State, vector<State>, std::greater<State>> q;

        dist[k] = 0;
        q.push({ 0, k });

        while (!q.empty())
        {
            // 目前距离 Source 最近的, 值得拓展的点
            auto [currentDist, u] = q.top();
            q.pop();

            // 由贪心, 确保信息不是过期的
            if (currentDist > dist[u])
                continue;

            // 遍历所有从 u 出发的边, 向外拓展
            for (auto [v, weight] : graph[u])
            {
                // u + weight -> 转移到 v —— 即从 Source 转移到 v
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    q.push({ dist[v], v });
                }
            }
        }

        auto ans = *std::max_element(dist.begin() + 1, dist.end());
        return ans == INF ? -1 : ans;
    }
};