#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        map[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            int add = target - nums[i];
            // 看target - nums[i]是否在map中，如果在就可以输出结果
            if (map.count(add)) {
                res.push_back(map[add]);
                res.push_back(nums[i]);
                break;
            }
            // 看target - nums[i]是否在map中，如果不在，就把nums[i]放到map中
            else {
                map[nums[i]] = i;
            }
        }
        return res;
    }
};