#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum;
    void backtracking(vector<int>& candidates, int target, int startindex){
        if (sum > target)
            return;
        if (sum == target){
            res.push_back(path);
            return;
        }
        // 单层循环
        // for(int i = startindex; i < candidates.size(); i++){
        //     cout << candidates[i] << " ";
        // }
        // cout << endl;
        for(int i = startindex; i < candidates.size(); i++){
            // 在本层中，如果当前元素的值在之前已经使用过了，就要跳过
            if (i != startindex )
                if (candidates[i] == candidates[i-1])
                    continue;
            path.push_back(candidates[i]);
            sum = sum + candidates[i];
            backtracking(candidates, target, i + 1);
            path.pop_back();
            sum = sum - candidates[i];
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};

int main()
{
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(5);
    candidates.push_back(2);
    candidates.push_back(1);
    candidates.push_back(2);
    Solution sol;
    vector<vector<int>> res = sol.combinationSum2(candidates, 5);
    for (int i =0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}