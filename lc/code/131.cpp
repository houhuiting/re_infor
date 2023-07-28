#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
public:
    vector<vector<string>> res;
    vector<string> path;
    // 判断是否是回文字符串
    bool is_partition(string s){
        string re = s;
        reverse(re.begin(), re.end());
        return s == re ? true : false;
    }
    // 回溯
    void backtracking(string s){
        //  如果在path已经出现了非回文子串，那这条路径就没必要往下走了
        if (path.size() > 0 && !is_partition(path[path.size() - 1]))
            return;
        // 分割完毕
        if (s.size() == 0){
            if (is_partition(path[path.size() - 1])){
                res.push_back(path);
            }
            return;
        }
        for (int i = 0; i < s.size(); i++){
            // 截取子串
            string sub = s.substr(0, i + 1);
            string remain = s.substr(i + 1, s.size() - i - 1);
            path.push_back(sub);
            backtracking(remain);
            path.pop_back();
        }
        return;
    }
    vector<vector<string>> partition(string s){
        backtracking(s);
        return res;
    }
};

int main()
{
    string s = "aab";
    Solution sol;
    vector<vector<string>> res = sol.partition(s);
    for (int i =0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}