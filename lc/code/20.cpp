#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        stack<char> st;
        unordered_map<char, char> map;
        map['['] = ']';
        map['('] = ')';
        map['{'] = '}';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            // 如果是左符号的话，就压入栈
            if (map.count(c)) {
                st.push(c);
            }
            // 如果是右符号的话，就看和栈顶元素是否匹配
            else {
                // 栈不为空，且匹配上了
                if (!st.empty() && map[st.top()] == c) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    string s = "([)]";
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}