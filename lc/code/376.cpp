#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        if (nums.size() == 2 && nums[0] != nums[1])
            return nums.size();
        if (nums.size() == 2 && nums[0] == nums[1])
            return 1;
        if (nums.size() == 3 && nums[0] == nums[1] && nums[1] == nums[2])
            return 1;
        int p1 = 0;
        int p2 = 1;
        int p3 = 2;
        int res = 0;
        while (p3 < nums.size()) {
            if (nums[p2] > nums[p1] && nums[p2] > nums[p3])
                res++;
            if (nums[p2] < nums[p1] && nums[p2] < nums[p3])
                res++;
            if (nums[p2] == nums[p3]) {
                p2++;
                p3++;
                continue;
            }
            p1 = p2;
            p2++;
            p3++;
        }
        return res + 2;
    }
};