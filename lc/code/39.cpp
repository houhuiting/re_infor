#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum;
    // startindex表明从这个candidates的那个地方开始循环
    void backtracking(vector<int>& candidates, int target, int startindex){
        // 终止条件
        // 此路不通，放弃这一条路径
        if (sum > target)
            return;
        // 找到了这个路径，存入结果
        if (sum == target){
            res.push_back(path);
            return;
        }
        // 单层循环
        // 记录循环次数，前面去过的节点，本层循环就不能再取了
        int loop = 0;
        for (int i = startindex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum = sum + candidates[i];
            backtracking(candidates, target, startindex + loop);
            path.pop_back();
            sum = sum - candidates[i];
            loop++;
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        backtracking(candidates, target, 0);
        return res;
    }
};