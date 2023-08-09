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
    void backtracking(vector<int>& nums) {
        if (nums.size() == 0) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int select = nums[i];
            path.push_back(nums[i]);
            //  把选中的元素从数组中删除，其余元素留下
            nums.erase(nums.begin() + i);
            backtracking(nums);
            path.pop_back();
            // 把选中的元素添加重新进去，回溯
            nums.insert(nums.begin() + i, select);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums);
        return res;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution sol;
    vector<vector<int>> res = sol.permute(nums);
    for (int i =0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}