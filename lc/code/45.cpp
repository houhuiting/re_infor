#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int cover = 0;
        int sum = 0;
        int next_cover = 0;
        // 只能在当前可到达区间内循环
        // 循环整个区间，看最多可以可以扩展到什么位置
        for (int i = 0; i <= cover; i++) {
            // 记录这个区间最多可以可以扩展到什么位置
            next_cover = max(next_cover, i + nums[i]);
            // 如果循环到了区间末尾，还没到达最后，就扩展区间
            if (i == cover && i < nums.size() - 1) {
                cover = next_cover;
                sum++;
            }
            // 看扩展后的区间能不能到达区间末尾
            if (cover >= nums.size() - 1)
                break;
        }
        return sum;
    }
};