#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<string> path;
    int all_tickets = 0;
    int use_tickets = 0;
    bool backtracking(unordered_map<string, map<string, int>> ticket_map) {
        // 题目要求优先级最高的航线，如果找到了第一个结果，直接返回true，不再进行后面的查找
        // 因为后面也可能能找到正确的结果，不能再查找下去了，否则就有可能出现结果覆盖
        if (use_tickets == all_tickets) {
            return true;
        }
        // 循环当前可选择的票
        for (auto it = ticket_map[path[path.size() - 1]].begin(); it != ticket_map[path[path.size() - 1]].end(); ++it) {
            // 这个票已经用完了，不能再用了
            if (it->second == 0)
                continue;
            path.push_back(it->first);
            use_tickets++;
            it->second--;
            bool success = backtracking(ticket_map);
            if (success)
                return true;
            path.pop_back();
            use_tickets--;
            it->second++;
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> ticket_map;
        path.push_back("JFK");
        for (int i = 0; i < tickets.size(); i++) {
            all_tickets++;
            string begin = tickets[i][0];
            string end = tickets[i][1];
            ticket_map[begin][end]++;
        }
        backtracking(ticket_map);
        return path;
    }
};

int main()
{
    vector<vector<string>> tickets = {
        {"MUC", "LHR"},
        {"JFK", "MUC"},
        {"SFO", "SJC"},
        {"LHR", "SFO"}
    };
    Solution sol;
    vector<string> res = sol.findItinerary(tickets);
    for (int i =0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
}