#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int p1 = 0;
        int p2 = 0;
        int res = 0;
        while (p2 < s.size() && p1 < g.size()) {
            //cout << g[p1] << " " << s[p2] << endl;
            // 如果最小的饼干够胃口最小的孩子吃的话
            if (g[p1] <= s[p2]) {
                p1++;
                p2++;
                res++;
            }
            // 如果不够，换一个大的饼干
            else {
                p2++;
            }
        }
        //cout << res << endl;
        return res;
    }
};

int main()
{
    vector<int> g;
    g.push_back(1);
    g.push_back(2);
    g.push_back(3);
    vector<int> s;
    s.push_back(1);
    s.push_back(1);
    Solution sol;
    int res = sol.findContentChildren(g, s);
    cout << res << endl;
    return res;
}