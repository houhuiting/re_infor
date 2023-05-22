#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int param2 = st.top();
                st.pop();
                int param1 = st.top();
                st.pop();
                st.push(param1 + param2);
            }
            else if (tokens[i] == "-") {
                int param2 = st.top();
                st.pop();
                int param1 = st.top();
                st.pop();
                st.push(param1 - param2);
            }
            else if (tokens[i] == "*") {
                int param2 = st.top();
                st.pop();
                int param1 = st.top();
                st.pop();
                st.push(param1 * param2);
            }
            else if (tokens[i] == "/") {
                int param2 = st.top();
                st.pop();
                int param1 = st.top();
                st.pop();
                st.push(param1 / param2);
            }
            else {
                int num = atoi(tokens[i].c_str());
                st.push(num);
            }
        }
        return st.top();
    }
};

int main()
{
    vector<string> tokens;
    tokens.push_back("10");
    tokens.push_back("6");
    tokens.push_back("9");
    tokens.push_back("3");
    tokens.push_back("+");
    tokens.push_back("-11");
    tokens.push_back("*");
    tokens.push_back("/");
    tokens.push_back("*");
    tokens.push_back("17");
    tokens.push_back("+");
    tokens.push_back("5");
    tokens.push_back("+");
    Solution sol;
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}