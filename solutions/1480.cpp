#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            res.push_back(res[i-1] + nums[i]);
        }
        return res;
    }

    void test()
    {
        vector<int> nums = {1, 2, 3};
        vector<int> res = runningSum(nums);

        for(int i : res)
        {
            printf("%d ", i);
        }
    }
};

int main() {
    Solution test;
    test.test();
    return 0;
}