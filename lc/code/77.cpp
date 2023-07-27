#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution{
public:
    //  存放最终结果
    vector<vector<int> > res;
    // 存放路径
    vector<int> path;
    void backtracking(int n, int k, int startindex){
        // 终止条件：找到叶子节点时/path大小到达k的时候
        if (path.size() >= k){
            res.push_back(path);
            return;
        }
        //  单层搜索，处理每一层的集合
        // 对集合进行循环，处理集合中的每一个节点
        for (int i = startindex; i <= n; i++) {
            // 处理节点：取出一个元素，存入到路径中
            path.push_back(i);
            // 递归下一层节点
            backtracking(n, k, i + 1);
            // 回撤
            path.pop_back();
        }
        return;
    }
    vector<vector<int> > combine(int n, int k){
        backtracking(n, k, 1);
        return res;
    }
};