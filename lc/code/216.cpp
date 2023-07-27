#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    // 从[1,n]这个集合中，找到k个组合，再判断组合中的数是否为n
    void backtracking(int k, int n, int startindex){
        // 终止条件
        if (path.size() >= k){
            // 只有这个组合中所有数字相加为n才存入结果
            if (sum == n)
                res.push_back(path);
            return;
        }
        // 单层搜索
        for (int i = startindex; i <= n; i++){
            // 处理节点
            path.push_back(i);
            sum = sum + i;
            backtracking(n, k, i+1);
            // 回溯
            path.pop_back();
            sum = sum - i;
        }
        return;
    }
    // k个数字，相加为n
    vector<vector<int>> combinationSum3(int k, int n){
        backtracking(k, n, 1);
        return res;
    }
};