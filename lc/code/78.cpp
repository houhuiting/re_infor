#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    // startindex表示节点的数组应该从原数组的那个位置开始
    void backtracking(vector<int>& nums, int startindex) {
        // 不管是否是叶子节点，都要把当前节点的路径存入到结果中
        res.push_back(path);
        // 直到空节点为止
        if (startindex == nums.size())
            return;
        for (int i = startindex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
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
    vector<vector<int>> res = sol.subsets(nums);
    for (int i =0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}