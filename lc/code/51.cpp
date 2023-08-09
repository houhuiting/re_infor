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
    // 结果集，vector<vector<int>>用于存放一个结果的皇后的坐标
    vector<vector<vector<int>>> res_int;
    // 用于存放一个结果的皇后的坐标
    vector<vector<int>> path;
    // 检查是否合法
    // 不能同行，不能同列，不能同斜线
    bool is_valid(vector<vector<int>>& path) {
        unordered_set<int> set_1;
        unordered_set<int> set_2;
        unordered_set<int> set_3;
        // 检查不能同列
        for (int i = 0; i < path.size(); i++) {
            if (!set_1.count(path[i][1]))
                set_1.insert(path[i][1]);
            else {
                return false;
            }
        }
        // 检查不能同斜线，135度斜线
        for (int i = 0; i < path.size(); i++) {
            // 如果行和列的差值相等，那就是同斜线
            if (!set_2.count(path[i][0] - path[i][1]))
                set_2.insert(path[i][0] - path[i][1]);
            else {
                return false;
            }
        }
        // 检查不能同斜线，45度斜线
        for (int i = 0; i < path.size(); i++) {
            // 如果行和列的差值相等，那就是同斜线
            if (!set_3.count(path[i][0] + path[i][1]))
                set_3.insert(path[i][0] + path[i][1]);
            else {
                return false;
            }
        }
        return true;
    }
    void backtracking(int n) {
        // 如果不合法，直接返回
        if (!is_valid(path))
            return;
        // 如果合法且到了叶子节点处，把结果存下
        if (path.size() == n) {
            res_int.push_back(path);
            return;
        }
        // j来代表循环到这一行的第几列
        for (int j = 0; j < n; j++) {
            int row = path.size();
            int col = j;
            vector<int> point;
            point.push_back(row);
            point.push_back(col);
            path.push_back(point);
            backtracking(n);
            path.pop_back();
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        backtracking(n);
        // 最终结果
        vector<vector<string>> res;
        for (int i = 0; i < res_int.size(); i++) {
            vector<string> res_ele;
            for (int j = 0; j < n; j++) {
                string str(n, '.');
                str[res_int[i][j][1]] = 'Q';
                res_ele.push_back(str);
            }
            res.push_back(res_ele);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(5);
    cout << res.size() << endl;
    for (int i =0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
}