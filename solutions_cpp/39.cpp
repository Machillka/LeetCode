#include <vector>

using std::vector;

class Solution
{
  public:
    int N;
    void dfs(vector<int>& currentList, int currentSum, int currentIndex, vector<int>& candidates, int target, vector<vector<int>>& resultList)
    {
        if (currentSum == target)
        {
            resultList.push_back(currentList);
            return;
        }

        if (currentSum > target)
            return;

        for (int i = currentIndex; i < N; i++)
        {
            currentList.push_back(candidates[i]);
            dfs(currentList, currentSum + candidates[i], i, candidates, target, resultList);
            currentList.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> currentList;
        N = candidates.size();
        dfs(currentList, 0, 0, candidates, target, res);
        return res;
    }
};