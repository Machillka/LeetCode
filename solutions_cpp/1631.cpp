#include <algorithm>
#include <cstdlib>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using std::priority_queue;
using std::vector;

class Solution
{
  public:
    const int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        // source 到 point -> cost
        using QueueState = std::tuple<int, int, int>;
        priority_queue<QueueState, vector<QueueState>, std::greater<QueueState>> q;

        const int INF = std::numeric_limits<int>::max();
        vector<vector<int>> dist(n, std::vector<int>(m, INF));

        // 0 -> 0, cost = 0
        q.push({ 0, 0, 0 });
        dist[0][0] = 0;
        while (!q.empty())
        {
            auto [currentCost, x, y] = q.top();
            q.pop();

            if (currentCost > dist[x][y])
                continue;

            for (int i = 0; i < 4; i++)
            {
                const int targetX = x + dir[i][0];
                const int targetY = y + dir[i][1];

                if (targetX < 0 || targetX >= n || targetY < 0 || targetY >= m)
                    continue;

                const int targetCost = std::max(dist[x][y], std::abs(heights[targetX][targetY] - heights[x][y]));

                if (targetCost < dist[targetX][targetY])
                {
                    dist[targetX][targetY] = targetCost;
                    q.push({ targetCost, targetX, targetY });
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};