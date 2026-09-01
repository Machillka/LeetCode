#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using std::queue;
using std::vector;

class Solution
{
  public:
    static constexpr int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int timeCount = 0;
        using CoodType = std::tuple<int, int, int>;

        queue<CoodType> q;

        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    ++fresh;
                }
                else if (grid[i][j] == 2)
                {
                    q.push({ i, j, 0 });
                }
            }
        }

        while (!q.empty())
        {
            // 拓展节点
            CoodType node = q.front();
            q.pop();
            auto [x, y, time] = node;

            // 进行拓展
            for (int i = 0; i < 4; i++)
            {
                const int target_x = x + dir[i][0];
                const int target_y = y + dir[i][1];

                if (target_x >= n || target_x < 0 || target_y >= m || target_y < 0)
                    continue;

                if (grid[target_x][target_y] == 1)
                {
                    q.push({ target_x, target_y, time + 1 });
                    grid[target_x][target_y] = 2;
                    timeCount = time + 1;
                    --fresh;
                }
            }
        }

        return fresh == 0 ? timeCount : -1;
    }
};