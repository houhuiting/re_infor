#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    void del_space(string &s) {
        int slow = 0;
        int fast = 0;
        while (s[fast] == ' ') {
            fast++;
        }
        while (fast < s.size()) {
            if (s[fast] != ' ')
            {
                s[slow] = s[fast];
                slow++;
                fast++;
            }
            else {
                // 如果有连续多个空格存在，找到最后一个空格，且只保留这最后一个空格
                // 如果s的最后几位都是空格，使用while定位到最后一个空格
                while (fast < s.size() - 1 && s[fast + 1] == ' ') {
                    fast++;
                }
                s[slow] = s[fast];
                slow++;
                fast++;
            }
        }
        // 由于上面赋值之后，slow++，所以导致slow比实际赋值的位置多1，这里减掉
        slow--;
        // 如果最后有空格，经过之前的赋值，仅把最后一个空格赋值下来，这里删掉
        if (s[slow] == ' ') {
            slow--;
        }
        // slow是下标，slow+1才是长度
        s.resize(slow + 1);
    }

    string reverseWords(string s) {
        // 先移除多余空格，保证字符串是“word1 word2 word3”的格式
        del_space(s);
        // 将整个字符串翻转
        reverse(s.begin(), s.end());
        // 识别空格，找到一个word，对word翻转
        int start = 0;
        int end = 0;
        while(end < s.size()) {
            // 找到word的最后一个字母的下标
            while (s[end + 1] != ' ' && end != s.size() - 1) {
                end++;
            }
            reverse(s.begin() + start, s.begin() + end + 1);
            start = end + 2;
            end = start;
        }
        return s;
    }
};

int main()
{
    string s="  hello world!  ";
    Solution sol;
    s = sol.reverseWords(s);
    cout << s << endl;
    cout << s.size() << endl;
    return 0;
}