#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;
        // 定义双指针，指明区间的开始和结束，用于判断是否上上升区间
        int p1 = 0;
        int p2 = 1;
        // 表示最终结果
        int res = 0;
        // 用来表示当前上升区间中，区间结束-区间开始的差
        int max = 0;
        while (p1 < prices.size() && p2 < prices.size()) {
            // 如果处于上升区间
            if (prices[p2] - prices[p2 - 1] > 0) {
                // 由于这个上升区间可能是连续的，所以应该把之前计算的差减掉
                res -= max;
                max = prices[p2] - prices[p1];
                // 然后加上最新技术出的差
                res += max;
                p2++;
            }
            // 下降区间
            else {
                p1 = p2;
                p2++;
                // 上升区间的差为0
                // 设置为0是为了保证，从下降区间进入上升区间后，上升区间首先要res -= max，这里设为0，防止不小心把上一个上升区间的max值减掉
                max = 0;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    Solution sol;
    cout << sol.maxProfit(nums) << endl;
}