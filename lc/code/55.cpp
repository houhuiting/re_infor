#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        // 表示当前可扩展到的最远区间
        int cover = 0;
        // 只能在当前可到达区间内循环
        // 循环每一个元素，看每一个元素最多可以扩展到什么位置
        for (int i = 0; i <= cover; i++) {
            // 从当前元素开始，计算当前元素最远可以到达的位置
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
                return true;
        }
        return false;
    }
};