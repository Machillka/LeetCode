#include <vector>

using std::vector;

class Solution
{
  public:
    static constexpr int directions[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    void flood_fill(int n, int m, int x, int y, vector<vector<char>>& grid)
    {
        if (x >= n || x < 0 || y >= m || y < 0)
            return;

        if (grid[x][y] == '0')
            return;

        grid[x][y] = '0';

        for (const auto& direction : directions)
        {
            flood_fill(n, m, x + direction[0], y + direction[1], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        int islandCount = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    islandCount++;
                    flood_fill(n, m, i, j, grid);
                }
            }
        }
        return islandCount;
    }
};