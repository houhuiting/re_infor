#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    vector<string> res;
    vector<string> path;
    // 将数组["255","255","111","35"]转为ip地址255.255.111.35
    string path_to_res(vector<string> path) {
        string ip;
        ip = path[0] + '.' + path[1] + '.' + path[2] + '.' + path[3];
        return ip;
    }
    // 判断ip地址是否合法
    bool is_valid(vector<string> path) {
        if (path.size() != 4)
            return false;
        for (int i = 0; i < 4; i++) {
            // 以0开头的不合法
            if (path[i][0] == '0' && path[i].size() > 1)
                return false;
            int sum = 0;
            for (int j = 0; j < path[i].size(); j++) {
                // 遇到非数字符不合法
                if (path[i][j] < '0' || path[i][j] > '9')
                    return false;
                // 计算字符串所对应的数字
                sum = sum * 10 + (path[i][j] - '0');
            }
            // 大于255不合法
            if (sum > 255)
                return false;
        }
        return true;
    }
    // 回溯
    void backtracking(string s) {
        // 如果到了空节点，说明分割完毕
        if (s.size() == 0) {
            // 只有当path合法的时候，才会存入结果
            if (path.size() == 4 && is_valid(path)) {
                res.push_back(path_to_res(path));
                return;
            }
            return;
        }
        // 单层循环
        for (int i = 0; i < s.size(); i++) {
            // 截取字符串加入路径
            string sub = s.substr(0, i + 1);
            // 获取剩余字符串，等待进入下一次回溯
            string remain = s.substr(i + 1, s.size() - i - 1);
            path.push_back(sub);
            backtracking(remain);
            path.pop_back();
        }
        return;
    }
    vector<string> restoreIpAddresses(string s){
        backtracking(s);
        return res;
    }
};

int main()
{
    string s = "101023";
    Solution sol;
    vector<string> res = sol.restoreIpAddresses(s);
    for (int i =0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
}