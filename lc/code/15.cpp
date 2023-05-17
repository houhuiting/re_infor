#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.size() < 3)
            return res;
        // 先排序一波，具体理由见博客的思路部分
        sort(nums.begin(), nums.end());
        // 如果排序后的第一个元素还大于0的话，那必然不可能有相加等于0的三元组
        if (nums[0] > 0)
            return res;
        // 遍历i去寻找a
        for (int i = 0; i < nums.size(); i++) {
            // 当a大于0，由于数组的排序的，三元组第一个元素都大于0了，必然不存在后两个元素，使得和为0
            // 对a进行去重，保证（-1，0，1）和（-1，0，1）不会同时出现，具体理由见博客的思路部分
            if (i > 0 && nums[i] == nums[i-1] || nums[i] > 0)
                continue;
            int a = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            // 针对一个确定的a，去寻找b和c
            // left和right不能相等，因为题目说b和c不能说同一个位置的元素
            while (left < right) {
                int b = nums[left];
                int c = nums[right];
                // 说明数字大了，c要小一点
                if (a + b + c > 0) {
                    right--;
                }
                // 说明数字小了，b要大一点
                else if (a + b + c < 0){
                    left++;
                }
                // 找到了三元组相加为0的情况
                else {
                    vector<int> ele;
                    ele.push_back(a);
                    ele.push_back(b);
                    ele.push_back(c);
                    res.push_back(ele);
                    // 对于情况-1 0 0 0 0 0 1 1 1 1 1，将(-1,0,1)加入结果集合后
                    // 需要让left指向最后一个0，否则，下一个找出来的三元组还是(-1,0,1)
                    while (nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    vector<vector<int> > res = s.threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        vector<int> num = res[i];
        for (int j = 0; j < 3; j++) {
            cout << num[j] << " ";
        }
        cout << endl;
    }
    return 0;
}