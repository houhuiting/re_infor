#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        int count = 0;
        int res = INT32_MIN;
        while (p1 < nums.size() && p2 < nums.size()) {
            count += nums[p2];
            //cout <<nums[p1]<<" "<<nums[p2]<<" "<<count<<" "<<endl;
            // 如果count为负数，直接放弃以p1为开始的区间，从下一个位置开始
            if (count > res)
                res = count;
            if (count < 0) {
                // 从结束位置的下一个元素开始
                p1 = p2 + 1;
                p2 = p1;
                count = 0;
                continue;
            }
            p2++;
        }
        return res;
    }
};


int main()
{
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-7);
    nums.push_back(4);
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;
}