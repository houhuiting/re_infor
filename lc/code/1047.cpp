#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        string res = "";
        for (int i = 0; i < S.size(); i++) {
            // 栈为空，和没匹配上，都将元素压入栈
            if (st.empty() || st.top() != S[i]) {
                st.push(S[i]);
            }
            // 栈不为空，且匹配上了
            else {
                st.pop();
            }
        }
        while (!st.empty()) {
            res = res + st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    string s = "abbaca";
    Solution sol;
    cout << sol.removeDuplicates(s) << endl;
    return 0;
}