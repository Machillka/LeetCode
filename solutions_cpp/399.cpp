#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    /*!
     * @brief
     *
     * @param  graph  存储的图结构
     * @param  node   当前拓展的点
     * @param  target 目标要达到的点
     * @param  path   沿路径求乘积
     * @param  res    到达目的的时候存储答案
     * @author Machillka (machillka2007@gmail.com)
     * @date 2026-10-04
     */
    vector<bool> visited;

    double dfs(const vector<vector<std::pair<int, double>>>& graph, int node, int target, double path)
    {
        if (node == target)
        {
            return path;
        }

        visited[node] = true;

        for (const auto [v, weight] : graph[node])
        {
            if (visited[v])
            {
                continue;
            }

            double result = dfs(graph, v, target, path * weight);

            if (result != -1.0)
                return result;
        }

        return -1.0f;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        // u -> {v, weight}
        vector<vector<std::pair<int, double>>> graph(30);
        std::unordered_map<string, int> ids;

        int index = 0;

        for (int i = 0; i < equations.size(); i++)
        {
            const string& u = equations[i][0];
            const string& v = equations[i][1];

            if (!ids.contains(u))
            {
                ids[u] = index++;
            }
            if (!ids.contains(v))
            {
                ids[v] = index++;
            }

            const int idxU = ids[u];
            const int idxV = ids[v];

            graph[idxU].push_back({ idxV, values[i] });
            graph[idxV].push_back({ idxU, 1.f / values[i] });
        }

        visited.resize(graph.size());

        vector<double> res;

        for (int i = 0; i < queries.size(); i++)
        {
            const string& u = queries[i][0];
            const string& v = queries[i][1];

            if (!ids.contains(u) || !ids.contains(v))
            {
                res.push_back(-1.f);
                continue;
            }

            visited.assign(graph.size(), false);

            double result = dfs(graph, ids[u], ids[v], 1.0);

            res.push_back(result);
        }

        return res;
    }
};