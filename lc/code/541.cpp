#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.size()) {
            int loop = i/k;
            //如果loop是偶数，那就反转
            if(loop%2 == 0) {
                // 如果最后一次反转的数量不够k个，那就反转到end()为止
                if (i + k > s.size())
                    reverse(s.begin() + i, s.end());
                else {
                    reverse(s.begin() + i, s.begin() + i + k);
                }
            }
            i = i + k;
        }
        return s;
    }
};

int main()
{
    string s = "abcdefg";
    Solution sol;
    string t = sol.reverseStr(s,2);
    cout << t << endl;
}