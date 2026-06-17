#include <vector>
using std::vector;

class TreeAncestor
{
  public:
    TreeAncestor(int n, vector<int>& parent)
    {
        _jumpLevelCount = 1;
        // 由于 k <= n, 所以层数最多是 logN
        while ((1 << _jumpLevelCount) <= n)
            _jumpLevelCount++;

        // 初始化,默认所有祖先都是 -1
        _up.assign(n, vector<int>(_jumpLevelCount, -1));

        // 初始化第一层 (边界条件)
        // i 节点向上跳一层直接就是 parent
        for (int i = 0; i < n; i++)
            _up[i][0] = parent[i];

        for (int j = 1; j < _jumpLevelCount; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (_up[i][j - 1] != -1)
                {
                    _up[i][j] = _up[_up[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int j = 0; j < _jumpLevelCount; j++)
        {
            if (k & (1 << j))
            {
                node = _up[node][j];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }

  private:
    vector<vector<int>> _up;
    int _jumpLevelCount; // 记录跳表层数 (logN)
};