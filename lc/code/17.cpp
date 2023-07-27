#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    // 对数字和字母之间做一个映射
    vector<string> dic = {
        "",// 0
        "",// 1
        "abc",// 2
        "def",// 3
        "ghi",// 4
        "jkl",// 5
        "mno",// 6
        "pqrs",// 7
        "tuv",// 8
        "wxyz"// 9
    };
    vector<string> res;
    string path;
    // digits代表用户输入的数字集合，deep代表本层节点取的数字是数字集合的第几个
    void backtracking(string digits, int deep){
        // 终止条件，path大小和digits大小相同
        if (path.size() == digits.size()){
            res.push_back(path);
            return;
        }
        // 本层数字所对应的集合
        string words = dic[digits[deep] - '0'];
        // 单层循环
        for (int i = 0; i < words.size(); i++){
            path.push_back(words[i]);
            backtracking(digits, deep + 1);
            path.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits){
        backtracking(digits, 0);
        return res;
    }
};