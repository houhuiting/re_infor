#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    // startindex表示节点的数组应该从原数组的那个位置开始
    void backtracking(vector<int>& nums, int startindex) {
        if (path.size() >= 2)
            res.push_back(path);
        // 遇到空节点，结束
        if (startindex == nums.size())
            return;
        // 使用一个set来碰到同一层的值有没有被使用过
        unordered_set<int> used;
        for (int i = startindex; i < nums.size(); i++) {
            // 如果这个值前面用过了，跳过
            if (used.count(nums[i]))
                continue;
            // 如果当前值小于path最后一个值，不满足递增的条件，跳过
            if (path.size() > 0 && nums[i] < path[path.size() - 1])
                continue;
            path.push_back(nums[i]);
            used.insert(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(7);
    Solution sol;
    vector<vector<int>> res = sol.findSubsequences(nums);
    for (int i =0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}